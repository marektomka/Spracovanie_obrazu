#pragma once
#include <stdio.h> 
#include "string"
typedef unsigned char uchar;
typedef unsigned int uint;


class IPClass
{
private:

	double* tempData = nullptr;
	int histogram[256] = { 0 };
	double histogramNORM[256] = { 0 };
	double histogramEKV[256] = { 0 };


	int tempWidth;
	int tempHeight;
	int minHistValue = 255;
	int maxHistValue = 0;
	int mask = 5;

public:

	// Constructors // 
	IPClass();

	// Filter functions // 
	bool mirroring(int N, int w, int h,int bpl, uchar* imgData);
	bool mirroring(int N, int w, int h,int bpl, double* imgData);
	bool unmirroring(int N, int w, int h, int bpl, uchar* imgData);
	void computeHistorgram(int w, int h, uchar* imgData);
	void clearHistogram();
	bool FSHS(int w, int h, uchar* imgData);
	void computeEKVHistogram(int w, int h, uchar* imgData);
	bool EKVHistogram(int w, int h, uchar* imgData);
	bool convolution(int w, int h,int bpl, uchar* imgData);
	double computeExplicit(int steps, double tau, int w, int h, int bpl, uchar* imgData);
	double computeImplicit(double omega, double tau, int steps, int w, int h, int bpl, uchar* imgData);
	void mirrorEdges(int N);

	// Get functions //
	double* getDataM() { return tempData; };
	int getWidthM() { return tempWidth; };
	int getHeightM() { return tempHeight; };


	// Destructor //
	~IPClass();

	// Export functions // 
	bool exportPGM(int w, int h, double* imgData);
	bool exportPGM(int w, int h, int bpl, uchar* imgData);
};