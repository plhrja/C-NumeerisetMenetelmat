#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>
#include "nr.h"
#include "matutl02.h"

void isolateRow(Mat_DP mtr, int row, Mat_DP rowMtr);

void isolateCol(Mat_DP mtr, int col, Mat_DP colMtr);

void generatePlottingData(Mat_DP xdata, Mat_DP ydata, const char* fname);

void generatePlottingData(std::vector<double> xdata, std::vector<double> ydata, const char* fname);