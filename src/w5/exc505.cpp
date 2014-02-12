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

double normDiff(Mat_DP &A, Mat_DP &B){
    Mat_DP diff = A - B;
    return mnormp(diff, 2);
}

void printFail(const Mat_DP &A, const Mat_DP &B, double diff, int n, const char* Aname, const char* Bname){
    cout << "FAIL! (n = " << n << "),  |" << Aname << " - " << Bname << "| = " << diff << endl;
}

void printResults(int testCount, int fails){
    cout << "test count = " << testCount << endl;
    cout << "fails = " << fails << endl;
    cout << "ratio = " << ((double) fails / testCount) * 100 << "%" << endl << endl;
}

void testCaseA(int testCount, double low, double high){
    int fails = 0;
    int powers = 6;
    for (int n = 2; n <= pow(2, powers); n *= 2) {
        for (int i = 0; i < testCount; i++) {
            Mat_DP A(n, n + 1), pinvA(n + 1,n), pinvpinvA(n,n + 1);
            
            ranmat2(A, low, high);
            pseudoinv(A, pinvA);
            pseudoinv(pinvA, pinvpinvA);
            double diff = normDiff(A, pinvpinvA);
            
            if(diff > EPS){
                fails++;
                printFail(A, pinvpinvA, diff, n, "A", "A^++");
            }
        }
    }
    printResults(testCount * powers, fails);
}

void testCaseB(int testCount, double low, double high){
    int fails = 0;
    int powers = 6;
    for (int n = 2; n <= pow(2, powers); n *= 2) {
        for (int i = 0; i < testCount; i++) {
            Mat_DP A(n, n + 1), pinvA(n + 1,n), transpA(n + 1,n), pinvTranspA(n,n + 1), transpPinvA(n,n + 1);
            
            ranmat2(A, low, high);
            transp(A, transpA);
            pseudoinv(A, pinvA);
            transp(pinvA, transpPinvA);
            pseudoinv(transpA, pinvTranspA);
            double diff = normDiff(transpPinvA, pinvTranspA);
            
            if(diff > EPS){
                fails++;
                printFail(transpPinvA, pinvTranspA, diff, n, "(A^+)^T", "(A^T)^+");
            }
        }
    }
    printResults(testCount * powers, fails);
}

void testCaseC(int testCount, double low, double high){
    int fails = 0;
    int powers = 6;
    for (int n = 2; n <= pow(2, powers); n *= 2) {
        for (int i = 0; i < testCount; i++) {
            Mat_DP A(n, n + 1), B(n + 1,n), AB(n,n), pinvA(n + 1,n),
                    pinvB(n,n + 1), pinvAPinvB();
            
            ranmat2(A, low, high);
            double diff = normDiff(A, B);
            
            if(diff > EPS){
                fails++;
                printFail(A, B, diff, n, "(A^+)^T", "(A^T)^+");
            }
        }
    }
    printResults(testCount * powers, fails);
}

int main(){
    init_srand();
    int testCount = 100;
    int low = -100;
    int high = 100;
    
    cout << "Testing pseudoinverse of pseudoinverse" << endl;
    testCaseA(testCount, low, high);
    getchar();
    
    cout << "Testing transpose of pseudoinverse and pseudoinverse of transpose" << endl;
    testCaseB(testCount, low, high);
}
