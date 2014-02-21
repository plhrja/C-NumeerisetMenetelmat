#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "nr.h"
#include "solve.h"
#include "myplot.h"
#include "mutils.h"
#include "matutl02.h"

using namespace std;

void pinv_solve(Mat_DP &A, Vec_DP &x, Vec_DP &b) {
    Mat_DP pinvA(A.ncols(), A.nrows());
    pseudoinv(A, pinvA);
    matvecmul(pinvA, b, x);
}

int main() {
    Mat_DP A1(3, 3), A2(3, 3);
    Vec_DP b(3), x1(3), x2(3);

    ones(A1);
    for (int i = 0; i < A2.nrows(); i++) {
        for (int j = 0; j < A2.ncols(); j++) {
            A2[i][j] = 3 * i + j + 1;
        }
    }

    for (int i = 0; i < b.size(); i++) {
        b[i] = i + 1;
    }


    pinv_solve(A1, x1, b);
    cout << "x1 = " << x1 << endl;

    pinv_solve(A2, x2, b);
    cout << "x2 = " << x2 << endl;
}