#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>
#include "nr.h"
#include "matutl02.h"

#define MUL_DEF 1.1

void isolateRow(Mat_DP& mtr, int row, Mat_DP& rowMtr) {
    if(mtr.ncols() != rowMtr.nrows() || row >= mtr.nrows()){
        cout << "invalid matrix dimensions!" << endl;
        return;
    }
    for (int i = 0; i < mtr.ncols(); i++) {
        rowMtr[i][0] = mtr[row][i];
    }
}

void isolateCol(Mat_DP& mtr, int col, Mat_DP& colMtr) {
    if(mtr.nrows() != colMtr.nrows() || col >= mtr.ncols()){
        cout << "invalid matrix dimensions!" << endl;
        return;
    }
    for (int i = 0; i < mtr.nrows(); i++) {
        colMtr[i][0] = mtr[i][col];
    }
}

void isolateRow(Mat_DP& mtr, int row, Vec_DP& rowVec) {
    if(mtr.ncols() != rowVec.size() || row >= mtr.nrows()){
        cout << "invalid matrix dimensions!" << endl;
        return;
    }
    for (int i = 0; i < mtr.ncols(); i++) {
        rowVec[i] = mtr[row][i];
    }
}

void isolateCol(Mat_DP& mtr, int col, Vec_DP& colVec) {
    if(mtr.nrows() != colVec.size() || col >= mtr.ncols()){
        cout << "invalid matrix dimensions!" << endl;
        return;
    }
    for (int i = 0; i < mtr.nrows(); i++) {
        colVec[i] = mtr[i][col];
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

void generatePlottingData(Mat_DP xdata, Mat_DP ydata, std::string fnameString) {
    const char* str = fnameString.c_str();
    generatePlottingData(xdata, ydata, str);
}

void generatePlottingData(std::vector<double> xdata, std::vector<double> ydata, std::string fnameString) {
    const char* str = fnameString.c_str();
    generatePlottingData(xdata, ydata, str);
}

void generatePlottingData(Vec_DP xdata, Vec_DP ydata, std::string fnameString) {
    const char* str = fnameString.c_str();
    generatePlottingData(xdata, ydata, str);
}

void DDmatrix(Mat_DP& A, double mul, double low, double high) {
    ranmat2(A, low, high);
    mul = (mul < 1) ? MUL_DEF : mul;

    for (int i = 0; i < A.nrows(); i++) {
        double sum = 0;

        for (int j = 0; j < A.ncols(); j++) {
            sum += (i != j) ? abs(A[i][j]) : 0;
        }
        A[i][i] = sum * mul;
    }
}

bool isDDmatrix(Mat_DP& A) {
    for (int i = 0; i < A.nrows(); i++) {
        double sum = 0;

        for (int j = 0; j < A.ncols(); j++) {
            sum += (i != j) ? abs(A[i][j]) : 0;
        }
        if (sum > A[i][i]) {
            cout << "FAIL! n = " << A.nrows() << ", A(" << i << "," << i;
            cout << ") - sum = " << A[i][i] - sum << endl;
            return false;

        }
    }
    return true;
}

void eigen(Mat_DP &a, Vec_CPLX_DP &w) {
    NR::balanc(a);
    NR::elmhes(a);
    NR::hqr(a, w);
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