#include <cstdio>
#include <cstdlib>
#include <complex>
#include <cmath>
#include <vector>
#include "plot.h"
#include "nr.h"
#include "mutils.h"
#include "matutl02.h"
#include "myeigen.cpp"

bool testSum(Mat_DP* A, Vec_CPLX_DP* eigens, double tol) {
    std::complex<double> sumOfDiag = 0;
    std::complex<double> sumOfEigens = 0;
    for (int i = 0; i < A->nrows(); i++) {
        sumOfDiag += (*A)[i][i];
        sumOfEigens += (*eigens)[i];
    }
    return (abs(sumOfDiag - sumOfEigens) > tol);
}

bool testDet(Mat_DP* A, Vec_CPLX_DP* eigens, double tol) {
    std::complex<double> prodOfEigens = 0;
    for (int i = 0; i < A->nrows(); i++) {
        prodOfEigens *= (*eigens)[i];
    }
    double det = detmat((*A));
    return (abs(det - prodOfEigens) > tol);
}

int main() {
    int testCount = 1;
    int p = 1;
    int low = -10;
    int high = 10;
    int fails = 0;
    double eps = 1e-8;
    for (int n = 2; n <= pow(2, p); n *= 2) {
        for (int i = 0; i < testCount; i++) {
            Mat_DP A(n, n);
            Vec_CPLX_DP eigens(n);

            ranmat2(A, low, high);
            eigen(A, eigens);

            if(testSum(&A, &eigens, eps)){
                fails++;
                cout << "FAIL! n = " << n << endl;
            }

        }
    }
}

