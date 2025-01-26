/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *titleLabel;
    QLabel *imageLabel;
    QLabel *pageLabel;
    QPushButton *openButton;
    QPushButton *createButton;
    QPushButton *prevButton;
    QPushButton *nextButton;
    QPushButton *zoomInButton;
    QPushButton *zoomOutButton;
    QPushButton *goToPageButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 800);

        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QVBoxLayout *mainLayout = new QVBoxLayout(centralwidget);
        centralwidget->setLayout(mainLayout);

        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setAlignment(Qt::AlignCenter);
        titleLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        mainLayout->addWidget(titleLabel);

        QHBoxLayout *imageLayout = new QHBoxLayout();
        imageLabel = new QLabel(centralwidget);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        imageLabel->setAlignment(Qt::AlignCenter);
        imageLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        imageLayout->addWidget(imageLabel);

        mainLayout->addLayout(imageLayout);

        QHBoxLayout *buttonLayout = new QHBoxLayout();
        openButton = new QPushButton(centralwidget);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        buttonLayout->addWidget(openButton);

        createButton = new QPushButton(centralwidget);
        createButton->setObjectName(QString::fromUtf8("createButton"));
        buttonLayout->addWidget(createButton);

        prevButton = new QPushButton(centralwidget);
        prevButton->setObjectName(QString::fromUtf8("prevButton"));
        buttonLayout->addWidget(prevButton);

        nextButton = new QPushButton(centralwidget);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        buttonLayout->addWidget(nextButton);

        zoomInButton = new QPushButton(centralwidget);
        zoomInButton->setObjectName(QString::fromUtf8("zoomInButton"));
        buttonLayout->addWidget(zoomInButton);

        zoomOutButton = new QPushButton(centralwidget);
        zoomOutButton->setObjectName(QString::fromUtf8("zoomOutButton"));
        buttonLayout->addWidget(zoomOutButton);

        goToPageButton = new QPushButton(centralwidget);
        goToPageButton->setObjectName(QString::fromUtf8("goToPageButton"));
        buttonLayout->addWidget(goToPageButton);

        mainLayout->addLayout(buttonLayout);

        pageLabel = new QLabel(centralwidget);
        pageLabel->setObjectName(QString::fromUtf8("pageLabel"));
        pageLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        pageLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        mainLayout->addWidget(pageLabel);

        MainWindow->setCentralWidget(centralwidget);

        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    }

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Comic Book Reader", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", "Comic Title", nullptr));
        imageLabel->setText(QString());
        pageLabel->setText(QCoreApplication::translate("MainWindow", "Page: 1", nullptr));
        openButton->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        createButton->setText(QCoreApplication::translate("MainWindow", "Create", nullptr));
        prevButton->setText(QCoreApplication::translate("MainWindow", "Previous", nullptr));
        nextButton->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        zoomInButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        zoomOutButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        goToPageButton->setText(QCoreApplication::translate("MainWindow", "To Page", nullptr));
    }
};

namespace Ui
{
    class MainWindow : public Ui_MainWindow
    {
    };
}

QT_END_NAMESPACE

#endif
