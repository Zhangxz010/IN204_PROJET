/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *mainGridLayout;
    QLabel *titleLabel;
    QLabel *imageLabel;
    QHBoxLayout *buttonHorizontalLayout;
    QPushButton *openButton;
    QPushButton *prevButton;
    QPushButton *nextButton;
    QPushButton *zoomInButton;
    QPushButton *zoomOutButton;
    QPushButton *goToPageButton;
    QLabel *pageLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        mainGridLayout = new QGridLayout(centralwidget);
        mainGridLayout->setObjectName(QString::fromUtf8("mainGridLayout"));
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setLineWidth(5);
        titleLabel->setMidLineWidth(0);
        titleLabel->setTextFormat(Qt::PlainText);
        titleLabel->setAlignment(Qt::AlignCenter);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(titleLabel->sizePolicy().hasHeightForWidth());
        titleLabel->setProperty("SizePolicy", QVariant(sizePolicy));

        mainGridLayout->addWidget(titleLabel, 0, 0, 1, 2);

        imageLabel = new QLabel(centralwidget);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        imageLabel->setAlignment(Qt::AlignCenter);
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(imageLabel->sizePolicy().hasHeightForWidth());
        imageLabel->setSizePolicy(sizePolicy1);

        mainGridLayout->addWidget(imageLabel, 1, 0, 1, 2);

        buttonHorizontalLayout = new QHBoxLayout();
        buttonHorizontalLayout->setObjectName(QString::fromUtf8("buttonHorizontalLayout"));
        openButton = new QPushButton(centralwidget);
        openButton->setObjectName(QString::fromUtf8("openButton"));

        buttonHorizontalLayout->addWidget(openButton);

        prevButton = new QPushButton(centralwidget);
        prevButton->setObjectName(QString::fromUtf8("prevButton"));

        buttonHorizontalLayout->addWidget(prevButton);

        nextButton = new QPushButton(centralwidget);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));

        buttonHorizontalLayout->addWidget(nextButton);

        zoomInButton = new QPushButton(centralwidget);
        zoomInButton->setObjectName(QString::fromUtf8("zoomInButton"));

        buttonHorizontalLayout->addWidget(zoomInButton);

        zoomOutButton = new QPushButton(centralwidget);
        zoomOutButton->setObjectName(QString::fromUtf8("zoomOutButton"));

        buttonHorizontalLayout->addWidget(zoomOutButton);

        goToPageButton = new QPushButton(centralwidget);
        goToPageButton->setObjectName(QString::fromUtf8("goToPageButton"));

        buttonHorizontalLayout->addWidget(goToPageButton);


        mainGridLayout->addLayout(buttonHorizontalLayout, 3, 0, 1, 2);

        pageLabel = new QLabel(centralwidget);
        pageLabel->setObjectName(QString::fromUtf8("pageLabel"));
        pageLabel->setAlignment(Qt::AlignRight);
        sizePolicy.setHeightForWidth(pageLabel->sizePolicy().hasHeightForWidth());
        pageLabel->setProperty("SizePolicy", QVariant(sizePolicy));

        mainGridLayout->addWidget(pageLabel, 4, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Comic Book Reader", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", "Comic Title", nullptr));
        imageLabel->setText(QCoreApplication::translate("MainWindow", "Image Preview", nullptr));
        openButton->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        prevButton->setText(QCoreApplication::translate("MainWindow", "Previous", nullptr));
        nextButton->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        zoomInButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        zoomOutButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        goToPageButton->setText(QCoreApplication::translate("MainWindow", "To Page", nullptr));
        pageLabel->setText(QCoreApplication::translate("MainWindow", "Page: 1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
