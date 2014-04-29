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

double f(const Vec_DP &x) {
    return pow(x[0] - x[1], 2) + pow(1 - x[0], 2);
}

Vec_DP calculate_gradient(const Vec_DP &x) {
    Vec_DP grad(2);
    grad[0] = 4 * x[0] - 2 * (x[1] + 1);
    grad[1] = 2 * x[1] - 2 * x[0];
    return grad;
}

int main() {
    Vec_DP grad(2), xold(2), xnew(2), temp(2);
    double f_xnew;
    xnew[0] = 5;
    xnew[1] = -7;

    for (int i = 0; i < 50; i++) {
        xold = xnew;
        grad = calculate_gradient(xold);

        NR::linmin(xnew, grad, f_xnew, f);
        cout << "xnew = " << xnew << endl;

        if (abs(f_xnew - f(xold)) < 1e-8) {
            break;
        }
    }
}
