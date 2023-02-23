#pragma once
#include <stdio.h> 
#include "string"
typedef unsigned char uchar;
typedef unsigned int uint;



class IPClass
{
private:

	uchar* data = nullptr;
	double* tempData = nullptr;

	int tempWidth;
	int tempHeight;

public:

	// Constructors // 
	IPClass();
	IPClass(uchar* dat) { data = dat; };

	// Filter functions // 
	void mirroring(int N, int w, int h, uchar* origData);
	void unmirroring(int N, int w, int h);

	// Get functions //
	uchar* getData() { return data; };
	double* getDataM() { return tempData; };
	int getWidthM() { return tempWidth; };
	int getHeightM() { return tempHeight; };

	// Destructor //
	~IPClass();

	// Export functions // 
	bool exportToPGM(std::string fileName, uint imgWidth, uint imgHeight, int maxValue, double* imgData, bool scaleData);
	bool exportToPGM(std::string fileName, uint imgWidth, uint imgHeight, int maxValue, uchar* imgData);

};