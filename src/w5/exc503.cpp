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
        double x = 0.5 + (0.1 * (i + 1));
        xdata[i] = x;
        ydata[i] = tgamma(x);
    }
}

double get_max_error(const Vec_DP &error){
    double max = 0;
    for (int i = 0; i < error.size(); i++) {
        max = (error[i] > max) ? error[i] : max;
    }
    return max;
}

double interp_spline_natural(const Vec_DP &xdata, const Vec_DP &ydata,
        Vec_DP &interpx, Vec_DP &interpy, Vec_DP &error) {
    Vec_DP y2(xdata.size());
    NR::spline(xdata, ydata, INFINITY, INFINITY, y2);
    for (int i = 0; i < interpx.size(); i++) {
        double y, x = 0.6 + ((double) i * 1.9)/(interpx.size() - 1);
        NR::splint(xdata, ydata, y2, x, y);
        interpx[i] = x;
        interpy[i] = y;
        error[i] = abs(tgamma(x) - y);
    }
    return get_max_error(error);
}

void plotInterp(const Vec_DP &xdata, const Vec_DP &ydata,
        const Vec_DP &interpx, const Vec_DP &interpy) {
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
        real_curve.add_point(interpx[i], tgamma(interpx[i]));
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
    Vec_DP xdata(20), ydata(20), interpx(200), interpy(200), error(200);
    double max_error;
    construct_data(xdata, ydata);
    max_error = interp_spline_natural(xdata, ydata, interpx, interpy, error);
    cout << "max error in spline interpolation = " << max_error << endl;
    plotInterp(xdata, ydata, interpx, interpy);
}
