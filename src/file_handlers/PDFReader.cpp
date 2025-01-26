#include "file_handlers/PDFReader.h"
#include <poppler-qt5.h>
#include <QDir>
#include <QDebug>
#include <QImage>


PDFReader::PDFReader(const QString& filePath) : Reader(filePath) {}

QStringList PDFReader::extractImages() {
    QStringList imagePaths;
    QString outputDir = prepareOutputDirectory();

    if (outputDir.isEmpty()) {
        qDebug() << "Failed to prepare output directory.";
        return imagePaths;
    }

    Poppler::Document* document = Poppler::Document::load(m_filePath);
    if (!document) {
        qDebug() << "Failed to open PDF file:" << m_filePath;
        return imagePaths;
    }

    for (int i = 0; i < document->numPages(); ++i) {
        QString imagePath = QString("%1/page_%2.png").arg(outputDir).arg(i + 1);
        Poppler::Page* page = document->page(i);
        if (page) {
            QImage image = page->renderToImage(300, 300);
            if (!image.isNull() && image.save(imagePath)) {
                imagePaths.append(imagePath);
            } else {
                qDebug() << "Failed to render/save page" << i + 1;
            }
            delete page;
        }
    }

    delete document;
    return imagePaths;
}

QString PDFReader::prepareOutputDirectory() {
    QString outputDir = QDir::tempPath() + "/pdf_temp";
    QDir dir(outputDir);
    if (dir.exists()) {
        dir.removeRecursively();
    }
    if (!dir.mkpath(".")) {
        qDebug() << "Failed to create output directory:" << outputDir;
        return {};
    }
    return outputDir;
}
