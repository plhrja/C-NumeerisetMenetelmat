#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <solve.h>
#include "nr.h"
#include "mutils.h"
#include "matutl02.h"

#define EPS 1e-9

using namespace std;

double normDiff(Mat_DP &A, Mat_DP &B) {
    Mat_DP diff = A - B;
    return mnormp(diff, 2);
}

void printFail(double diff, int n, int m, const char* Aname, const char* Bname) {
    cout << "FAIL! (n = " << n << "," << m << "),  |"
            << Aname << " - " << Bname << "| = " << diff << endl;
}

void printResults(int testCount, int fails) {
    cout << "test count = " << testCount << endl;
    cout << "fails = " << fails << endl;
    cout << "ratio = " << ((double) fails / testCount) * 100 << "%" << endl << endl;
}

void testCaseA(int testCount, double low, double high) {
    int fails = 0;
    int counter = 0;
    int powers = 6;
    for (int n = 2; n <= pow(2, powers); n *= 2) {
        for (int m = n; m <= pow(2, powers); m *= 2) {
            for (int i = 0; i < testCount; i++) {
                counter++;
                Mat_DP A(m, n), pinvA(n, m), pinvpinvA(m, n);

                ranmat2(A, low, high);
                pseudoinv(A, pinvA);
                pseudoinv(pinvA, pinvpinvA);
                double diff = normDiff(A, pinvpinvA);

                if (diff > EPS) {
                    fails++;
                    printFail(diff, n, m, "A", "A^++");
                }
            }
        }
    }
    printResults(counter, fails);
}

void testCaseB(int testCount, double low, double high) {
    int fails = 0;
    int counter = 0;
    int powers = 5;
    for (int n = 2; n <= pow(2, powers); n *= 2) {
        for (int m = n; m <= pow(2, powers); m *= 2) {
            for (int i = 0; i < testCount; i++) {
                counter++;
                Mat_DP A(m, n), pinvA(n, m), transpA(n, m), pinvTranspA(m, n), transpPinvA(m, n);

                ranmat2(A, low, high);
                transp(A, transpA);
                pseudoinv(A, pinvA);
                transp(pinvA, transpPinvA);
                pseudoinv(transpA, pinvTranspA);
                double diff = normDiff(transpPinvA, pinvTranspA);

                if (diff > EPS) {
                    fails++;
                    printFail(diff, n, m, "(A^+)^T", "(A^T)^+");
                }
            }
        }
    }
    printResults(counter, fails);
}

void testCaseC(int testCount, double low, double high) {
    int fails = 0;
    int counter = 0;
    int powers = 5;
    for (int n = 2; n <= pow(2, powers); n *= 2) {
        for (int m = n; m <= pow(2, powers); m *= 2) {
            for (int i = 0; i < testCount; i++) {
                counter++;
                int p = rdm(1, m + n);
                Mat_DP A(m, n), B(n, p), AB(m, p), pinvAB(p, m),
                        pinvA(n, m), pinvB(p, n ), pinvBPinvA(p, m);

                ranmat2(A, low, high);
                ranmat2(B, low, high);
                pseudoinv(A, pinvA);
                pseudoinv(B, pinvB);
                AB = A * B;
                pseudoinv(AB, pinvAB);
                pinvBPinvA = pinvB * pinvA;
                double diff = normDiff(pinvAB, pinvBPinvA);
                if (diff > EPS) {
                    fails++;
                    printFail(diff, n, m, "(AB)^+", "B^+A^+");
                }
            }
        }
    }
    printResults(counter, fails);
}

int main() {
    init_srand();
    int testCount = 50;
    int low = -100;
    int high = 100;

    cout << "1st case" << endl;
    testCaseA(testCount, low, high);
    getchar();

    cout << "2nd case" << endl;
    testCaseB(testCount, low, high);
    getchar();

    cout << "3rd case" << endl;
    testCaseC(testCount, low, high);
}
