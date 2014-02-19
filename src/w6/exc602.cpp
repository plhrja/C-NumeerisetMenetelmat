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

    myplot::data_set container();
    myplot::plot_data line1("-");
    myplot::plot_data line2("-");
    myplot::plot_data line3("-");
    myplot::plot_data point("+");
    int start = -1;
    int end = 1;
    int points = 100;
    for (int i = 0; i < points; i++) {
        double x = start + ((double) i * (end - start)) / (points - 1);
        for (int j = 0; j < points; j++) {
            double y = start + ((double) j * (end - start)) / (points - 1);
        }
    }
}