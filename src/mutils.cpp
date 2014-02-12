#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>
#include <solve.h>
#include "nr.h"
#include "matutl02.h"
#include "mutils.h"

#define MUL_DEF 1.1

void mutils::isolateRow(const Mat_DP &mtr, int row, Mat_DP &rowMtr) {
    if (mtr.ncols() != rowMtr.nrows() || row >= mtr.nrows()) {
        cout << "invalid matrix dimensions!" << endl;
        return;
    }
    for (int i = 0; i < mtr.ncols(); i++) {
        rowMtr[i][0] = mtr[row][i];
    }
}

void mutils::isolateCol(const Mat_DP &mtr, int col, Mat_DP &colMtr) {
    if (mtr.nrows() != colMtr.nrows() || col >= mtr.ncols()) {
        cout << "invalid matrix dimensions!" << endl;
        return;
    }
    for (int i = 0; i < mtr.nrows(); i++) {
        colMtr[i][0] = mtr[i][col];
    }
}

void mutils::isolateRow(const Mat_DP &mtr, int row, Vec_DP &rowVec) {
    if (mtr.ncols() != rowVec.size() || row >= mtr.nrows()) {
        cout << "invalid matrix dimensions!" << endl;
        return;
    }
    for (int i = 0; i < mtr.ncols(); i++) {
        rowVec[i] = mtr[row][i];
    }
}

void mutils::isolateCol(const Mat_DP &mtr, int col, Vec_DP &colVec) {
    if (mtr.nrows() != colVec.size() || col >= mtr.ncols()) {
        cout << "invalid matrix dimensions!" << endl;
        return;
    }
    for (int i = 0; i < mtr.nrows(); i++) {
        colVec[i] = mtr[i][col];
    }
}

void mutils::generatePlottingData(const Mat_DP &xdata, const Mat_DP &ydata, const char* fname) {
    std::ofstream f(fname);

    for (int i = 0; i < xdata.nrows(); i++) {
        f.precision(6);
        f << xdata[i][0] << " " << ydata[i][0] << std::endl;
    }

    f.close();
}

void mutils::generatePlottingData(const std::vector<double> &xdata, const std::vector<double> &ydata, const char* fname) {
    std::ofstream f(fname);

    for (int i = 0; i < xdata.size(); i++) {
        f.precision(6);
        f << xdata[i] << " " << ydata[i] << std::endl;
    }

    f.close();
}

void mutils::generatePlottingData(const Vec_DP &xdata, const Vec_DP &ydata, const char* fname) {
    std::ofstream f(fname);

    for (int i = 0; i < xdata.size(); i++) {
        f.precision(6);
        f << xdata[i] << " " << ydata[i] << std::endl;
    }

    f.close();
}

void mutils::generatePlottingData(const Mat_DP &xdata, const Mat_DP &ydata, std::string fnameString) {
    const char* str = fnameString.c_str();
    generatePlottingData(xdata, ydata, str);
}

void mutils::generatePlottingData(const std::vector<double> &xdata, const std::vector<double> &ydata, std::string fnameString) {
    const char* str = fnameString.c_str();
    generatePlottingData(xdata, ydata, str);
}

void mutils::generatePlottingData(const Vec_DP &xdata, const Vec_DP &ydata, std::string fnameString) {
    const char* str = fnameString.c_str();
    generatePlottingData(xdata, ydata, str);
}

void mutils::DDmatrix(Mat_DP &A, double mul, double low, double high) {
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

bool mutils::isDDmatrix(const Mat_DP &A) {
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

void mutils::eigen(Mat_DP &a, Vec_CPLX_DP &w) {
    NR::balanc(a);
    NR::elmhes(a);
    NR::hqr(a, w);
}

void mutils::LUsolve(Mat_DP a, Vec_DP b, Vec_DP &x) {
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

void mutils::polyfit_LU(const Vec_DP &xdata, const Vec_DP &ydata, Vec_DP &coeffs, int degree) {
    if (coeffs.size() < degree + 1 || ydata.size() != xdata.size()) {
        perror("Unbalanced parameter sizes!");
        return;
    }

    Mat_DP A(degree + 1, degree + 1);
    Vec_DP b(degree + 1);
    
    for (int n = 1; n <= degree * 2; n++) {
        double sum = 0;
        for (int i = 0; i < xdata.size(); i++) {
            sum += pow(xdata[i], n);
        }
        for (int i = max(0, degree - n); i <= min(degree, (degree*2) - n); ++i) {
                int j = 2 * degree - n - i;
                A[i][j] = sum;
            }
    }
    A[degree][degree] = xdata.size();
    
    for (int n = 0; n < degree + 1; n++) {
        double sum = 0;
        for (int i = 0; i < xdata.size(); i++) {
            sum += ydata[i] * pow(xdata[i], n);
        }
        b[degree - n] = sum;
    }
    mutils::LUsolve(A, b, coeffs);
}

void mutils::polyfit_SVD(const Vec_DP &xdata, const Vec_DP &ydata, Vec_DP &coeffs, int degree){
    if (coeffs.size() < degree + 1 || ydata.size() != xdata.size()) {
        perror("Unbalanced parameter sizes!");
        return;
    }
    
    Mat_DP A(xdata.size(), degree + 1);
    Vec_DP b(xdata.size());
    for (int i = 0; i < xdata.size(); i++) {
        for (int j = 0; j < degree + 1; j++) {
            A[i][j] = pow(xdata[i], degree - j);
        }
        b[i] = ydata[i];
    }
    SVDsolve(A, b, coeffs);
}