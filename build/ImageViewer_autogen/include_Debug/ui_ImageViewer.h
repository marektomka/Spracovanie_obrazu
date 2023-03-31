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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
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
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_Explicit;
    QFormLayout *formLayout;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBoxTau;
    QLabel *label_2;
    QSpinBox *spinBoxStepsExplicit;
    QPushButton *pushButtonExplicit;
    QGroupBox *groupBox_Implicit;
    QFormLayout *formLayout_2;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBoxTauImplicit;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBoxOmega;
    QPushButton *pushButtonImplicit;
    QLabel *label_5;
    QSpinBox *spinBoxStepsImplicit;
    QSpacerItem *verticalSpacer_3;
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
        ImageViewerClass->resize(824, 643);
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
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 10, 138, 380));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        groupBox_Explicit = new QGroupBox(groupBox);
        groupBox_Explicit->setObjectName("groupBox_Explicit");
        formLayout = new QFormLayout(groupBox_Explicit);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName("formLayout");
        label = new QLabel(groupBox_Explicit);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        doubleSpinBoxTau = new QDoubleSpinBox(groupBox_Explicit);
        doubleSpinBoxTau->setObjectName("doubleSpinBoxTau");
        doubleSpinBoxTau->setAlignment(Qt::AlignCenter);
        doubleSpinBoxTau->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        doubleSpinBoxTau->setMinimum(0.010000000000000);
        doubleSpinBoxTau->setMaximum(0.250000000000000);
        doubleSpinBoxTau->setSingleStep(0.010000000000000);

        formLayout->setWidget(0, QFormLayout::FieldRole, doubleSpinBoxTau);

        label_2 = new QLabel(groupBox_Explicit);
        label_2->setObjectName("label_2");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_2);

        spinBoxStepsExplicit = new QSpinBox(groupBox_Explicit);
        spinBoxStepsExplicit->setObjectName("spinBoxStepsExplicit");
        spinBoxStepsExplicit->setAlignment(Qt::AlignCenter);
        spinBoxStepsExplicit->setMinimum(1);
        spinBoxStepsExplicit->setMaximum(100);

        formLayout->setWidget(3, QFormLayout::FieldRole, spinBoxStepsExplicit);

        pushButtonExplicit = new QPushButton(groupBox_Explicit);
        pushButtonExplicit->setObjectName("pushButtonExplicit");

        formLayout->setWidget(5, QFormLayout::SpanningRole, pushButtonExplicit);


        verticalLayout->addWidget(groupBox_Explicit);

        groupBox_Implicit = new QGroupBox(groupBox);
        groupBox_Implicit->setObjectName("groupBox_Implicit");
        formLayout_2 = new QFormLayout(groupBox_Implicit);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName("formLayout_2");
        label_4 = new QLabel(groupBox_Implicit);
        label_4->setObjectName("label_4");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_4);

        doubleSpinBoxTauImplicit = new QDoubleSpinBox(groupBox_Implicit);
        doubleSpinBoxTauImplicit->setObjectName("doubleSpinBoxTauImplicit");
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(doubleSpinBoxTauImplicit->sizePolicy().hasHeightForWidth());
        doubleSpinBoxTauImplicit->setSizePolicy(sizePolicy1);
        doubleSpinBoxTauImplicit->setMinimum(0.010000000000000);
        doubleSpinBoxTauImplicit->setSingleStep(0.010000000000000);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, doubleSpinBoxTauImplicit);

        label_3 = new QLabel(groupBox_Implicit);
        label_3->setObjectName("label_3");
        label_3->setEnabled(true);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_3);

        doubleSpinBoxOmega = new QDoubleSpinBox(groupBox_Implicit);
        doubleSpinBoxOmega->setObjectName("doubleSpinBoxOmega");
        doubleSpinBoxOmega->setMinimum(0.010000000000000);
        doubleSpinBoxOmega->setSingleStep(0.010000000000000);
        doubleSpinBoxOmega->setValue(1.250000000000000);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, doubleSpinBoxOmega);

        pushButtonImplicit = new QPushButton(groupBox_Implicit);
        pushButtonImplicit->setObjectName("pushButtonImplicit");

        formLayout_2->setWidget(3, QFormLayout::SpanningRole, pushButtonImplicit);

        label_5 = new QLabel(groupBox_Implicit);
        label_5->setObjectName("label_5");

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_5);

        spinBoxStepsImplicit = new QSpinBox(groupBox_Implicit);
        spinBoxStepsImplicit->setObjectName("spinBoxStepsImplicit");
        spinBoxStepsImplicit->setAlignment(Qt::AlignCenter);
        spinBoxStepsImplicit->setMinimum(1);
        spinBoxStepsImplicit->setMaximum(100);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, spinBoxStepsImplicit);


        verticalLayout->addWidget(groupBox_Implicit);

        verticalSpacer_3 = new QSpacerItem(93, 62, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(186, 9, 621, 571));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 619, 569));
        scrollArea->setWidget(scrollAreaWidgetContents);
        ImageViewerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ImageViewerClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 824, 22));
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
        label_4->setText(QCoreApplication::translate("ImageViewerClass", "Tau:", nullptr));
        label_3->setText(QCoreApplication::translate("ImageViewerClass", "Omega:", nullptr));
        pushButtonImplicit->setText(QCoreApplication::translate("ImageViewerClass", "Implicit", nullptr));
        label_5->setText(QCoreApplication::translate("ImageViewerClass", "Steps:", nullptr));
        menuFile->setTitle(QCoreApplication::translate("ImageViewerClass", "File", nullptr));
        menuImage->setTitle(QCoreApplication::translate("ImageViewerClass", "Image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageViewerClass: public Ui_ImageViewerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEVIEWER_H
