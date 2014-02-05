#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "plot.h"
#include "nr.h"
#include "solve.h"
#include "mutils.h"
#include "matutl02.h"

using namespace std;

void constructCoeffs(Vec_DP& c, Vec_DP& d){
    c[0] = -0.4; d[0] = 0.5;
    c[1] = 0.6;  d[1] = 0.0;
    c[2] = -1.3; d[2] = 1.2;
    c[3] = 2.0;  d[3] = -0.8;
}

void constructSystem(Mat_DP& A, Vec_DP& b, Vec_DP& c, Vec_DP& d, int n){
    for (int i = 0; i < n; i++) {
        A[i][0] = c[i]; 
        A[i][1] = -1;
        b[i] = -d[i];
    }
}

void plotLines(Vec_DP& c, Vec_DP& d, Vec_DP& x, int n){
    int start = 0;
    int end = 1;
    int points = 100;
    Vec_DP x1(1), x2(1), xdata(points);
    x1[0] = x[0];
    x2[0] = x[1];
    for (int i = 0; i < xdata.size(); i++) {
        xdata[i] = start + ((double) i * (end - start)/(xdata.size() - 1));
    }
       
    const char* fpoints0 = "data/fpoints0.dat";
    const char* fpoints1 = "data/fpoints1.dat";
    const char* fpoints2 = "data/fpoints2.dat";
    const char* fpoints3 = "data/fpoints3.dat";
    const char* xpoints = "data/xpoints";
    
    generatePlottingData(x1, x2, xpoints);
    for (int i = 0; i < n; i++) {
        stringstream sstr;
        string str;
        const char* fname;
        Vec_DP ydata(points);
        
        sstr << "data/fpoints" << i << ".dat";
        str = sstr.str();
        fname = str.c_str();
        
        for (int k = 0; k < ydata.size(); k++) {
            ydata[k] = c[i] * xdata[k] + d[i];
        }
        generatePlottingData(xdata, ydata, fname);
    }
    
    switch(n){
        case 2: plot(fpoints0, "c-2", fpoints1, "c-2", xpoints, "k.3", NULL); break;
        case 3: plot(fpoints0, "c-2", fpoints1, "c-2",
                fpoints2, "c-2", xpoints, "k.3", NULL); break;
        case 4: plot(fpoints0, "c-2", fpoints1, "c-2",
                fpoints2, "c-2", fpoints3, "c-2", xpoints, "k.3", NULL); break;
    }
}

int main(){
    
    Vec_DP c(4), d(4);
    constructCoeffs(c, d);
    
    for (int n = 2; n <= 4; n++) {
        Mat_DP A(n,2);
        Vec_DP b(n), x(2);
        
        constructSystem(A, b, c, d, n);
        
        SVDsolve(A, b, x);
        
        cout << "Number of lines = " << n << endl;
        cout << "Ship located at (" << x[0] << "," << x[1] << ")" << endl << endl;
        plotLines(c, d, x, n);
    }
}