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
	int histogram[256] = { 0 };

	int tempWidth;
	int tempHeight;
	int minHistValue = 255;
	int maxHistValue = 0;

public:

	// Constructors // 
	IPClass();
	IPClass(uchar* dat) { data = dat; };

	// Filter functions // 
	bool mirroring(int N, int w, int h, uchar* origData);
	bool unmirroring(int N, int w, int h);
	void computeHistorgram(int w, int h, uchar* origData);
	void clearHistogram();
	bool FSHS(int w, int h, uchar* imgData);

	// Get functions //
	uchar* getData() { return data; };
	double* getDataM() { return tempData; };
	int getWidthM() { return tempWidth; };
	int getHeightM() { return tempHeight; };

	// Destructor //
	~IPClass();

	// Export functions // 
	bool exportPGM(int w, int h, double* imgData);
	bool exportPGM(int w, int h, uchar* imgData);
};