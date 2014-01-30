#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "plot.h"
#include "nr.h"
#include "mutils.h"
#include "matutl02.h"

using namespace std;

void DD(Mat_DP* A, double mul, double low, double high) {
    ranmat2((*A), low, high);
    mul = (mul < 1) ? 1.1 : mul;

    for (int i = 0; i < A->nrows(); i++) {
        double sum = 0;

        for (int j = 0; j < A->ncols(); j++) {
            sum += (i != j) ? abs((*A)[i][j]) : 0;
        }
        (*A)[i][i] = sum * mul;
    }
}

bool isDD(Mat_DP* A) {
    for (int i = 0; i < A->nrows(); i++) {
        double sum = 0;

        for (int j = 0; j < A->ncols(); j++) {
            sum += (i != j) ? abs((*A)[i][j]) : 0;
        }
        if (sum > (*A)[i][i]) {
            cout << "FAIL! n = " << A->nrows() << ", A(" << i << "," << i;
            cout << ") - sum = " << (*A)[i][i] - sum << endl;
            return false;

        }
    }
    return true;
}

void testInv(int n, int testCount, double mul, double low, double high) {
    int fails = 0;
    for (int i = 0; i < testCount; i++) {
        Mat_DP A(n, n);
        Mat_DP invA(n, n);

        DD(&A, rdm(1, mul), low, high);
        invmat(A, invA);

        if (!isDD(&invA)) {
            fails++;
        }
    }
    cout << endl << "n = " << n << endl;
    cout << "test count = " << testCount << endl;
    cout << "fails = " << fails << endl;
    cout << "ratio = " << ((double) fails / testCount) * 100 << "%" << endl << endl;
}

void testProd(int n, int testCount, double mul, double low, double high) {
    int fails = 0;
    for (int i = 0; i < testCount; i++) {
        Mat_DP A(n, n);
        Mat_DP B(n, n);
        Mat_DP AB(n, n);
        
        DD(&A, rdm(1, mul), low, high);
        DD(&B, rdm(1, mul), low, high);
        AB = A * B;

        if (!isDD(&AB)) {
            fails++;
        }
    }
    cout << endl << "n = " << n << endl;
    cout << "test count = " << testCount << endl;
    cout << "fails = " << fails << endl;
    cout << "ratio = " << ((double) fails / testCount) * 100 << "%" << endl << endl;
}

int main() {
    int testCount = 150;
    double low = -100;
    double high = 100;
    double mul = 10;
    
    cout.precision(3);
    init_srand();
    
    cout << "Testing inverse of DD-matrices:" << endl << endl;
    for (int n = 2; n <= pow(2, 6); n *= 2) {
        testInv(n, testCount, mul, low, high);
        getchar();
    }
    
    cout << "Testing product of two DD-matrices:" << endl << endl;
    for (int n = 2; n <= pow(2, 6); n *= 2) {
        testProd(n, testCount, mul, low, high);
        getchar();
    }
}
