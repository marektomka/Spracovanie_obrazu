#include "ImageViewer.h"


ImageViewer::ImageViewer(QWidget* parent)
	: QMainWindow(parent), ui(new Ui::ImageViewerClass)
{
	ui->setupUi(this);
	vW = new ViewerWidget(QSize(500, 500));
	
	ui->scrollArea->setWidget(vW);

	ui->scrollArea->setBackgroundRole(QPalette::Dark);
	ui->scrollArea->setWidgetResizable(true);
	ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

	vW->setObjectName("ViewerWidget");
	
}

//ImageViewer Events
void ImageViewer::closeEvent(QCloseEvent* event)
{
	if (QMessageBox::Yes == QMessageBox::question(this, "Close Confirmation", "Are you sure you want to exit?", QMessageBox::Yes | QMessageBox::No))
	{
		event->accept();
	}
	else {
		event->ignore();
	}
}

//Image functions
bool ImageViewer::openImage(QString filename)
{
	QImage loadedImg(filename);
	if (!loadedImg.isNull()) {
		return vW->setImage(loadedImg);
	}
	return false;
}
bool ImageViewer::saveImage(QString filename)
{
	QFileInfo fi(filename);
	QString extension = fi.completeSuffix();

	QImage* img = vW->getImage();
	return img->save(filename, extension.toStdString().c_str());
}

bool ImageViewer::invertColors()
{

	if (vW->isEmpty()) {
		return false;
	}

	uchar* data = vW->getData();

	int row = vW->getImage()->bytesPerLine();
	int depth = vW->getImage()->depth();

	for (int i = 0; i < vW->getImgHeight(); i++)
	{
		for (int j = 0; j < vW->getImgWidth(); j++)
		{
			//Grayscale
			if (depth == 8) {
				vW->setPixel(j, i, static_cast<uchar>(255 - data[i * row + j]));
			}
			//RGBA
			else {
				uchar r = static_cast<uchar>(255 - data[i * row + j * 4]);
				uchar g = static_cast<uchar>(255 - data[i * row + j * 4 + 1]);
				uchar b = static_cast<uchar>(255 - data[i * row + j * 4 + 2]);
				vW->setPixel(j, i, r, g, b);
			}
		}
	}
	vW->update();

	return true;
}

//Slots
void ImageViewer::on_actionOpen_triggered()
{
	QString folder = settings.value("folder_img_load_path", "").toString();

	QString fileFilter = "Image data (*.bmp *.gif *.jpg *.jpeg *.png *.pbm *.pgm *.ppm .*xbm .* xpm);;All files (*)";
	QString fileName = QFileDialog::getOpenFileName(this, "Load image", folder, fileFilter);
	if (fileName.isEmpty()) { return; }

	QFileInfo fi(fileName);
	settings.setValue("folder_img_load_path", fi.absoluteDir().absolutePath());

	if (!openImage(fileName)) {
		msgBox.setText("Unable to open image.");
		msgBox.setIcon(QMessageBox::Warning);
		msgBox.exec();
		opened = false;
	}

	opened = true;
}
void ImageViewer::on_actionSave_as_triggered()
{
	QString folder = settings.value("folder_img_save_path", "").toString();

	QString fileFilter = "Image data (*.bmp *.gif *.jpg *.jpeg *.png *.pbm *.pgm *.ppm .*xbm .* xpm);;All files (*)";
	QString fileName = QFileDialog::getSaveFileName(this, "Save image", folder, fileFilter);
	if (!fileName.isEmpty()) {
		QFileInfo fi(fileName);
		settings.setValue("folder_img_save_path", fi.absoluteDir().absolutePath());

		if (!saveImage(fileName)) {
			msgBox.setText("Unable to save image.");
			msgBox.setIcon(QMessageBox::Warning);
		}
		else {
			msgBox.setText(QString("File %1 saved.").arg(fileName));
			msgBox.setIcon(QMessageBox::Information);
		}
		msgBox.exec();
	}
}
void ImageViewer::on_actionExit_triggered()
{
	this->close();
}

void ImageViewer::on_actionInvert_triggered()
{
	if (opened)
	{
		invertColors();
	}
	else
	{
		msgBox.setText("Please open image.");
		msgBox.setIcon(QMessageBox::Warning);
		msgBox.exec();
	}
}

void ImageViewer::on_actionFSHS_triggered()
{
	if (opened)
	{
		IPClass ipmodul;

		ipmodul.FSHS(vW->getImage()->width(), vW->getImage()->height(), vW->getData());

		printf("FSHS successful\n");
		vW->update();
	}
	else
	{
		msgBox.setText("Please open image.");
		msgBox.setIcon(QMessageBox::Warning);
		msgBox.exec();
	}
}

