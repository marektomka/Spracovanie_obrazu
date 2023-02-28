#include "IPmodul.h"

IPClass::IPClass()
{
}

bool IPClass::mirroring(int N, int w, int h, uchar* origData)
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
			tempData[tempIndex] = static_cast<double>(origData[index]);
		}
	}

	// Upper and lower mirror //
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < w; j++)
		{
			int index = j + (N - 1 - i) * w;
			int tempIndex = N + j + (i * tempWidth);
			tempData[tempIndex] = static_cast<double>(origData[index]);

			index = j + ((h-1) - (N - 1) + i) * w;
			tempIndex = N + j + (tempHeight - 1) * tempWidth - (i * tempWidth);
			tempData[tempIndex] = static_cast<double>(origData[index]);
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

void IPClass::computeHistorgram(int w, int h, uchar* origData)
{

	clearHistogram();

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			int index = j + (i * w);
			uchar value = origData[index];

			// Min and max values // 
			if (value < minHistValue) minHistValue = value;
			if (value > maxHistValue) maxHistValue = value;
			
			
			histogram[value]++;
		}
	}

}

void IPClass::clearHistogram()
{
	// Clear histogram // 
	for (size_t i = 0; i < 256; i++)
	{
		histogram[i] = 0;
	}

}

bool IPClass::FSHS(int w, int h, uchar* imgData)
{
	if (imgData == nullptr)
		return false;

	computeHistorgram(w,h,imgData);

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







/*
bool IPmodul::FSHS(uchar* imgData, const int bytesPerLine, const int imgWidth, const int imgHeight)
{
	if (imgData == nullptr)
		return false;

	// compute histogram for the given image, function also finds min and max values
	computeHistogramData(imgData, bytesPerLine, imgWidth, imgHeight);

	int index = 0;
	double temp = 0;
	uchar scaledValue = 0;
	for (int i = 0; i < imgHeight; i++)
	{
		for (int j = 0; j < imgWidth; j++)
		{
			index = i * bytesPerLine + j;
			// scale values from original range [m_minValue, m_maxValue] to [0, 255]
			temp = static_cast<double>(imgData[index]);
			scaledValue = static_cast<uchar>(((temp - m_minValue) / (m_maxValue - m_minValue)) * 255 + 0.5);
			imgData[index] = scaledValue;
		}
	}

	return true;
}

*/