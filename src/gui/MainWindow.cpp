#include "gui/MainWindow.h"
#include "gui/ui_MainWindow.h"
#include "file_handlers/CBZWriter.h"
#include "file_handlers/CBZReader.h"
#include "file_handlers/CBRReader.h"
#include "file_handlers/CBRWriter.h"
#include "image/ImageLoader.h"

#include <QPixmap>
#include <QDir>
#include <QFileInfo>
#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>
#include <QtConcurrent>
#include <QDebug>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), currentImageIndex(-1), imageLoader(new ImageLoader(this))
{
    ui->setupUi(this);

    connect(ui->zoomInButton, &QPushButton::clicked, this, &MainWindow::zoomIn);
    connect(ui->zoomOutButton, &QPushButton::clicked, this, &MainWindow::zoomOut);
    connect(ui->goToPageButton, &QPushButton::clicked, this, &MainWindow::goToPage);
    connect(ui->createButton, &QPushButton::clicked, this, &MainWindow::createCBZ);
    connect(ui->openButton, &QPushButton::clicked, this, &MainWindow::openCBZ);
    connect(ui->prevButton, &QPushButton::clicked, this, &MainWindow::showPreviousImage);
    connect(ui->nextButton, &QPushButton::clicked, this, &MainWindow::showNextImage);
    connect(imageLoader, &ImageLoader::imageLoaded, this, &MainWindow::onImageLoaded);
    connect(imageLoader, &ImageLoader::loadingFinished, this, &MainWindow::onLoadingFinished);
    connect(imageLoader, &ImageLoader::loadingFailed, this, &MainWindow::onLoadingFailed);
    loadDefaultImage();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadDefaultImage()
{
    QPixmap pixmap(":/images/default.jpg");
    if (!pixmap.isNull())
    {
        ui->imageLabel->setPixmap(pixmap.scaled(ui->imageLabel->size(), Qt::KeepAspectRatio));
    }
}

void MainWindow::openCBZ()
{
    QString filePath = QFileDialog::getOpenFileName(
        this, "Open CBR/CBZ/PDF File", "", "Comic Files (*.cbz *.cbr *.pdf)");

    if (filePath.isEmpty())
        return;

    QString comicTitle = QFileInfo(filePath).baseName();
    ui->titleLabel->setText(comicTitle);

    imageList.clear();
    currentImageIndex = -1;

    QStringList options = {"Single Page", "Double Page"};
    bool ok;
    QString choice = QInputDialog::getItem(this, "Select Mode", "Choose display mode:", options, 0, false, &ok);
    if (!ok)
        return;

    if (choice == "Single Page")
    {
        ui->pageLabel->setText("Page");
    }
    else if (choice == "Double Page")
    {
        ui->pageLabel->setText("Pages");
    }

    imageLoader->setFilePath(filePath);
    imageLoader->startLoading();

    QMessageBox::information(this, "Loading", "Images are being loaded. They will appear as they are processed.");
}

void MainWindow::onImageLoaded(const QImage &image, int index)
{
    imageList.append(image);
    qDebug() << "Image loaded at index:" << index;
    qDebug() << "Current mode:" << (ui->pageLabel->text().contains("Pages") ? "Double Page" : "Single Page");

    if (ui->pageLabel->text().contains("Pages"))
    {
        if (imageList.size() >= 2 && currentImageIndex == -1)
        {
            currentImageIndex = 0;
            updateDoublePageDisplay();
        }
    }
    else
    {
        if (currentImageIndex == -1)
        {
            currentImageIndex = 0;
            ui->imageLabel->setPixmap(QPixmap::fromImage(image).scaled(
                ui->imageLabel->size(), Qt::KeepAspectRatio));
            ui->pageLabel->setText(QString("Page: %1").arg(currentImageIndex + 1));
        }
    }
}

void MainWindow::onLoadingFinished()
{
    if (imageList.isEmpty())
    {
        QMessageBox::warning(this, "No Pages", "The comic book contains no valid pages.");
        return;
    }

    if (ui->pageLabel->text().contains("Pages"))
    {
        if (imageList.size() >= 2)
        {
            currentImageIndex = 0;
            updateDoublePageDisplay();
        }
        else
        {
            QMessageBox::warning(this, "Double Page Mode", "Not enough pages for double page mode.");
        }
    }
    else
    {
        currentImageIndex = 0;
        ui->imageLabel->setPixmap(QPixmap::fromImage(imageList[currentImageIndex]).scaled(ui->imageLabel->size(), Qt::KeepAspectRatio));
        ui->pageLabel->setText(QString("Page: %1").arg(currentImageIndex + 1));
    }

    ui->statusbar->showMessage("All images loaded successfully!");
}

void MainWindow::onLoadingFailed(const QString &error)
{
    QMessageBox::warning(this, "Error", error);
}

void MainWindow::showNextImage()
{
    if (imageList.isEmpty())
        return;

    if (ui->pageLabel->text().contains("Pages"))
    {
        if (currentImageIndex + 2 < imageList.size())
        {
            currentImageIndex += 2;
            updateDoublePageDisplay();
        }
    }
    else
    {
        if (currentImageIndex + 1 < imageList.size())
        {
            currentImageIndex++;
            ui->imageLabel->setPixmap(QPixmap::fromImage(imageList[currentImageIndex]).scaled(ui->imageLabel->size(), Qt::KeepAspectRatio));
            ui->pageLabel->setText(QString("Page: %1").arg(currentImageIndex + 1));
        }
    }
}

void MainWindow::showPreviousImage()
{
    if (imageList.isEmpty())
        return;

    if (ui->pageLabel->text().contains("Pages"))
    {
        if (currentImageIndex - 2 >= 0)
        {
            currentImageIndex -= 2;
            updateDoublePageDisplay();
        }
    }
    else
    {
        if (currentImageIndex - 1 >= 0)
        {
            currentImageIndex--;
            ui->imageLabel->setPixmap(QPixmap::fromImage(imageList[currentImageIndex]).scaled(ui->imageLabel->size(), Qt::KeepAspectRatio));
            ui->pageLabel->setText(QString("Page: %1").arg(currentImageIndex + 1));
        }
    }
}

void MainWindow::zoomIn()
{
    scaleFactor *= 1.2;

    if (currentImageIndex >= 0)
    {
        if (ui->pageLabel->text().contains("Pages"))
        {
            if (currentImageIndex + 1 < imageList.size())
            {
                QPixmap leftPage = QPixmap::fromImage(imageList[currentImageIndex]);
                QPixmap rightPage = QPixmap::fromImage(imageList[currentImageIndex + 1]);

                QSize combinedSize = QSize(
                                         leftPage.width() + rightPage.width(),
                                         qMax(leftPage.height(), rightPage.height())) *
                                     scaleFactor;
                QSize windowSize = ui->centralwidget->size();

                if (combinedSize.width() > windowSize.width() || combinedSize.height() > windowSize.height())
                {
                    QMessageBox::warning(this, "Zoom In", "Cannot zoom in further, images exceed window size.");
                    scaleFactor /= 1.2;
                    return;
                }

                updateDoublePageDisplay();
            }
        }
        else
        {
            QSize scaledSize = imageList[currentImageIndex].size() * scaleFactor;
            QSize windowSize = ui->centralwidget->size();

            if (scaledSize.width() > windowSize.width() || scaledSize.height() > windowSize.height())
            {
                QMessageBox::warning(this, "Zoom In", "Cannot zoom in further, image exceeds window size.");
                scaleFactor /= 1.2;
                return;
            }

            ui->imageLabel->setPixmap(QPixmap::fromImage(imageList[currentImageIndex]).scaled(scaledSize, Qt::KeepAspectRatio));
        }
    }
}

void MainWindow::zoomOut()
{
    scaleFactor /= 1.2;
    if (currentImageIndex >= 0)
    {
        ui->imageLabel->setPixmap(QPixmap::fromImage(imageList[currentImageIndex]).scaled(ui->imageLabel->size() * scaleFactor, Qt::KeepAspectRatio));
    }
}

void MainWindow::updateDoublePageDisplay()
{
    if (currentImageIndex < 0 || currentImageIndex >= imageList.size())
        return;

    QPixmap leftPage = QPixmap::fromImage(imageList[currentImageIndex]);
    QPixmap rightPage;

    if (currentImageIndex + 1 < imageList.size()) // 检查右页是否存在
    {
        rightPage = QPixmap::fromImage(imageList[currentImageIndex + 1]);
    }

    int combinedWidth = leftPage.width() * scaleFactor +
                        (rightPage.isNull() ? 0 : rightPage.width() * scaleFactor);
    int maxHeight = qMax(leftPage.height(), rightPage.height()) * scaleFactor;

    QPixmap combinedPixmap(combinedWidth, maxHeight);
    combinedPixmap.fill(Qt::white);

    QPainter painter(&combinedPixmap);
    painter.drawPixmap(0, 0, leftPage.scaled(leftPage.size() * scaleFactor, Qt::KeepAspectRatio));

    if (!rightPage.isNull())
    {
        painter.drawPixmap(leftPage.width() * scaleFactor, 0,
                           rightPage.scaled(rightPage.size() * scaleFactor, Qt::KeepAspectRatio));
    }

    ui->imageLabel->setPixmap(combinedPixmap.scaled(ui->imageLabel->size(), Qt::KeepAspectRatio));
    ui->pageLabel->setText(QString("Pages: %1-%2").arg(currentImageIndex + 1).arg(currentImageIndex + 2 <= imageList.size() ? currentImageIndex + 2 : currentImageIndex + 1));
}

void MainWindow::goToPage()
{
    bool ok;

    int maxPage = ui->pageLabel->text().contains("Pages") ? (imageList.size() + 1) / 2 : imageList.size();
    int page = QInputDialog::getInt(
        this,
        "Go to Page",
        QString("Page Number (1-%1):").arg(maxPage),
        1,
        1,
        maxPage,
        1,
        &ok);

    if (ok)
    {
        if (ui->pageLabel->text().contains("Pages"))
        {
            currentImageIndex = (page - 1) * 2;

            if (currentImageIndex >= imageList.size())
            {
                QMessageBox::warning(this, "Invalid Page", "Page number exceeds the total pages.");
                return;
            }

            updateDoublePageDisplay();
        }
        else
        {
            currentImageIndex = page - 1;

            if (currentImageIndex >= imageList.size())
            {
                QMessageBox::warning(this, "Invalid Page", "Page number exceeds the total pages.");
                return;
            }

            ui->imageLabel->setPixmap(QPixmap::fromImage(imageList[currentImageIndex]).scaled(ui->imageLabel->size(), Qt::KeepAspectRatio));
            ui->pageLabel->setText(QString("Page: %1").arg(currentImageIndex + 1));
        }
    }
}

void MainWindow::createCBZ()
{
    QStringList images = QFileDialog::getOpenFileNames(
        this,
        "Select Images",
        QDir::currentPath(),
        "Images (*.jpg *.jpeg *.png *.bmp *.gif);;All Files (*)");

    if (images.isEmpty())
    {
        QMessageBox::warning(this, "No Images Selected", "Please select one or more images.");
        return;
    }

    QString outputFilePath = QFileDialog::getSaveFileName(
        this,
        "Save File",
        QDir::currentPath(),
        "Comic Files (*.cbz *.cbr)");

    if (outputFilePath.isEmpty())
        return;

    if (outputFilePath.endsWith(".cbz", Qt::CaseInsensitive))
    {
        CBZWriter writer(outputFilePath);
        if (writer.createFromImages(images))
        {
            QMessageBox::information(this, "Success", "CBZ file created successfully!");
        }
        else
        {
            QMessageBox::warning(this, "Error", "Failed to create CBZ file.");
        }
    }
    else if (outputFilePath.endsWith(".cbr", Qt::CaseInsensitive))
    {
        CBRWriter writer(outputFilePath);
        if (writer.createFromImages(images))
        {
            QMessageBox::information(this, "Success", "CBR file created successfully!");
        }
        else
        {
            QMessageBox::warning(this, "Error", "Failed to create CBR file.");
        }
    }
    else
    {
        QMessageBox::warning(this, "Unsupported Format", "Please save as a .cbz or .cbr file.");
    }
}
