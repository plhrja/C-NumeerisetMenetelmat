#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "plot.h"
#include "nr.h"
#include "mutils.h"
#include "matutl02.h"

using namespace std;

void triu(Mat_DP* A, double low, double high) {
    ranmat2((*A), low, high);
    
    for (int j = 0; j < A->nrows(); j++) {
        for (int i = j + 1; i < A->ncols(); i++) {
            (*A)[i][j] = 0;
        }
    }
}

void trid(Mat_DP* A, double low, double high) {
    ranmat2((*A), low, high);
    
    for (int j = 0; j < A->nrows(); j++) {
        for (int i = j + 1; i < A->ncols(); i++) {
            (*A)[i][j] = (abs(i - j) > 1) ? 0 : (*A)[i][j];
        }
    }
}

bool isTriu(Mat_DP* A, double eps) {
    for (int j = 0; j < A->nrows(); j++) {
        for (int i = j + 1; i < A->ncols(); i++) {
            if (abs((*A)[i][j]) > eps) {
                cout << "n = " << A->nrows() << " element (" << i << "," << j << ") = " << (*A)[i][j] << endl;
                return false;
            }
        }
        return true;
    }
}

bool isTrid(Mat_DP* A, double eps) {
    for (int j = 0; j < A->nrows(); j++) {
        for (int i = j + 1; i < A->ncols(); i++) {
            if (abs(i - j) > 1) {
                if (abs((*A)[i][j]) > eps) {
                    cout << "n = " << A->nrows() << " element (" << i << "," << j << ") = " << (*A)[i][j] << endl;
                    return false;
                }
            }
        }
        return true;
    }
}

void testInv(void (*con)(Mat_DP*, double, double), bool (*pred)(Mat_DP*, double), double eps, double min, double max) {
    int fails = 0;
    int power = 5;
    int tests = 300;
    for (int n = 4; n <= pow(2, power); n *= 2) {
        for (int i = 0; i < tests; i++) {
            Mat_DP A(n, n);
            Mat_DP invA(n, n);

            (*con)(&A, min, max);
            invmat(A, invA);

            if (!(*pred)(&invA, eps)) {
                fails++;
            }
        }
    }
    power--;
    cout << "Testcount = " << power * tests << endl;
    cout << "Fails = " << fails << endl;
    cout << "ratio = " << (double) fails / (power * tests) * 100 << "%" << endl;
}

void testProd(void (*con)(Mat_DP*, double, double), bool (*pred)(Mat_DP*, double), double eps, double min, double max) {
    int fails = 0;
    int power = 5;
    int tests = 300;
    for (int n = 4; n <= pow(2, power); n *= 2) {
        for (int i = 0; i < tests; i++) {
            Mat_DP A(n, n);
            Mat_DP B(n, n);
            Mat_DP AB(n, n);

            (*con)(&A, min, max);
            (*con)(&B, min, max);
            AB = A * B;

            if (!(*pred)(&AB, eps)) {
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
    testInv(triu, isTriu, 1e-8, -100, 100);
    getchar();

    cout << "Testing product of two upper triangle matrices:" << endl;
    testProd(triu, isTriu, 1e-8, -100, 100);
    getchar();
    
    cout << "Testing inverse of tridiagonal matrices:" << endl;
    testInv(trid, isTrid, 1e-8, -0.01, 0.01);
    getchar();

    cout << "Testing product of two tridiagonal matrices:" << endl;
    testProd(trid, isTrid, 1e-8, -100, 100);
}
