#pragma once
#include <stdio.h> 
#include <vector> 

typedef unsigned char uchar;
typedef unsigned int uint;


class IPClass
{
private:

	double* tempData = nullptr;
	double* GradtempData = nullptr;

	int histogram[256] = { 0 };
	double histogramNORM[256] = { 0 };
	double histogramEKV[256] = { 0 };

	int tempWidth;
	int tempHeight;
	int minHistValue = 255;
	int maxHistValue = 0;
	int mask = 5;

	struct Gradient 
	{
		double edgeN = 0.0;
		double edgeS = 0.0;
		double edgeW = 0.0;
		double edgeE = 0.0;
	}; 

	std::vector<Gradient> pixelsGradient = {};

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
	void computeGradientsPM(double omega, double tau, int steps, int w, int h, int bpl);
	void mirrorEdges(int N, double* DataTmp);
	void computePM(double K, double omega, double sigma, double tau, int steps, int w, int h, int bpl, uchar* imgData);
	void copyData();

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