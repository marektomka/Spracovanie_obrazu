#include "IPmodul.h"

IPClass::IPClass()
{
}

void IPClass::mirroring(int N, int w, int h, uchar* origData)
{ 
	tempWidth = w + (2 * N); 
	tempHeight = h + (2 * N);
	int ZeroPix = N + (N * tempWidth);		// 0. pixel original
	tempData = new double[tempWidth * tempHeight];

	// stred
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			int index = j + (i * w);
			int tempIndex = ZeroPix + j + (i * tempWidth);
			tempData[tempIndex] = static_cast<double>(origData[index]);
		}
	}

	
	// hore a dole
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < w; j++)
		{
			int index = j + (N - 1 - i) * w;
			int tempIndex = N + j + (i * tempWidth);
			tempData[tempIndex] = static_cast<double>(origData[index]);

			index = j + (h - N + 1 + i) * (w - 1);
			tempIndex = N + (tempHeight - 1) * tempWidth + j - (i * tempWidth);
			tempData[tempIndex] = static_cast<double>(origData[index]);
		}
	}

	
	// lavy a pravy kraj 
	for (int i = 0; i < tempHeight; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int index1 = (i * tempWidth) + j;
			int index2 = (2 * N) + (i * tempWidth) - j;
			tempData[index1] = tempData[index2];

			index1 = (tempWidth - 1) + (i * tempWidth) - j;
			index2 = (i * tempWidth) - (2 * N) + j;
			tempData[index1] = tempData[index2];
		}
	}

}

void IPClass::unmirroring(int N, int w, int h)
{
	int ZeroPix = N + (N * tempWidth);		// 0. pixel new
	data = new uchar[w * h];

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			int index = j + (i * w);
			int tempIndex = ZeroPix + j + (i * tempWidth);
			data[index] = static_cast<uchar>(tempData[tempIndex] + 0.5);
		}
	}

}

IPClass::~IPClass()
{
	delete tempData;
}


bool IPClass::exportToPGM(std::string fileName, uint imgWidth, uint imgHeight, int maxValue, double* imgData, bool scaleData)
{
	printf("Exporting image to pgm...");
	FILE* fp = nullptr;
	fp = fopen((fileName + ".pgm").c_str(), "w+");
	if (fp == nullptr)
		return false;

	unsigned char scaledValue = 0;
	int dataSize = imgWidth * imgHeight;
	fprintf(fp, "P2\n%d %d\n%d\n", imgWidth, imgHeight, maxValue);

	if (scaleData)
	{
		for (size_t i = 0; i < dataSize; i++)
		{
			scaledValue = static_cast<unsigned char>(imgData[i] * maxValue + 0.5);
			fprintf(fp, "%d ", scaledValue);

			if ((i + 1) % 70 == 0)
				fprintf(fp, "\n");

			if ((i + 1) % (dataSize / 10) == 0)
				printf("\rExporting image to pgm... %d%% done", 10 * ((int)i + 1) / (dataSize / 10));
		}
	}
	else
	{
		for (size_t i = 0; i < dataSize; i++)
		{
			scaledValue = static_cast<unsigned char>(imgData[i] + 0.5);
			fprintf(fp, "%d ", scaledValue);

			if ((i + 1) % 70 == 0)
				fprintf(fp, "\n");

			if ((i + 1) % (dataSize / 10) == 0)
				printf("\rExporting image to pgm... %d%% done", 10 * ((int)i + 1) / (dataSize / 10));
		}
	}
	printf("\n");
	fclose(fp);

	return true;
}


bool IPClass::exportToPGM(std::string fileName, uint imgWidth, uint imgHeight, int maxValue, uchar* imgData)
{
	printf("Exporting image to pgm...");
	FILE* fp = nullptr;
	fp = fopen((fileName + ".pgm").c_str(), "w+");
	if (fp == nullptr)
		return false;

	int dataSize = imgWidth * imgHeight;
	fprintf(fp, "P2\n%d %d\n%d\n", imgWidth, imgHeight, maxValue);
	for (size_t i = 0; i < dataSize; i++)
	{
		fprintf(fp, "%d ", imgData[i]);

		if ((i + 1) % 70 == 0)
			fprintf(fp, "\n");

		if ((i + 1) % (dataSize / 10) == 0)
		{
			printf("\rExporting image to pgm... %d%% done", 10 * ((int)i + 1) / (dataSize / 10));
			//_sleep(500);
		}
	}
	printf("\n");
	fclose(fp);

	return true;
}
