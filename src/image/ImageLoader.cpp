#include "image/ImageLoader.h"
#include "file_handlers/CBZReader.h"
#include "file_handlers/CBRReader.h"
#include "file_handlers/PDFReader.h"
#include <QDir>
#include <QDebug>
#include <QtConcurrent/QtConcurrent>

ImageLoader::ImageLoader(QObject *parent) : QObject(parent) {}

void ImageLoader::setFilePath(const QString &filePath)
{
    m_filePath = filePath;
}

void ImageLoader::startLoading()
{

    QtConcurrent::run([this]()
                      { extractAndLoadImages(); });
}

void ImageLoader::extractAndLoadImages()
{
    if (m_filePath.isEmpty())
    {
        emit loadingFailed("File path is empty.");
        return;
    }

    QStringList imagePaths;

    if (m_filePath.endsWith(".cbz", Qt::CaseInsensitive))
    {
        CBZReader reader(m_filePath);
        imagePaths = reader.extractImages();
    }
    else if (m_filePath.endsWith(".cbr", Qt::CaseInsensitive))
    {
        CBRReader reader(m_filePath);
        imagePaths = reader.extractImages();
    }
    else if (m_filePath.endsWith(".pdf", Qt::CaseInsensitive))
    {
        PDFReader reader(m_filePath);
        imagePaths = reader.extractImages();
    }
    else
    {
        emit loadingFailed("Unsupported file format.");
        return;
    }

    if (imagePaths.isEmpty())
    {
        emit loadingFailed("No images extracted from the file.");
        return;
    }

    int index = 0;
    for (const QString &path : imagePaths)
    {
        QImage image(path);
        if (!image.isNull())
        {
            emit imageLoaded(image, index++);
        }
        else
        {
            qDebug() << "Failed to load image from path:" << path;
        }
    }

    emit loadingFinished();
}
