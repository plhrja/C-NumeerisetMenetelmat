#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "plot.h"
#include "nr.h"
#include "mutils.cpp"
#include "matutl02.h"

using namespace std;

void triulize(Mat_DP* A) {
    for (int j = 0; j < A->nrows(); j++) {
        for (int i = j + 1; i < A->ncols(); i++) {
            (*A)[i][j] = 0;
        }
    }
}

void triu(Mat_DP* A, double low, double high) {
    ranmat2((*A), low, high);
    triulize(A);
}

void tridlize(Mat_DP* A) {
    for (int j = 0; j < A->nrows(); j++) {
        for (int i = j + 1; i < A->ncols(); i++) {
            (*A)[i][j] = (abs(i - j) > 1) ? 0 : (*A)[i][j];
        }
    }
}

void trid(Mat_DP* A, double low, double high) {
    ranmat2((*A), low, high);
    tridlize(A);
}

int isTriu(Mat_DP* A, double eps) {
    for (int j = 0; j < A->nrows(); j++) {
        for (int i = j + 1; i < A->ncols(); i++) {
            if (abs((*A)[i][j]) > eps) {
                cout << "n = " << A->nrows() << " element (" << i << "," << j << ") = " << (*A)[i][j] << endl;
                return 0;
            }
        }
        return 1;
    }
}

int isTrid(Mat_DP* A, double eps) {
    for (int j = 0; j < A->nrows(); j++) {
        for (int i = j + 1; i < A->ncols(); i++) {
            if (abs(i - j) > 1) {
                if (abs((*A)[i][j]) > eps) {
                    cout << "n = " << A->nrows() << " element (" << i << "," << j << ") = " << (*A)[i][j] << endl;
                    return 0;
                }
            }
        }
        return 1;
    }
}

void testTriuInv() {
    double min = -100;
    double max = 100;
    int fails = 0;
    int power = 5;
    int tests = 300;
    double eps = 1e-8;
    for (int n = 2; n <= pow(2, power); n *= 2) {
        for (int i = 0; i < tests; i++) {
            Mat_DP A(n, n);
            Mat_DP invA(n, n);

            triu(&A, min, max);
            invmat(A, invA);

            if (!isTriu(&invA, eps)) {
                fails++;
            }
        }
    }
    cout << "Testcount = " << power * tests << endl;
    cout << "Fails = " << fails << endl;

    cout << "ratio = " << (double) fails / (power * tests) * 100 << "%" << endl;
}

void testTriuProd() {
    double min = -100;
    double max = 100;
    int fails = 0;
    int power = 5;
    int tests = 300;
    double eps = 1e-8;
    for (int n = 2; n <= pow(2, power); n *= 2) {
        for (int i = 0; i < tests; i++) {
            Mat_DP A(n, n);
            Mat_DP B(n, n);
            Mat_DP AB(n, n);

            triu(&A, min, max);
            triu(&B, min, max);
            AB = A * B;

            if (!isTriu(&AB, eps)) {
                fails++;
            }
        }
    }
    cout << "Testcount = " << power * tests << endl;
    cout << "Fails = " << fails << endl;
    cout << "ratio = " << (double) fails / (power * tests) * 100 << "%" << endl;
}

void testTridInv() {
    double min = -100;
    double max = 100;
    int fails = 0;
    int power = 5;
    int tests = 300;
    double eps = 1e-8;
    for (int n = 4; n <= pow(2, power); n *= 2) {
        for (int i = 0; i < tests; i++) {
            Mat_DP A(n, n);
            Mat_DP invA(n, n);

            trid(&A, min, max);
            invmat(A, invA);

            if (!isTrid(&invA, eps)) {
                fails++;
            }
        }
    }
    power--;
    cout << "Testcount = " << power * tests << endl;
    cout << "Fails = " << fails << endl;
    cout << "ratio = " << (double) fails / (power * tests) * 100 << "%" << endl;
}

void testTridProd() {
    double min = -100;
    double max = 100;
    int fails = 0;
    int power = 5;
    int tests = 300;
    double eps = 1e-8;
    for (int n = 4; n <= pow(2, power); n *= 2) {
        for (int i = 0; i < tests; i++) {
            Mat_DP A(n, n);
            Mat_DP B(n, n);
            Mat_DP AB(n, n);

            trid(&A, min, max);
            trid(&B, min, max);
            AB = A * B;

            if (!isTrid(&AB, eps)) {
                fails++;
            }
        }
    }
    
    power--;
    cout << "Testcount = " << power * tests << endl;
    cout << "Fails = " << fails << endl;
    cout << "ratio = " << (double) fails / (power * tests) * 100 << "%" << endl;
}

int main() {
    init_srand();
    cout.precision(3);
    
    cout << "Testing inverse of upper triangle matrices:" << endl;
    testTriuInv();
    getchar();

    cout << "Testing product of two upper triangle matrices:" << endl;
    testTriuInv();
    getchar();
    
    cout << "Testing inverse of tridiagonal matrices:" << endl;
    testTridInv();
    getchar();

    cout << "Testing product of two tridiagonal matrices:" << endl;
    testTridProd();
}
