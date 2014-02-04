#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "plot.h"
#include "nr.h"
#include "mutils.h"
#include "matutl02.h"

using namespace std;

void generateData(Vec_DP& xdata, Vec_DP& ydata, Vec_DP& coeffs, double low, double high){
    for (int i = 0; i < coeffs.size(); i++) {
        coeffs[i] = rdm(low, high);
    }
    for (int i = 0; i < xdata.size(); i++) {
        ydata[i] = (coeffs[0]*pow(xdata[i],2) + coeffs[1]*xdata[i] + coeffs[2]) * rdm(0.8, 1.2);
    }
}

void construct_A(Mat_DP& A, Vec_DP& xdata){
    Vec_DP sums(4);
    for (int i = 0; i < sums.size(); i++) {
        sums[i] = 0;
    }
    for (int i = 0; i < xdata.size(); i++) {
        sums[0] += 2 * xdata[i]; 
        sums[1] += 2 * pow(xdata[i], 2); 
        sums[2] += 2 * pow(xdata[i], 3); 
        sums[3] += 2 * pow(xdata[i], 4); 
    }
    
    A[0][0] = sums[3];
    A[0][1] = sums[2];
    A[0][2] = sums[1];
    A[1][0] = sums[2];
    A[1][1] = sums[1];
    A[1][2] = sums[0];
    A[2][0] = sums[1];
    A[2][1] = sums[0];
    A[2][2] = 2 * xdata.size();
}

void construct_b(Vec_DP& b, Vec_DP& xdata, Vec_DP& ydata){
    Vec_DP sums(3);
    for (int i = 0; i < sums.size(); i++) {
        sums[i] = 0;
    }
    for (int i = 0; i < xdata.size(); i++) {
        sums[0] += 2 * ydata[i] * pow(xdata[i], 2); 
        sums[1] += 2 * ydata[i] * xdata[i]; 
        sums[2] += 2 * ydata[i]; 
    }
    
    b[0] = sums[0];
    b[1] = sums[1];
    b[2] = sums[2];
}

int main(){
    int n = 30;
    double start = -5;
    double end = 5;
    init_srand();
    
    Vec_DP xdata(n);
    Vec_DP ydata(n);
    Vec_DP fittedData(n);
    Vec_DP coeffs(3);
    Vec_DP sol(3);
    Vec_DP b(3);
    Mat_DP A(3,3);
    
    for (int i = 0; i < xdata.size(); i++) {
        xdata[i] = start + ((double) i * (end - start) / (xdata.size() - 1));
    }
    
    generateData(xdata, ydata, coeffs, 1, 5);
    construct_A(A, xdata);
    construct_b(b, xdata, ydata);
    LUsolve(A, b, sol);
    
    for (int i = 0; i < xdata.size(); i++) {
        fittedData[i] = sol[0]*pow(xdata[i],2) + sol[1]*xdata[i] + sol[2];
    }
    
    cout << endl << "Actual coefficients = " << coeffs << endl;
    cout << "Calculated through LSQ = " << sol << endl;
    
    //-------------------------------------------plotting-------------------------------------------
    
    const char* fpoints = "data/fpoints.dat";
    const char* datapoints = "data/datapoints.dat";
    
    generatePlottingData(xdata, fittedData, fpoints);
    generatePlottingData(xdata, ydata, datapoints);
    
    plot(fpoints, "r-2", datapoints, "k.", NULL);
}