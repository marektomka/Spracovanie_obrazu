#include "IPmodul.h"

IPClass::IPClass()
{
}

bool IPClass::mirroring(int N, int w, int h, int bpl, uchar* imgData)
{ 
	// Variables //
	tempWidth = w + (2 * N);
	tempHeight = h + (2 * N);
	int ZeroPix = N + (N * tempWidth);		// 0. pixel original

	// Delete old data //
	if (tempData != nullptr)
	{
		delete[] tempData;
		tempData = nullptr;
	}

	// Memory allocation // 
	tempData = new double[tempWidth * tempHeight];

	if (tempData == nullptr) 
		return false;


	// Copy original data // 
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			int index = j + (i * bpl);
			int tempIndex = ZeroPix + j + (i * tempWidth);
			tempData[tempIndex] = static_cast<double>(imgData[index]);
		}
	}

	// Upper and lower mirror //
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < w; j++)
		{
			int index = j + (N - 1 - i) * bpl;
			int tempIndex = N + j + (i * tempWidth);
			tempData[tempIndex] = static_cast<double>(imgData[index]);   // upper edge index

			index = j + (h - N + i) * bpl;
			tempIndex = N + j + (tempHeight - 1 - i) * tempWidth;  // lower edge index
			tempData[tempIndex] = static_cast<double>(imgData[index]);
		}
	}

	
	// Left and right mirror //
	for (int i = 0; i < tempHeight; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int index1 = (i * tempWidth) + j;  // left edge index
			int index2 = 2 * N - 1 + (i * tempWidth) - j;
			tempData[index1] = tempData[index2]; 

			index1 = (tempWidth - 1) + (i * tempWidth) - j;  // right edge index
			index2 = (tempWidth - 2 * N) + j + (i * tempWidth);
			tempData[index1] = tempData[index2];
		}
	}

	return true;
}

bool IPClass::mirroring(int N, int w, int h,int bpl, double* imgData)
{

	// Variables //
	tempWidth = w + (2 * N);
	tempHeight = h + (2 * N);
	int ZeroPix = N + (N * tempWidth);		// 0. pixel original

	// Delete old data //
	if (tempData != nullptr)
	{
		delete[] tempData;
		tempData = nullptr;
	}

	// Memory allocation // 
	tempData = new double[tempWidth * tempHeight];

	if (tempData == nullptr)
		return false;


	// Copy original data // 
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			int index = j + (i * bpl);
			int tempIndex = ZeroPix + j + (i * tempWidth);
			tempData[tempIndex] = imgData[index];
		}
	}

	// Upper and lower mirror //
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < w; j++)
		{
			int index = j + (N - 1 - i) * bpl;
			int tempIndex = N + j + (i * tempWidth);  // upper edge index
			tempData[tempIndex] = imgData[index];

			index = j + (h - N + i) * bpl;
			tempIndex = N + j + (tempHeight - 1 - i) * tempWidth;  // lower edge index
			tempData[tempIndex] = imgData[index];

		}
	}


	// Left and right mirror //
	for (int i = 0; i < tempHeight; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int index1 = (i * tempWidth) + j; // left edge index
			int index2 = (2 * N - 1) + (i * tempWidth) - j;
			tempData[index1] = tempData[index2];

			index1 = (tempWidth - 1) + (i * tempWidth) - j; // right edge index
			index2 = (tempWidth - 2 * N) + j + (i * tempWidth);
			tempData[index1] = tempData[index2];

		}
	}

	return true;
}

bool IPClass::unmirroring(int N, int w, int h, int bpl, uchar* imgData)
{

	// Variables //
	int ZeroPix = N + (N * tempWidth);		// 0. pixel new

	// Memory allocation // 
	if (tempData == nullptr)
		return false;

	// Unmirror //
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			int index = j + (i * w);
			int tempIndex = ZeroPix + j + (i * tempWidth);
			imgData[index] = static_cast<uchar>(tempData[tempIndex] + 0.5);
		}
	}

	return true;
}

