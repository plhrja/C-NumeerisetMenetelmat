#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "nr.h"
#include "mutils.h"
#include "matutl02.h"

using namespace std;

void GSsolve_iter(Mat_DP &a, Vec_DP &b, Vec_DP &x, Vec_DP &xold) {
    int i, j, rows = a.nrows();
    if ((rows != a.ncols()) || (rows != b.size()) ||
            (rows != x.size()) || (rows != xold.size())) {
        cout << "Argument error in GaussSeidel_iter\n" << endl;
        abort();
    }

    double s;
    for (i = 0; i < rows; i++) {
        s = 0;
        for (j = 0; j < rows; j++) {
            s += (j <= i - 1) ? a[i][j] * x[j] :
                    (j >= i + 1) ? a[i][j] * xold[j] : 0;
        }
        xold[i] = x[i];
        x[i] = (b[i] - s) / a[i][i];
    }
}

int main() {
    init_srand();
    double low = -50;
    double high = 50;
    double mul = 1.01;
    int iterCount = 50;
    int m = 10;

    Mat_DP A(m, m);
    Vec_DP b(m), xLU(m), xGS(m), xGSold(m);

    DDmatrix(A, mul, low, high);
    for (int i = 0; i < b.size(); i++) {
        b[i] = rdm(low, high);
        xGS[i] = 0;
        xGSold[i] = 0;
    }
    LUsolve(A, b, xLU);
    double residLU = residual(A, xLU, b);

    printf("n\tresid/GS\tresid/LU\n");
    for (int i = 1; i <= iterCount; i++) {

        GSsolve_iter(A, b, xGS, xGSold);
        double residGS = residual(A, xGS, b);

        if ((i % 5) == 0) {
            printf("%-8d%-16.3e%-15.3e\n", i, residGS, residLU);
        }
    }
}