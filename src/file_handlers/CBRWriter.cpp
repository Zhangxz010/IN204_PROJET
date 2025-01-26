#include "file_handlers/CBRWriter.h"
#include <QProcess>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QDebug>

CBRWriter::CBRWriter(const QString &outputFile) : Writer(outputFile) {}

bool CBRWriter::createFromImages(const QStringList &images)
{
    if (images.isEmpty())
    {
        qDebug() << "No images provided for CBR creation.";
        return false;
    }

    QString tempDirPath = QDir::tempPath() + "/cbr_temp";
    QDir tempDir(tempDirPath);
    if (tempDir.exists())
    {
        tempDir.removeRecursively();
    }
    tempDir.mkpath(".");

    for (const QString &imagePath : images)
    {
        QFileInfo fileInfo(imagePath);
        QString destPath = tempDir.filePath(fileInfo.fileName());
        if (!QFile::copy(imagePath, destPath))
        {
            qDebug() << "Failed to copy image to temp directory:" << imagePath;
            return false;
        }
    }

    QProcess process;
    QStringList args;
    args << "a"
         << "-ep1"
         << m_outputFile
         << tempDirPath + "/*";

    qDebug() << "Executing RAR command:" << "rar" << args;
    process.start("rar", args);
    if (!process.waitForFinished())
    {
        qDebug() << "Failed to execute rar:" << process.errorString();
        return false;
    }

    if (process.exitCode() != 0)
    {
        qDebug() << "Rar failed:" << process.readAllStandardError();
        return false;
    }

    qDebug() << "CBR file created successfully at:" << m_outputFile;
    return true;
}