void IPClass::computeHistorgram(int w, int h, uchar* imgData)
{

	//clearHistogram(histogram);
	clearHistogram();

	// Algorithm for histogram comp.. // 
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			int index = j + (i * w);
			uchar value = imgData[index];

			// Min and max values // 
			if (value < minHistValue) { minHistValue = value; }
			if (value > maxHistValue) { maxHistValue = value; }
			
			
			histogram[value]++;
		}
	}

}

void IPClass::clearHistogram()
{
	// Clear histogram // 
	for (int i = 0; i < 256; i++)
	{
		histogram[i] = 0;
	}

}

bool IPClass::FSHS(int w, int h, uchar* imgData)
{
	// ImgData check //
	if (imgData == nullptr)
		return false;


	computeHistorgram(w, h, imgData);


	// FSHS algorithm //
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			int index = j + (i * w); 
			double value = static_cast<double>(imgData[index]);
			uchar newValue = static_cast<uchar>((255 * (value - minHistValue)) / (maxHistValue - minHistValue));
			
			imgData[index] = newValue;
		}
	}

	return true;
}

void IPClass::computeEKVHistogram(int w, int h, uchar* imgData)
{
	//clearHistogram((int*)histogramNORM);
	//clearHistogram((int*)histogramEKV);

	int numPixels = w * h;

	// Normalized histogram //
	for (int i = 0; i < 256; i++)
	{
		histogramNORM[i] = static_cast<double>(histogram[i]) / numPixels;
	}

	// EKV histogram // 
	histogramEKV[0] = histogramNORM[0];
	for (int i = 1; i < 256; i++)
	{
		histogramEKV[i] = histogramEKV[i - 1] + histogramNORM[i];
	}


}

bool IPClass::EKVHistogram(int w, int h, uchar* imgData)
{
	computeHistorgram(w, h, imgData);
	computeEKVHistogram(w, h, imgData);

	// EKV histogram algorithm //
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			int index = j + (i * w);
			int value = static_cast<int>(imgData[index]);
			uchar newValue = static_cast<uchar>(255 * histogramEKV[value] + 0.5);

			imgData[index] = newValue;
		}
	}

	return true;
}

bool IPClass::convolution(int w, int h, int bpl, uchar* imgData)
{

	// Variables //
	double w1 = 0.234237; double w2 = 0.112116; double w3 = 0.0542418;
	double w4 = 0.01241; double w5 = 0.00600398; double w6 = 0.000664574;
	double sum = 0;
	int newI = 0, newJ; 
	int N = (mask-1) / 2;

	double mask[25] = {
	w6, w5, w4, w5, w6,
	w5, w3, w2, w3, w5,
	w4, w2, w1, w2, w4,
	w5, w3, w2, w3, w5,
	w6, w5, w4, w5, w6 };

	tempWidth = w + (2 * N);
	tempHeight = h + (2 * N);

	// Mirroring //
	mirroring(N, w, h,bpl, imgData);


	// Convolution // 
	for (int i = N; i < tempHeight - N; i++)
	{
		newJ = 0;
		for (int j = N; j < tempWidth - N; j++)
		{
			
			sum = 0; 

			for (int k = -N; k <= N; k++)
			{
				for (int l = -N; l <= N; l++)
				{
					int maskIndex = (l + N) + (k + N) * 5; 

					int imageIndex = (j + l) + (i + k) * tempWidth;
					sum += mask[maskIndex] * tempData[imageIndex];

				}
			}

			imgData[newI * bpl + newJ] = static_cast<uchar>(sum + 0.5);

			newJ++;
		}
		newI++;
	}

	
	return true;
}

