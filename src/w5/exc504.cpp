#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "myplot.h"
#include "nr.h"
#include "numdiff.h"
#include "mutils.h"
#include "matutl02.h"

using namespace std;

void der2(double (*f)(double), const Vec_DP &xpoints, Vec_DP &dders, double a, double b) {
    double h = 1e-05;
    a -= 4 * h;
    b += 4 * h;
    for (int i = 0; i < xpoints.size(); i++) {
        dders[i] = numdf(f, a, b, xpoints[i], h, 2);
    }
}

void plot_two(const Vec_DP &xdata1, const Vec_DP &ydata1,
        const Vec_DP &xdata2, const Vec_DP &ydata2) {
    myplot::data_set container;
    myplot::plot_data line1("b-2");
    myplot::plot_data line2("r-2");
    for (int i = 0; i < xdata1.size(); i++) {
        line1.add_point(xdata1[i], ydata1[i]);
    }
    for (int i = 0; i < xdata2.size(); i++) {
        line2.add_point(xdata2[i], ydata2[i]);
    }
    container.push_back(line1);
    container.push_back(line2);
    plot(container);
}

int main() {
//    double a = -2;
//    double b = 2;
//    double(*f)(double)  = [](double x){return pow(x, 2);};
    double a = 0;
    double b = 4 * M_PI;
    double(*f)(double) = &sin;
    int pointnum = 1000;
    Vec_DP xpoints(pointnum), fpoints(pointnum), sumpoints(pointnum), dders(pointnum);
    
    for (int i = 0; i < pointnum; i++) {
        double x = a + ((double) i * (b - a))/(pointnum - 1);
        xpoints[i] = x;
        fpoints[i] = f(x);
    }
    der2(f, xpoints, dders, a, b);
    plot_two(xpoints, fpoints, xpoints, dders);
    
    for (int i = 0; i < pointnum; i++) {
        sumpoints[i] = fpoints[i] + dders[i];
    }
    
    myplot::data_set container;
    myplot::plot_data curve("b-2");
    for (int i = 0; i < pointnum; i++) {
        curve.add_point(xpoints[i], sumpoints[i]);
    }
    container.push_back(curve);
    plot(container);
}