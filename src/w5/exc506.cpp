#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "myplot.h"
#include "nr.h"
#include "solve.h"
#include "mutils.h"
#include "matutl02.h"

using namespace std;

void constructData(Vec_DP &xdata, Vec_DP &ydata){
    xdata[0] = 1; ydata[0] = 2;
    xdata[1] = 2; ydata[1] = 2;
    xdata[2] = 3; ydata[2] = 3;
    xdata[3] = 3; ydata[3] = 5;
    xdata[4] = 4; ydata[4] = 6;
}

void plotFitted(const Vec_DP &xdata, const Vec_DP &ydata, const Vec_DP &coeffs){
    int start = 0;
    int end = 7;
    int pointnum = 100;
    myplot::data_set dataContainer;
    myplot::plot_data poly("c-2");
    myplot::plot_data points("k.2");
    
    for (int i = 0; i < pointnum; i++) {
        double x = start + ((double) i * (end - start) / (pointnum - 1)); 
        poly.add_point(x, coeffs[0]*pow(x,2) + coeffs[1]*x + coeffs[2]);
    }
    for (int i = 0; i < xdata.size(); i++) {
        points.add_point(xdata[i], ydata[i]);
    }
    
    dataContainer.push_back(poly);
    dataContainer.push_back(points);
    plot(dataContainer);
}

int main(){
    Vec_DP coeffs1(3), coeffs2(3), xdata(5), ydata(5);
    constructData(xdata, ydata);
    
    mutils::polyfit_SVD(xdata, ydata, coeffs1, 2);
    cout << "Coeffs obtained through SVD = " << coeffs1 << endl;
    plotFitted(xdata, ydata, coeffs1);
    
    mutils::polyfit_HOUSE(xdata, ydata, coeffs2, 2);
    cout << "Coeffs obtained through HOUSE = " << coeffs2 << endl;
    plotFitted(xdata, ydata, coeffs2);
}
