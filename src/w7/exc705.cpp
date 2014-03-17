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

Vec_DP coeffs(3);

void solve_system(Vec_DP xdata, Vec_DP ydata, Vec_DP zdata){
    Mat_DP A(xdata.size(), 3);
    Vec_DP b(xdata.size());
    for (int i = 0; i < xdata.size(); i++) {
        double x = xdata[i];
        double y = ydata[i];
        
        A[i][0] = x;
        A[i][1] = y;
        A[i][2] = 1;
        b[i] = zdata[i];
    }
    SVDsolve(A, b, coeffs);
}

int main(){
    Mat_DP data = getmat("data/data705.mat");
    Vec_DP xdata(data.nrows()), ydata(data.nrows()), zdata(data.nrows());
    mutils::isolateCol(data, 0, xdata);
    mutils::isolateCol(data, 1, ydata);
    mutils::isolateCol(data, 2, zdata);
    
    solve_system(xdata, ydata, zdata);
    auto f = [](double x, double y) {return coeffs[0]*x + coeffs[1]*y + coeffs[2];};
    
    myplot::surf_data_set container;
    myplot::surf_data surface(".");
    myplot::surf_data points("+");
    
    myplot::generate_data(f, container, surface, -10, 10, -10, 10);
    for (int i = 0; i < xdata.size(); i++) {
        points.add_point(xdata[i], ydata[i], zdata[i]);
    }
    container.push_back(points);
    cout << "coeffs = " << coeffs << endl;
    myplot::surf(container, "Parameter fitting", true);
}