double IPClass::computeExplicit(int steps, double tau, int w, int h, int bpl, uchar* imgData)
{
	int N = 1;
	tempWidth = w + (2 * N);
	tempHeight = h + (2 * N);
	int ZeroPix = N + (N * tempWidth);      	// 0. pixel new

	double* stepExpli = new double[w * h] {0.0};

	// EXPLICIT // 

	for (int t = 1; t <= steps; t++)
	{
		double sumicka = 0;
		if (t == 1)
		{
			mirroring(N, w, h, bpl, imgData);
		}
		else mirroring(N, w, h, w, stepExpli);
		
	
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				double uN = 0; double uS = 0; 
				double uE = 0; double uW = 0;
				//double un = 0;
				
				int index = j + (i * w);
				int tempIndex = ZeroPix + j + i * tempWidth;

				uN = tempData[tempIndex - tempWidth];
				uS = tempData[tempIndex + tempWidth];
				uE = tempData[tempIndex + 1];
				uW = tempData[tempIndex - 1];

				double u = (1.0 - 4.0 * tau) * tempData[tempIndex] + tau * (uN + uS + uE + uW);
				stepExpli[index] = u;

				sumicka += stepExpli[index];
				if (t == steps)
				{
					imgData[index] = static_cast<uchar>(stepExpli[index] + 0.5);
				}
				
			}
		}

		printf("%.10lf\n", sumicka / (h * w));

	}


	return 0.0;
}

double IPClass::computeImplicit(double omega, double tau, int steps, int w, int h, int bpl, uchar* imgData)
{
	int N = 1;

	mirroring(N, w, h, bpl, imgData);

	tempWidth = w + (2 * N);
	tempHeight = h + (2 * N);

	double sum = 0.0;   // sum to - mean value of original image
	double meanOrig = 0.0;  // mean value of original image
	double meanFilter = 0.0;
	double toler = 0.000001;
	double rez = 0.0;
	double tempRez = 0.0;
	double sigma = 0.0;
	int iter = 0;
	int maxIter = 100;

	double* b = new double[tempWidth * tempHeight] {0.0};  // right side
	double* phi = tempData;  // mirrored image with edges (before unmirror) 

	double aii = 1.0 + 4 * tau;
	double aij = -tau;

	double phiN = 0.0; double phiS = 0.0;
	double phiE = 0.0; double phiW = 0.0;
	double phiC = 0.0;


	// compute mean value of original image // 
	for (size_t i = 0; i < h; i++)
	{
		for (size_t j = 0; j < w; j++)
		{
			sum += static_cast<double>(imgData[i * bpl + j]);
		}
	}
	meanOrig = sum / (w * h);
	printf("Mean value of original image: %.10lf\n", meanOrig);

	
	// Right side // 
	for (size_t i = 0; i < tempHeight; i++)
	{
		for (size_t j = 0; j < tempWidth; j++)
		{
			b[i * tempWidth + j] = static_cast<double>(tempData[i * tempWidth + j]);
		}
	}



	// IMPLICIT //
	for (size_t t = 0; t < steps; t++)
	{
		// SOR algorithm //
		iter = 0;

		rez = 0.0;
		do
		{
			iter++;

			for (size_t i = N; i < tempHeight - N; i++)
			{
				for (size_t j = N; j < tempWidth - N; j++)
				{
					phiN = 0.0; phiS = 0.0; phiE = 0.0; phiW = 0.0;
					
					phiC = phi[j + i * tempWidth];
					phiN = phi[j + (i - 1) * tempWidth];
					phiS = phi[j + (i + 1) * tempWidth];
					phiE = phi[j + i * tempWidth + 1];
					phiW = phi[j + i * tempWidth - 1];
					
					sigma = aij * (phiN + phiS + phiE + phiW);
					phi[j + i * tempWidth] = (1.0 - omega) * phi[j + i * tempWidth] + omega * (b[j + i * tempWidth] - sigma) / aii;
					

				}
			}
			
			// update edges // 
			mirrorEdges(N);

			// compute residuals // 
			// Ax - b // 
			tempRez = 0.0;
			rez = 0.0;
			for (size_t i = N; i < tempHeight - N; i++)
			{
				for (size_t j = N; j < tempWidth - N; j++)
				{
					phiN = 0.0; phiS = 0.0; phiE = 0.0; phiW = 0.0;

					phiC = phi[j + i * tempWidth];
					phiN = phi[j + (i - 1) * tempWidth];
					phiS = phi[j + (i + 1) * tempWidth];
					phiE = phi[j + i * tempWidth + 1];
					phiW = phi[j + i * tempWidth - 1];

					tempRez = (aii * phiC + aij * (phiN + phiS + phiE + phiW)) - b[j + i * tempWidth];
					rez += tempRez * tempRez;
				}
			}

			if (sqrt(rez) < toler)
			{
				break;
			}

			printf("Time step: %d .. Iteration: %d .. Rez: %.10lf\n", t, iter, sqrt(rez));

		} while (iter < maxIter);



		// Compute mean value of new image // 
		sum = 0.0;
		meanFilter = 0.0;
		for (size_t i = N; i < tempHeight - N; i++)
		{
			for (size_t j = N; j < tempWidth - N; j++)
			{
				int index = j + i * tempWidth;

				sum += phi[index];

				b[index] = phi[index];   // update right side 
			}
		}
		meanFilter = sum / (w * h);
		printf("End in step: %d ..... Iteration: %d .....  Mean value: %.10lf\n", t, iter, meanFilter);



	}

	unmirroring(N, w, h, bpl, imgData);

	delete[] b;

	return 0.0;
}

