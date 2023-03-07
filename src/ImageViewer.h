#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets>
#include "ui_ImageViewer.h"
#include "ViewerWidget.h"
#include "IPmodul.h"


class ImageViewer : public QMainWindow
{
	Q_OBJECT

public:
	ImageViewer(QWidget* parent = Q_NULLPTR);

private:
	Ui::ImageViewerClass* ui;
	ViewerWidget* vW;

	QSettings settings;
	QMessageBox msgBox;

	// Variables // 
	int N = 2;
	bool opened = false;


	//ImageViewer Events
	void closeEvent(QCloseEvent* event);

	//Image functions
	bool openImage(QString filename);
	bool saveImage(QString filename);
	bool invertColors();

private slots:
	void on_actionOpen_triggered();
	void on_actionSave_as_triggered();
	void on_actionExit_triggered();
	void on_actionInvert_triggered();
	void on_actionFSHS_triggered();
	void on_actionEdgeMirror_triggered();
	void on_actionEKVHist_triggered();
	void on_actionConvolution_triggered();

};
