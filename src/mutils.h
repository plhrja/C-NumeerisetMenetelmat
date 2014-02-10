#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>
#include "nr.h"
#include "matutl02.h"

void isolateRow(Mat_DP& mtr, int row, Mat_DP& rowMtr);

void isolateCol(Mat_DP& mtr, int col, Mat_DP& colMtr);

void isolateRow(Mat_DP& mtr, int row, Vec_DP& rowVec);

void isolateCol(Mat_DP& mtr, int col, Vec_DP& colVec);

void generatePlottingData(Mat_DP xdata, Mat_DP ydata, const char* fname);

void generatePlottingData(Vec_DP xdata, Vec_DP ydata, const char* fname);

void generatePlottingData(std::vector<double> xdata, std::vector<double> ydata, const char* fname);

void generatePlottingData(Mat_DP xdata, Mat_DP ydata, std::string fnameString);

void generatePlottingData(Vec_DP xdata, Vec_DP ydata, std::string fnameString);

void generatePlottingData(std::vector<double> xdata, std::vector<double> ydata, std::string fnameString);

void DDmatrix(Mat_DP& A, double mul, double low, double high);

bool isDDmatrix(Mat_DP& A);

void eigen(Mat_DP &a, Vec_CPLX_DP &w);

void LUsolve(Mat_DP a, Vec_DP b, Vec_DP &x);