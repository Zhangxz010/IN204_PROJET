#include "file_handlers/CBZReader.h"
#include <quazip5/quazip.h>
#include <quazip5/quazipfile.h>
#include <QFile>
#include <QDir>
#include <QDebug>

CBZReader::CBZReader(const QString &filePath) : Reader(filePath) {}

QStringList CBZReader::extractImages()
{
    QStringList imagePaths;
    QString outputDir = QDir::tempPath() + "/cbz_temp";

    QDir dir(outputDir);
    if (!dir.exists())
    {
        dir.mkpath(".");
    }

    QuaZip zip(m_filePath);
    if (!zip.open(QuaZip::mdUnzip))
    {
        qDebug() << "Failed to open CBZ file:" << m_filePath;
        return imagePaths;
    }

    for (bool more = zip.goToFirstFile(); more; more = zip.goToNextFile())
    {
        QuaZipFile file(&zip);
        if (!file.open(QIODevice::ReadOnly))
        {
            qDebug() << "Failed to open file inside CBZ:" << file.getActualFileName();
            continue;
        }

        QString outFilePath = dir.filePath(file.getActualFileName());
        QFile outFile(outFilePath);
        if (!outFile.open(QIODevice::WriteOnly))
        {
            qDebug() << "Failed to open output file for writing:" << outFilePath;
            continue;
        }

        outFile.write(file.readAll());
        outFile.close();
        imagePaths.append(outFilePath);
    }

    zip.close();
    return imagePaths;
}
