#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>
#include "nr.h"

void isolateRow(Mat_DP mtr, int row, Mat_DP* rowMtr) {
    for (int i = 0; i < mtr.ncols(); i++) {
        (*rowMtr)[i][0] = mtr[row][i];
    }
}

void isolateCol(Mat_DP mtr, int col, Mat_DP* colMtr) {
    for (int i = 0; i < mtr.nrows(); i++) {
        (*colMtr)[i][0] = mtr[i][col];
    }
}

void generatePlottingData(Mat_DP xdata, Mat_DP ydata, const char* fname) {
    std::ofstream f(fname);

    for (int i = 0; i < xdata.nrows(); i++) {
        f.precision(6);
        f << xdata[i][0] << " " << ydata[i][0] << std::endl;
    }

    f.close();
}

void generatePlottingData(std::vector<double> xdata, std::vector<double> ydata, const char* fname) {
    std::ofstream f(fname);

    for (int i = 0; i < xdata.size(); i++) {
        f.precision(6);
        f << xdata[i] << " " << ydata[i] << std::endl;
    }

    f.close();
}

void generatePlottingData(Vec_DP xdata, Vec_DP ydata, const char* fname) {
    std::ofstream f(fname);

    for (int i = 0; i < xdata.size(); i++) {
        f.precision(6);
        f << xdata[i] << " " << ydata[i] << std::endl;
    }

    f.close();
}

void LUsolve(Mat_DP a, Vec_DP b, Vec_DP &x){
    int rows = a.nrows(), cols = a.ncols(), mb = b.size(), xsize = x.size();
    if ((rows != cols) || (rows != mb) || (rows != xsize)) {
        cout << "Matrix/vector dimension error in LUsolve. " << endl;
        abort();
    }
    
    DP p;
    Vec_INT indx(rows);
   
    NR::ludcmp(a, indx, p);
    NR::lubksb(a, indx, b);
    x = b;
}