#include "file_handlers/CBRReader.h"
#include <QDir>
#include <QProcess>
#include <QDebug>
#include <QFileInfo>

CBRReader::CBRReader(const QString &filePath) : Reader(filePath) {}

QStringList CBRReader::extractImages()
{
    QString outputDir = prepareOutputDirectory();
    if (outputDir.isEmpty())
    {
        qDebug() << "Failed to prepare output directory.";
        return {};
    }

    if (!executeUnrar(outputDir))
    {
        qDebug() << "Failed to extract CBR file using unrar.";
        return {};
    }

    QStringList imagePaths;
    QDir dir(outputDir);
    QFileInfoList files = dir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot);
    for (const QFileInfo &file : files)
    {
        imagePaths.append(file.absoluteFilePath());
    }

    return imagePaths;
}

QString CBRReader::prepareOutputDirectory()
{
    QString outputDir = QDir::tempPath() + "/cbr_temp";
    QDir dir(outputDir);
    if (dir.exists())
    {
        dir.removeRecursively();
    }
    if (!dir.mkpath("."))
    {
        qDebug() << "Failed to create output directory:" << outputDir;
        return {};
    }
    return outputDir;
}

bool CBRReader::executeUnrar(const QString &outputDir)
{
    QProcess process;
    QStringList args;
    args << "x" << "-o+" << m_filePath << outputDir + "/";
    process.start("unrar", args);

    if (!process.waitForFinished())
    {
        qDebug() << "Unrar process did not finish:" << process.errorString();
        return false;
    }

    if (process.exitCode() != 0)
    {
        qDebug() << "Unrar failed:" << process.readAllStandardError();
        return false;
    }

    return true;
}
