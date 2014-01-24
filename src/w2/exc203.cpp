#include <cstdio>
#include <cstdlib>
#include <cmath>
#include "nr.h"
#include "mutils.h"
#include "matutl02.h"

using namespace std;

void constructBigMatrix(Mat_DP* AB, Mat_DP* P, Mat_DP* R) {
    int n = AB->nrows();
    int m = AB->ncols();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            (*AB)[i][j] = (i < n/2 && j < m/2) ? (*P)[i][j] :
                    (i >= n/2 && j >= m/2) ? (*R)[i - n/2][j - m/2] : 0;
        }
    }
}

void testTheorem() {

    int min = -100;
    int max = 100;
    for (int n = 2; n <= pow(2,7); n *= 2) {
        Mat_DP P(n, n);
        Mat_DP invP(n, n);
        Mat_DP R(n, n);
        Mat_DP invR(n, n);
        Mat_DP A(2 * n, 2 * n);
        Mat_DP invA(2 * n, 2 * n);
        Mat_DP B(2 * n, 2 * n);
        Mat_DP errorMatrix(2 * n, 2 * n);

        init_srand();
        ranmat2(P, min, max);
        invmat(P, invP);
        ranmat2(R, min, max);
        invmat(R, invR);

        constructBigMatrix(&A, &P, &R);
        constructBigMatrix(&B, &invP, &invR);

        invmat(A, invA);
        errorMatrix = invA - B;
        double norm = mnormp(errorMatrix, 2);
        
//        if(n == 4){
//            showmat(errorMatrix);
//            showmat(invA);
//            showmat(B);
//        }

        cout.precision(6);
        cout << "n = " << n << endl;
        cout << "|A^(-1) - B| = " << norm << endl << endl;
    }

}

int main() {

    testTheorem();

}