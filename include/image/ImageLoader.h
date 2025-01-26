#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QImage>

class ImageLoader : public QObject
{
    Q_OBJECT

public:
    explicit ImageLoader(QObject *parent = nullptr);

    void setFilePath(const QString &filePath); // Définir le chemin du fichier compressé
    void startLoading();                       // Commencer le chargement asynchrone

signals:
    void imageLoaded(const QImage &image, int index); // Émis après le chargement de chaque image
    void loadingFinished();                           // Émis lorsque toutes les images sont chargées
    void loadingFailed(const QString &error);         // Émis en cas d'échec du chargement

private:
    QString m_filePath;                // Chemin du fichier compressé
    void extractAndLoadImages();       // Extraction et chargement asynchrone des images
};

#endif