void ImageViewer::on_actionEdgeMirror_triggered()
{

	int N = 250;    // N for mirroring

	if (opened)
	{
		IPClass ipmodul;

		// Mirror function //
		ipmodul.mirroring(N,vW->getImage()->width(), vW->getImage()->height(), vW->getImage()->bytesPerLine(), vW->getData());

		// Unmirror function //
		ipmodul.unmirroring(N, vW->getImage()->width(), vW->getImage()->height(), vW->getImage()->bytesPerLine(), vW->getData());

		// Export data to PGM // 
		ipmodul.exportPGM(ipmodul.getWidthM(), ipmodul.getHeightM(), ipmodul.getDataM());
		ipmodul.exportPGM(vW->getImage()->width(), vW->getImage()->height(),vW->getImage()->bytesPerLine(), vW->getData());
		
	}
	else
	{
		msgBox.setText("Please open image.");
		msgBox.setIcon(QMessageBox::Warning);
		msgBox.exec();
	}
}

void ImageViewer::on_actionEKVHist_triggered()
{
	if (opened)
	{
		IPClass ipmodul;

		ipmodul.EKVHistogram(vW->getImage()->width(), vW->getImage()->height(), vW->getData());

		printf("EKV histogram successful\n");
		vW->update();
	}
	else
	{
		msgBox.setText("Please open image.");
		msgBox.setIcon(QMessageBox::Warning);
		msgBox.exec();
	}
}

void ImageViewer::on_actionConvolution_triggered()
{
	if (opened)
	{
		IPClass ipmodul;

		// Convolution function // 
		ipmodul.convolution(vW->getImage()->width(), vW->getImage()->height(), vW->getImage()->bytesPerLine(), vW->getData());
		printf("Convolution successful\n");

		vW->update();
	}
	else
	{
		msgBox.setText("Please open image.");
		msgBox.setIcon(QMessageBox::Warning);
		msgBox.exec();
	}

}

void ImageViewer::on_pushButtonExplicit_clicked()
{
	double tau = ui->doubleSpinBoxTau->value();
	int steps = ui->spinBoxStepsExplicit->value();

	if (opened)
	{
		IPClass ipmodul;
		ipmodul.computeExplicit(steps, tau, vW->getImage()->width(), vW->getImage()->height(), vW->getImage()->bytesPerLine(), vW->getData());

		vW->update();
		printf("Explicit successful\n");
	}
	else
	{
		msgBox.setText("Please open image.");
		msgBox.setIcon(QMessageBox::Warning);
		msgBox.exec();
	}

}

void ImageViewer::on_pushButtonImplicit_clicked()
{
	double tau = ui->doubleSpinBoxTauImplicit->value();
	double omega = ui->doubleSpinBoxOmega->value();
	int steps = ui->spinBoxStepsImplicit->value();

	if (opened)
	{
		IPClass ipmodul;
		ipmodul.computeImplicit(omega, tau, steps, vW->getImage()->width(), vW->getImage()->height(), vW->getImage()->bytesPerLine(), vW->getData());

		vW->update();

		printf("Implicit successful\n");
		

	}
	else
	{
		msgBox.setText("Please open image.");
		msgBox.setIcon(QMessageBox::Warning);
		msgBox.exec();
	}


}

void ImageViewer::on_pushButtonPM_clicked()
{
	double sigma = ui->doubleSpinBoxSigmaPM->value();
	double tau = ui->doubleSpinBoxTauPM->value();
	double K = ui->doubleSpinBoxKPM->value();
	double steps = ui->spinBoxStepsPM->value();
	double omega = ui->doubleSpinBoxOmegaPM->value();


	if (opened)
	{
		IPClass ipmodul;
		ipmodul.computePM(K, omega, sigma, tau, steps, vW->getImage()->width(), vW->getImage()->height(), vW->getImage()->bytesPerLine(), vW->getData());

		vW->update();

		printf("Perona-Malik successful\n");

	}
	else
	{
		msgBox.setText("Please open image.");
		msgBox.setIcon(QMessageBox::Warning);
		msgBox.exec();
	}

}

void ImageViewer::on_pushButtonGMCF_clicked()
{
	double sigma = ui->doubleSpinBoxSigmaPM->value();
	double tau = ui->doubleSpinBoxTauPM->value();
	double K = ui->doubleSpinBoxKPM->value();
	double steps = ui->spinBoxStepsPM->value();
	double omega = ui->doubleSpinBoxOmegaPM->value();
	double epsilon = ui->doubleSpinBoxEpsilon->value();


	if (opened)
	{
		IPClass ipmodul;
		ipmodul.computeGMCF(K, omega, sigma, tau, steps, epsilon, vW->getImage()->width(), vW->getImage()->height(), vW->getImage()->bytesPerLine(), vW->getData());

		vW->update();

		printf("(G)MCF successful\n");

	}
	else
	{
		msgBox.setText("Please open image.");
		msgBox.setIcon(QMessageBox::Warning);
		msgBox.exec();
	}


}


