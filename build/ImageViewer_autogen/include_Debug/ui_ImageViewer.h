/********************************************************************************
** Form generated from reading UI file 'ImageViewer.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEVIEWER_H
#define UI_IMAGEVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageViewerClass
{
public:
    QAction *actionOpen;
    QAction *actionSave_as;
    QAction *actionClear;
    QAction *actionExit;
    QAction *actionResize;
    QAction *actionInvert;
    QAction *actionFSHS;
    QAction *actionEdgeMirror;
    QAction *actionEKVHist;
    QAction *actionConvolution;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_Explicit;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBoxTau;
    QLabel *label_2;
    QSpinBox *spinBoxSteps;
    QPushButton *pushButtonExplicit;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_Implicit;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuImage;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ImageViewerClass)
    {
        if (ImageViewerClass->objectName().isEmpty())
            ImageViewerClass->setObjectName("ImageViewerClass");
        ImageViewerClass->resize(818, 646);
        actionOpen = new QAction(ImageViewerClass);
        actionOpen->setObjectName("actionOpen");
        actionSave_as = new QAction(ImageViewerClass);
        actionSave_as->setObjectName("actionSave_as");
        actionClear = new QAction(ImageViewerClass);
        actionClear->setObjectName("actionClear");
        actionExit = new QAction(ImageViewerClass);
        actionExit->setObjectName("actionExit");
        actionResize = new QAction(ImageViewerClass);
        actionResize->setObjectName("actionResize");
        actionInvert = new QAction(ImageViewerClass);
        actionInvert->setObjectName("actionInvert");
        actionFSHS = new QAction(ImageViewerClass);
        actionFSHS->setObjectName("actionFSHS");
        actionEdgeMirror = new QAction(ImageViewerClass);
        actionEdgeMirror->setObjectName("actionEdgeMirror");
        actionEKVHist = new QAction(ImageViewerClass);
        actionEKVHist->setObjectName("actionEKVHist");
        actionConvolution = new QAction(ImageViewerClass);
        actionConvolution->setObjectName("actionConvolution");
        centralWidget = new QWidget(ImageViewerClass);
        centralWidget->setObjectName("centralWidget");
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        groupBox_Explicit = new QGroupBox(groupBox);
        groupBox_Explicit->setObjectName("groupBox_Explicit");
        verticalLayout = new QVBoxLayout(groupBox_Explicit);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(groupBox_Explicit);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        doubleSpinBoxTau = new QDoubleSpinBox(groupBox_Explicit);
        doubleSpinBoxTau->setObjectName("doubleSpinBoxTau");
        doubleSpinBoxTau->setAlignment(Qt::AlignCenter);
        doubleSpinBoxTau->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        doubleSpinBoxTau->setMinimum(0.010000000000000);
        doubleSpinBoxTau->setMaximum(0.250000000000000);
        doubleSpinBoxTau->setSingleStep(0.010000000000000);

        verticalLayout->addWidget(doubleSpinBoxTau);

        label_2 = new QLabel(groupBox_Explicit);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        spinBoxSteps = new QSpinBox(groupBox_Explicit);
        spinBoxSteps->setObjectName("spinBoxSteps");
        spinBoxSteps->setAlignment(Qt::AlignCenter);
        spinBoxSteps->setMinimum(1);
        spinBoxSteps->setMaximum(100);

        verticalLayout->addWidget(spinBoxSteps);

        pushButtonExplicit = new QPushButton(groupBox_Explicit);
        pushButtonExplicit->setObjectName("pushButtonExplicit");

        verticalLayout->addWidget(pushButtonExplicit);

        verticalSpacer = new QSpacerItem(58, 348, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addWidget(groupBox_Explicit, 0, 1, 1, 1);

        groupBox_Implicit = new QGroupBox(groupBox);
        groupBox_Implicit->setObjectName("groupBox_Implicit");

        gridLayout->addWidget(groupBox_Implicit, 1, 1, 1, 1);


        horizontalLayout->addWidget(groupBox);

        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 671, 571));
        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);

        ImageViewerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ImageViewerClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 818, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName("menuFile");
        menuImage = new QMenu(menuBar);
        menuImage->setObjectName("menuImage");
        ImageViewerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ImageViewerClass);
        mainToolBar->setObjectName("mainToolBar");
        ImageViewerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ImageViewerClass);
        statusBar->setObjectName("statusBar");
        ImageViewerClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuImage->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave_as);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuImage->addAction(actionInvert);
        menuImage->addAction(actionFSHS);
        menuImage->addAction(actionEdgeMirror);
        menuImage->addAction(actionEKVHist);
        menuImage->addAction(actionConvolution);

        retranslateUi(ImageViewerClass);

        QMetaObject::connectSlotsByName(ImageViewerClass);
    } // setupUi

    void retranslateUi(QMainWindow *ImageViewerClass)
    {
        ImageViewerClass->setWindowTitle(QCoreApplication::translate("ImageViewerClass", "ImageViewer", nullptr));
        actionOpen->setText(QCoreApplication::translate("ImageViewerClass", "Open", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("ImageViewerClass", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_as->setText(QCoreApplication::translate("ImageViewerClass", "Save as", nullptr));
#if QT_CONFIG(shortcut)
        actionSave_as->setShortcut(QCoreApplication::translate("ImageViewerClass", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionClear->setText(QCoreApplication::translate("ImageViewerClass", "Clear", nullptr));
        actionExit->setText(QCoreApplication::translate("ImageViewerClass", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("ImageViewerClass", "Alt+F4", nullptr));
#endif // QT_CONFIG(shortcut)
        actionResize->setText(QCoreApplication::translate("ImageViewerClass", "Resize", nullptr));
        actionInvert->setText(QCoreApplication::translate("ImageViewerClass", "Invert", nullptr));
        actionFSHS->setText(QCoreApplication::translate("ImageViewerClass", "FSHS", nullptr));
        actionEdgeMirror->setText(QCoreApplication::translate("ImageViewerClass", "EdgeMirror", nullptr));
        actionEKVHist->setText(QCoreApplication::translate("ImageViewerClass", "EKVHist", nullptr));
        actionConvolution->setText(QCoreApplication::translate("ImageViewerClass", "Convolution", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ImageViewerClass", "Controls", nullptr));
        groupBox_Explicit->setTitle(QCoreApplication::translate("ImageViewerClass", "Explicit scheme", nullptr));
        label->setText(QCoreApplication::translate("ImageViewerClass", "Tau:", nullptr));
        label_2->setText(QCoreApplication::translate("ImageViewerClass", "Steps:", nullptr));
        pushButtonExplicit->setText(QCoreApplication::translate("ImageViewerClass", "Explicit", nullptr));
        groupBox_Implicit->setTitle(QCoreApplication::translate("ImageViewerClass", "Implicit scheme", nullptr));
        menuFile->setTitle(QCoreApplication::translate("ImageViewerClass", "File", nullptr));
        menuImage->setTitle(QCoreApplication::translate("ImageViewerClass", "Image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageViewerClass: public Ui_ImageViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEVIEWER_H
