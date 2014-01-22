#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "plot.h"
#include "nr.h"
#include "mutils.cpp"
#include "matutl02.h"

using namespace std;

void MC(double (*f1)(double), double (*f2)(double), int n, double xmin, double xmax, double ymin, double ymax){
    vector<double> hitx;
    vector<double> hity;
    vector<double> missx;
    vector<double> missy;
    
    for (int i = 0; i < n; i++) {
        double x = rdm(xmin, xmax);
        double y = rdm(ymin,ymax);
        if(y < max((*f1)(x), (*f2)(x)) && y > min((*f1)(x), (*f2)(x))){
            hitx.push_back(x);
            hity.push_back(y);
        } else {
            missx.push_back(x);
            missy.push_back(y);
        }
    }
    
    double area = ((double) hitx.size()/n) * (xmax - xmin) * (ymax - ymin);
    cout << "MC integration result = " << area << endl;
    
    //-----------------------------------------plotting-----------------------------------------
    
    const char* hitPoints = "data/hp.mat";
    const char* missPoints = "data/mp.mat";
    const char* f1Points = "data/f1.mat";
    const char* f2Points = "data/f2.mat";
    vector<double> f1x;
    vector<double> f2x;
    vector<double> f1y;
    vector<double> f2y;
    
    int m = 200;
    for (int i = 0; i < m; i++) {
        double xx = i * ((2 * M_PI)/(m - 1));
        f1x.push_back(xx);
        f2x.push_back(xx);
        f1y.push_back((*f1)(xx));
        f2y.push_back((*f2)(xx));
    }

    generatePlottingData(hitx, hity, hitPoints);
    generatePlottingData(missx, missy, missPoints);
    generatePlottingData(f1x, f1y, f1Points);
    generatePlottingData(f2x, f2y, f2Points);
    
    plot(hitPoints, "b.", missPoints, "r.", f1Points, "k-5", f2Points, "k-5", NULL);
    
}

int main(){
    
    MC(&sin, &cos, 5000, 0, 2 * M_PI, -1, 1);
    
}

