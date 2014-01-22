#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>
#include "nr.h"
#include "matutl02.h"

void isolateRow(Mat_DP mtr, int row, Mat_DP* rowMtr){
    for (int i = 0; i < mtr.ncols(); i++) {
        (*rowMtr)[i][0] = mtr[row][i];
    }
}

void isolateCol(Mat_DP mtr, int col, Mat_DP* colMtr){
    for (int i = 0; i < mtr.nrows(); i++) {
        (*colMtr)[i][0] = mtr[i][col];
    }
}

void generatePlottingData(Mat_DP xdata, Mat_DP ydata, const char* fname){
    std::ofstream f(fname);
    
    for (int i = 0; i < xdata.nrows(); i++) {
        f.precision(6);
        f << xdata[i][0] << " " << ydata[i][0] << std::endl;
    }
    
    f.close();
}
void generatePlottingData(std::vector<double> xdata, std::vector<double> ydata, const char* fname){
    std::ofstream f(fname);
    
    for (int i = 0; i < xdata.size(); i++) {
        f.precision(6);
        f << xdata[i] << " " << ydata[i] << std::endl;
    }
    
    f.close();
}