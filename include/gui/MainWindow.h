#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QImage>
#include "image/ImageLoader.h"
namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openCBZ();
    void createCBZ();
    void showNextImage();
    void showPreviousImage();
    void onImageLoaded(const QImage &image, int index);
    void onLoadingFinished();
    void zoomIn();
    void zoomOut();
    void goToPage();
    void onLoadingFailed(const QString &error);

private:
    void loadDefaultImage();
    void loadSinglePageMode();
    void loadDoublePageMode();
    void updateDoublePageDisplay();

    double scaleFactor = 1.0;

    Ui::MainWindow *ui;

    QList<QImage> imageList;
    int currentImageIndex;
    ImageLoader *imageLoader;
};

#endif