void IPClass::mirrorEdges(int N)
{
	int centerIndex = -1;
	int edgeIndex = -1;

	// Upper and lower mirror //
	for (int i = 0; i < N; i++)
	{
		for (int j = N; j < tempWidth - N; j++)
		{
			centerIndex = j + (i + N) * tempWidth;
			edgeIndex = j + (N - 1 - i) * tempWidth;		// upper edge index
			tempData[edgeIndex] = tempData[centerIndex];

			centerIndex = (tempHeight - N - 1 - i) * tempWidth + j;
			edgeIndex = (tempHeight - N + i) * tempWidth + j;  // lower edge index
			tempData[edgeIndex] = tempData[centerIndex];

		}
	}

	// Left and right mirror //
	for (int i = 0; i < tempHeight; i++)
	{
		for (int j = 0; j < N; j++)
		{
			centerIndex = (i * tempWidth) + (N + j);
			edgeIndex = (i * tempWidth) + (N - 1 - j);  // left edge index
			tempData[edgeIndex] = tempData[centerIndex];

			centerIndex = (tempWidth - N - 1 - j) + (i * tempWidth);
			edgeIndex = (tempWidth - N + j) + (i * tempWidth);  // right edge index
			tempData[edgeIndex] = tempData[centerIndex];
		}
	}

	// control of mirror function
	// exportPGM(tempWidth, tempHeight, tempData);

}

IPClass::~IPClass()
{
	delete[] tempData;
}


bool IPClass::exportPGM(int w, int h, double* imgData)
{
	FILE* mirrorPic = nullptr;

	mirrorPic = fopen("mirrorPic.pgm", "wb");
	if (mirrorPic == nullptr)
		return false;

	fprintf(mirrorPic, "P2\n%d %d\n%d\n", w, h, 255);

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			fprintf(mirrorPic, "%d ", static_cast<uchar>(imgData[i * w + j] + 0.5));
		}
		fprintf(mirrorPic, "\n");
	}

	fclose(mirrorPic);

	printf("Export mirror to PGM successful\n");
	return true;
}

bool IPClass::exportPGM(int w, int h, int bpl, uchar* imgData)
{
	FILE* unmirrorPic = nullptr;

	unmirrorPic = fopen("unmirrorPic.pgm", "wb"); 
	if (unmirrorPic == nullptr)
		return false;

	fprintf(unmirrorPic, "P2\n%d %d\n%d\n", w, h, 255);

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			fprintf(unmirrorPic, "%d ", imgData[i * bpl + j]);
		}
		fprintf(unmirrorPic, "\n");
	}

	fclose(unmirrorPic);

	printf("Export unmirror to PGM successful\n");
	return true;

}

