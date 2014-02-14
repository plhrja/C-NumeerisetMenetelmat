#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "myplot.h"
#include "nr.h"
#include "mutils.h"
#include "matutl02.h"

using namespace std;

void constructData_A(Vec_DP &xdata, Vec_DP &ydata) {
    xdata[0] = 1;
    ydata[0] = 1;
    xdata[1] = 2;
    ydata[1] = 125;
    xdata[2] = 3;
    ydata[2] = 729;
    xdata[3] = 4;
    ydata[3] = 2197;
}

void constructData_B(Vec_DP &xdata, Vec_DP &ydata) {
    double ylow = -10;
    double yhigh = 10;
    for (int i = 0; i < xdata.size(); i++) {
        xdata[i] = i + 1;
        ydata[i] = rdm(ylow, yhigh);
    }
}

void interp(const Vec_DP &xdata, const Vec_DP &ydata,
        Vec_DP &interpx, Vec_DP &interpy, Vec_DP &error) {
    for (int i = 0; i < interpx.size(); i++) {
        double y, errory, x = 2 + i * 0.25;
        NR::polint(xdata, ydata, x, y, errory);
        interpx[i] = x;
        interpy[i] = y;
        error[i] = errory;
    }
}

void printResults(const Vec_DP &interpx, const Vec_DP &interpy, const Vec_DP &error){
    printf("x\tf(x)\terror\n");
    for (int i = 0; i < interpx.size(); i++) {
        printf("%-8.2f%-8.2f%-8.2f\n", interpx[i], interpy[i], error[i]);
    }
}

void plotInterp(const Vec_DP &xdata, const Vec_DP &ydata,
        const Vec_DP &interpx, const Vec_DP &interpy) {
    int pointnum = 100;
    double start = xdata[0];
    double end = xdata[xdata.size() - 1];

    myplot::data_set container;
    myplot::plot_data realPoints("k+2");
    myplot::plot_data interpPoints("r.");
    myplot::plot_data curve("c-2");
    for (int i = 0; i < pointnum; i++) {
        double x = start + ((double) i * (end - start)) / (pointnum - 1);
        double y, dy;
        NR::polint(xdata, ydata, x, y, dy);
        curve.add_point(x, y);
    }
    for (int i = 0; i < xdata.size(); i++) {
        realPoints.add_point(xdata[i], ydata[i]);
    }
    for (int i = 0; i < interpx.size(); i++) {
        interpPoints.add_point(interpx[i], interpy[i]);
    }
    container.push_back(curve);
    container.push_back(realPoints);
    container.push_back(interpPoints);
    myplot::plot(container);
}

int main() {
    init_srand();
    Vec_DP xdata(4), ydata(4), interpx(5), interpy(5), error(5);
    
    constructData_A(xdata, ydata);
    interp(xdata, ydata, interpx, interpy, error);
    printResults(interpx, interpy, error);
    plotInterp(xdata, ydata, interpx, interpy);
    
    constructData_B(xdata, ydata);
    interp(xdata, ydata, interpx, interpy, error);
    printResults(interpx, interpy, error);
    plotInterp(xdata, ydata, interpx, interpy);
}