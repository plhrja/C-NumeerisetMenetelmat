#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>
#include <solve.h>
#include "nr.h"
#include "matutl02.h"
#include "numdiff.h"
#include "mutils.h"

void myHOUSEsolve(Mat_DP &a, Vec_DP &b, Vec_DP &sol);

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

double mutils::deriv(double (*f)(double), double x){
    double h = 1e-5;
    Vec_DP y(6), dy(6);
    for (int i = 1; i <= 5; i++) {
        y[i] = f(x + (i-3) * h);
    }
    numder(y, dy, h, 5);
    return dy[3];
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
        for (int i = max(0, degree - n); i <= min(degree, (degree * 2) - n); ++i) {
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

void mutils::polyfit_SVD(const Vec_DP &xdata, const Vec_DP &ydata, Vec_DP &coeffs, int degree) {
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

void mutils::polyfit_HOUSE(const Vec_DP &xdata, const Vec_DP &ydata, Vec_DP &coeffs, int degree) {
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
    myHOUSEsolve(A, b, coeffs);
}

//---------------------------------------------------private---------------------------------------------------

void house2(Mat_DP &a)
/* Overwrites a by its upper triangular Householder matrix
 See Heath p. 124 */ {
    int m = a.nrows(), n = a.ncols();
    if ((m < 2) || (n < 2)) {
        cout << "Argument error in house2,m,n="
                << m << ",  " << n << endl;
        abort();
    }
    Mat_DP v(m, 1), vT(1, m), e(m, 1);
    DP alf, beta, gam;
    for (int k = 0; k < n; k++) {
        DP s = 0.0;
        v = 0.0;
        vT = 0.0;
        for (int kk = 0; kk < m; kk++) e[kk][0] = (kk == k) ? 1 : 0;
        for (int kk = k; kk < m; kk++) {
            s += a[kk][k] * a[kk][k];
            v[kk][0] = a[kk][k];
        }
        alf = (a[k][k] > 0) ? pow(s, 0.5) : -pow(s, 0.5);
        v[k][0] = v[k][0] - alf;
        transp(v, vT);
        s = 0.0;
        for (int kk = 0; kk < m; kk++) s += v[kk][0] * v[0][kk];
        beta = s;
        if (beta > 1e-14) /* if beta =0 go to next k */ {
            for (int j = k; j < n; j++) {
                gam = 0.0;
                for (int jj = 0; jj < m; jj++) gam += v[jj][0] * a[jj][j];
                for (int jj = 0; jj < m; jj++)
                    a[jj][j] = a[jj][j]-(2 * gam / beta) * v[jj][0];
            }
        }
    }
}

void house_vec(Mat_DP &a, int col_idx, Vec_DP &w)
/* Returns as w for column col_idx the Householder
   vector v that  makes zero the subdiagonal entries
   of col_idx of a 
 */ {
    int m = a.nrows(), n = a.ncols();
    if ((m < 2) || (n < 2) || (m < n) || (col_idx >= n)) {
        cout << "Argument error in house_vec,m,n, col_idx="
                << m << ",  " << n << ", " << col_idx << endl;
        abort();
    }
    Mat_DP v(m, 1), vT(1, m), e(m, 1);
    DP alf, beta, gam;
    for (int k = col_idx; k <= col_idx; k++) {
        DP s = 0.0;
        v = 0.0;
        vT = 0.0;
        for (int kk = 0; kk < m; kk++) e[kk][0] = (kk == k) ? 1 : 0;
        for (int kk = k; kk < m; kk++) {
            s += a[kk][k] * a[kk][k];
            v[kk][0] = a[kk][k];
        }
        alf = (a[k][k] > 0) ? pow(s, 0.5) : -pow(s, 0.5);
        v[k][0] = v[k][0] - alf;
        //v=v-alf*e;    
        transp(v, vT);
        s = 0.0;
        for (int kk = 0; kk < m; kk++) s += v[kk][0] * v[0][kk];
        beta = s;
        if (beta > 1e-14) /* if beta =0 go to next k */ {
            for (int j = k; j < n; j++) {
                gam = 0.0;
                for (int jj = 0; jj < m; jj++) gam += v[jj][0] * a[jj][j];
                for (int jj = 0; jj < m; jj++)
                    a[jj][j] = a[jj][j]-(2 * gam / beta) * v[jj][0];
            }
        }
    }
    for (int i = 0; i < a.nrows(); i++) w[i] = v[i][0];
}

void Usolve(Mat_DP &a, Vec_DP &b, Vec_DP &sol)
/*
Usolve returns the solution x of U x=b for
an upper triangular matrix U
 */ {
    int m = a.nrows(), n = a.ncols();
    if ((m != n) || (m < 2)) {
        cout << "Argument error in Usolve,m,n="
                << m << ",  " << n << endl;
        abort();
    }
    Vec_DP z(m);
    DP s;
    for (int i = m - 1; i >= 0; i--) /* Solve U z = b */ {
        s = 0.0;
        for (int j = i + 1; j < m; j++) s += a[i][j] * z[j];
        if (fabs(a[i][i]) < 1e-16) {
            cout << "Division by zero in Usolve\n"
                    << endl;
            abort();
        }
        z[i] = (b[i] - s) / (a[i][i]);
    }
    sol = z;
}

void edit_matrix(Mat_DP &a) {
    int m = a.nrows(), n = a.ncols(), imx, jmx;
    DP amx;
    amx = fabs(a[0][0]);
    imx = 0;
    jmx = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (fabs(a[i][j]) > amx) {
                imx = i;
                jmx = j;
                amx = fabs(a[i][j]);
            }
        }
    amx = amx * 1e-14;
    if (amx < 1e-14) amx = 1e-14;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (fabs(a[i][j]) < amx) a[i][j] = 0.0;
}

void myHOUSEsolve(Mat_DP &a, Vec_DP &b, Vec_DP &sol)
/*   Solves a*x = b by the Householder method. 
   writing a = QR with orthog. Q and upper triangular R
   a will be overwritten.
 */ {
    int m = a.nrows(), n = a.ncols();
    if ((m < 2) || (n < 2) || (m < n) || (b.size() != m) || (sol.size() != n)) {
        cout << "Argument error in HOUSEsolve,m,n="
                << m << ",  " << n << endl;
        abort();
    }
    Vec_DP v(m), tmp(m);
    tmp = b;
    for (int i = 0; i < n; i++) {
        house_vec(a, i, v);
        DP beta = vnormp(v, 2.0);
        beta = beta*beta;
        if (beta > 1e-14) {
            DP gam = 0.0;
            for (int ii = 0; ii < m; ii++) {
                gam += v[ii] * tmp[ii];
            }
            gam = 2 * gam / beta;
            for (int ii = 0; ii < m; ii++)
                tmp[ii] = tmp[ii] - gam * v[ii];
        }
    }
    Mat_DP aa(n, n);
    Vec_DP rhs(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) aa[i][j] = a[i][j];
    for (int i = 0; i < n; i++) rhs[i] = tmp[i];
    Usolve(aa, rhs, sol);
}
