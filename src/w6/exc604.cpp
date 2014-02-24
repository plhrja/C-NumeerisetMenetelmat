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

Vec_DP coeffs(5);

double f(double x){
    double a = coeffs[0];
    double b = coeffs[1]*x + coeffs[3];
    double c = coeffs[2]*x + coeffs[4] - pow(x, 2);
    double disk = pow(b, 2) - (4*a*c);
    return (-b + sqrt(disk))/(2*a);
}

void solve_system(Vec_DP xdata, Vec_DP ydata){
    Mat_DP A(xdata.size(), 5);
    Vec_DP b(xdata.size());
    for (int i = 0; i < xdata.size(); i++) {
        double x = xdata[i];
        double y = ydata[i];
        
        A[i][0] = pow(y, 2);
        A[i][1] = x * y;
        A[i][2] = x;
        A[i][3] = y;
        A[i][4] = 1;
        b[i] = pow(x, 2);
    }
    SVDsolve(A, b, coeffs);
}

int main(){
    Mat_DP data = getmat("data/comet_data.mat");
    Vec_DP xdata(data.nrows()), ydata(data.nrows());
    mutils::isolateCol(data, 0, xdata);
    mutils::isolateCol(data, 1, ydata);
    
    solve_system(xdata, ydata);
    
    myplot::data_set container;
    myplot::plot_data function("b-2");
    myplot::plot_data points("k+2");
    
    myplot::generate_data(f, container, function, -0.2, 1.1, 100);
    for (int i = 0; i < xdata.size(); i++) {
        points.add_point(xdata[i], ydata[i]);
    }
    container.push_back(points);
    cout << "coeffs = " << coeffs << endl;
    plot(container);
}
