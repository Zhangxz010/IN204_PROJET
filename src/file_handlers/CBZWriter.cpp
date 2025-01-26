#include "file_handlers/CBZWriter.h"
#include <quazip5/quazip.h>
#include <quazip5/quazipfile.h>
#include <QFile>
#include <QFileInfo>
#include <QDebug>

CBZWriter::CBZWriter(const QString& outputFile) : Writer(outputFile) {}

bool CBZWriter::createFromImages(const QStringList& images) {
    if (images.isEmpty()) {
        qDebug() << "No images provided for CBZ creation.";
        return false;
    }

    QuaZip zip(m_outputFile);
    if (!zip.open(QuaZip::mdCreate)) {
        qDebug() << "Failed to create CBZ file:" << m_outputFile;
        return false;
    }

    for (const QString& imagePath : images) {
        QFile file(imagePath);
        if (!file.open(QIODevice::ReadOnly)) {
            qDebug() << "Failed to open image file for reading:" << imagePath;
            zip.close();
            return false;
        }

        QuaZipFile zipFile(&zip);
        QString zipFileName = QFileInfo(imagePath).fileName();
        if (!zipFile.open(QIODevice::WriteOnly, zipFileName)) {
            qDebug() << "Failed to add file to CBZ:" << zipFileName;
            file.close();
            zip.close();
            return false;
        }

        zipFile.write(file.readAll());
        zipFile.close();
        file.close();
    }

    zip.close();
    if (zip.getZipError() != UNZ_OK) {
        qDebug() << "Error finalizing CBZ file:" << m_outputFile;
        return false;
    }

    qDebug() << "CBZ file created successfully:" << m_outputFile;
    return true;
}
