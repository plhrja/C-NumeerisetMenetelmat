#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "myplot.h"
#include "nr.h"
#include "mutils.h"
#include "matutl02.h"

using namespace std;

void construct_data(Vec_DP &xdata, Vec_DP &ydata){
    for (int i = 0; i < xdata.size(); i++) {
        double x = i * (M_PI / 10);
        xdata[i] = x;
        ydata[i] = sin(x);
    }
}

double get_max_error(const Vec_DP &error){
    double max = 0;
    for (int i = 0; i < error.size(); i++) {
        max = (error[i] > max) ? error[i] : max;
    }
    return max;
}

double interp_polint(const Vec_DP &xdata, const Vec_DP &ydata,
        Vec_DP &interpx, Vec_DP &interpy, Vec_DP &error) {
    for (int i = 0; i < interpx.size(); i++) {
        double y, errory, x = i * (M_PI / 200);
        NR::polint(xdata, ydata, x, y, errory);
        interpx[i] = x;
        interpy[i] = y;
        error[i] = abs(sin(x) - y);
    }
    return get_max_error(error);
}

double interp_spline_periodic(const Vec_DP &xdata, const Vec_DP &ydata, double deriv,
        Vec_DP &interpx, Vec_DP &interpy, Vec_DP &error) {
    Vec_DP y2(xdata.size());
    NR::spline(xdata, ydata, deriv, deriv, y2);
    for (int i = 0; i < interpx.size(); i++) {
        double y, x = i * (M_PI / 200);
        NR::splint(xdata, ydata, y2, x, y);
        interpx[i] = x;
        interpy[i] = y;
        error[i] = abs(sin(x) - y);
    }
    return get_max_error(error);
}

double interp_spline_natural(const Vec_DP &xdata, const Vec_DP &ydata,
        Vec_DP &interpx, Vec_DP &interpy, Vec_DP &error) {
    return interp_spline_periodic(xdata, ydata, INFINITY, interpx, interpy, error);
}

void plotInterp(const Vec_DP &xdata, const Vec_DP &ydata,
        const Vec_DP &interpx, const Vec_DP &interpy) {
    int pointnum = 100;
    double start = xdata[0];
    double end = xdata[xdata.size() - 1];

    myplot::data_set container;
    myplot::plot_data realPoints("k+2");
    myplot::plot_data interp_curve("c");
    myplot::plot_data real_curve("b");
    for (int i = 0; i < interpx.size(); i++) {
        interp_curve.add_point(interpx[i], interpy[i]);
    }
    for (int i = 0; i < interpx.size(); i++) {
        real_curve.add_point(interpx[i], sin(interpx[i]));
    }
    for (int i = 0; i < xdata.size(); i++) {
        realPoints.add_point(xdata[i], ydata[i]);
    }
    container.push_back(real_curve);
    container.push_back(interp_curve);
    container.push_back(realPoints);
    myplot::plot(container);
}

int main(){
    init_srand();
    Vec_DP xdata(6), ydata(6), interpx(101), interpy(101), error(101);
    double max_error;
    construct_data(xdata, ydata);
    
    max_error = interp_polint(xdata, ydata, interpx, interpy, error);
    cout << "max error in polynomial interpolation = " << max_error << endl;
    plotInterp(xdata, ydata, interpx, interpy);
    
    double deriv = 15;
    max_error = interp_spline_periodic(xdata, ydata, deriv, interpx, interpy, error);
    cout << "max error in periodic spline interpolation (period = " << deriv << ") = " << max_error << endl;
    plotInterp(xdata, ydata, interpx, interpy);
    
    max_error = interp_spline_natural(xdata, ydata, interpx, interpy, error);
    cout << "max error in natural spline interpolation = " << max_error << endl;
    plotInterp(xdata, ydata, interpx, interpy);
    
}
