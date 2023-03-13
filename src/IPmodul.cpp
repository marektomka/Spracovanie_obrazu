#include "IPmodul.h"

IPClass::IPClass()
{
}

bool IPClass::mirroring(int N, int w, int h, uchar* imgData)
{ 
	// Variables //
	tempWidth = w + (2 * N);
	tempHeight = h + (2 * N);
	int ZeroPix = N + (N * tempWidth);		// 0. pixel original

	// Delete old data //
	if (tempData != nullptr)
	{
		free(tempData); 
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
			int index = j + (i * w);
			int tempIndex = ZeroPix + j + (i * tempWidth);
			tempData[tempIndex] = static_cast<double>(imgData[index]);
		}
	}

	// Upper and lower mirror //
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < w; j++)
		{
			int index = j + (N - 1 - i) * w;
			int tempIndex = N + j + (i * tempWidth);
			tempData[tempIndex] = static_cast<double>(imgData[index]);

			index = j + ((h-1) - (N - 1) + i) * w;
			tempIndex = N + j + (tempHeight - 1) * tempWidth - (i * tempWidth);
			tempData[tempIndex] = static_cast<double>(imgData[index]);
		}
	}

	
	// Left and right mirror //
	for (int i = 0; i < tempHeight; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int index1 = (i * tempWidth) + j;
			int index2 = (2 * N) + (i * tempWidth) - j;
			tempData[index1] = tempData[index2];

			index1 = (tempWidth - 1) + (i * tempWidth) - j;
			index2 = w + j + (i * tempWidth);
			tempData[index1] = tempData[index2];
		}
	}

	return true;
}

bool IPClass::unmirroring(int N, int w, int h)
{

	// Variables //
	int ZeroPix = N + (N * tempWidth);		// 0. pixel new

	// Memory allocation // 
	if (tempData == nullptr)
		return false;

	data = new uchar[w * h];

	// Unmirror //
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			int index = j + (i * w);
			int tempIndex = ZeroPix + j + (i * tempWidth);
			data[index] = static_cast<uchar>(tempData[tempIndex] + 0.5);
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

bool IPClass::convolution(int w, int h, uchar* imgData)
{

	// Variables //
	double w1 = 0.234237; double w2 = 0.112116; double w3 = 0.0542418;
	double w4 = 0.01241; double w5 = 0.00600398; double w6 = 0.000664574;
	double sum = 0;
	int newI = 0, newJ; 
	int N = mask / 2;

	double mask[25] = {
	w6, w5, w4, w5, w6,
	w5, w3, w2, w3, w5,
	w4, w2, w1, w2, w4,
	w5, w3, w2, w3, w5,
	w6, w5, w4, w5, w6 };

	tempWidth = w + (2 * N);
	tempHeight = h + (2 * N);

	// Mirroring //
	mirroring(N, w, h, imgData);


	// Convolution // 
	
	for (int i = N; i < tempHeight - N; i++)
	{
		newJ = 0;
		for (int j = N; j < tempWidth - N; j++)
		{
			
			sum = 0; // 

			for (int k = -N; k <= N; k++)
			{
				for (int l = -N; l <= N; l++)
				{
					int maskIndex = (l + N) + (k + N) * 5; 

					int imageIndex = (j + l) + (i + k) * tempWidth;
					sum += mask[maskIndex] * tempData[imageIndex];

				}
			}

			imgData[newI * w + newJ] = static_cast<uchar>(sum + 0.5);

			newJ++;
		}
		newI++;
	}

	
	return true;
}

IPClass::~IPClass()
{
	free(tempData);
	free(data);
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
			fprintf(mirrorPic, "%d ", static_cast<unsigned char>(imgData[i * w + j]));		
		}
		fprintf(mirrorPic, "\n");
	}

	fclose(mirrorPic);

	printf("Export mirror to PGM successful\n");
	return true;
}

bool IPClass::exportPGM(int w, int h, uchar* imgData)
{
	FILE* unmirrorPic = nullptr;

	unmirrorPic = fopen("unmirrorPic.pgm", "wb"); 
	if (unmirrorPic == nullptr)
		return false;

	fprintf(unmirrorPic, "P2\n%d %d\n%d\n", w, h, 255);

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			fprintf(unmirrorPic, "%d ", imgData[i * w + j]);
		}
		fprintf(unmirrorPic, "\n");
	}

	fclose(unmirrorPic);

	printf("Export unmirror to PGM successful\n");
	return true;

}

