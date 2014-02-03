#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "plot.h"
#include "nr.h"
#include "mutils.h"
#include "matutl02.h"

using namespace std;

double polyf(double x, vector<double>* consts){
    double sum = 0;
    int n = consts->size();
    for (int i = 0; i <= n; i++) {
        sum += (*consts)[i] * pow(x, i);
    }
    return sum;
}

double integPolyf(double a, double b, vector<double>* consts){
    double sum = 0;
    int n = consts->size();
    for (int i = 1; i <= n; i++) {
        sum += (double) (*consts)[i - 1] * (pow(b, i) - pow(a, i)) / i;
    }
    return sum;
}

double numIntegPolyf(double a, double b, int n, vector<double>* consts){
    double h = (double) (b - a) / n;
    double sum = 0;
    for (int k = 0; k <= n; k++) {
        double x_k = a + k*h; 
        sum += (*polyf)(x_k, consts);
    }
    return h * sum - ((h/2) * (polyf(a, consts) + polyf(b, consts)));
}

int main(){
    vector<double> consts(5);
    double low = -10;
    double high = 10;
    init_srand();
    
    cout << "\nf(x) = ";
    for (int i = 4; i > -1; i--) {
        consts[i] = rdm(low, high);
        
        string sign = (consts[i] < 0) ? " - " : (i != 4) ? " + " : "";
        string var = (4 - i > 1) ? "x^" : (4 - i == 1) ? "x" : "";
        string exp = (4 - i > 1) ? to_string(4 - i) : "";
        cout << sign << abs(consts[i]) << var << exp;
    }
    cout << endl << endl;
    
    double a = -2;
    double b = 2;
    int testCount = 6;
    
    printf("n\t\tI(a,b,n)\t|I(a,b,n) - I(a,b)| \t h*h\n");
    for (int i = 10; i < pow(10, testCount); i *= 10) {
        double h = (double) (b - a) / i;
        printf("%-16i%-20.4f%-19.3e%-5.2e\n", i, numIntegPolyf(a, b, i, &consts),
                abs(numIntegPolyf(a, b, i, &consts) - integPolyf(a,b, &consts)), h*h);
    }
    
    //---------------------------plotting---------------------------
    
    int points = 100;
    vector<double> xaxisx(2); 
    vector<double> xaxisy(2); 
    vector<double> xpoints(points); 
    vector<double> fxpoints(points); 
    
    const char* fpoints = "data/fpoints.dat";
    const char* axisPoints = "data/axisPoints.dat";
    
    for (int i = 0; i < points; i++) {
        double x = a + i * ((double) (b - a) / points);
        xpoints[i] = x;
        fxpoints[i] = polyf(x, &consts);
    }
    xaxisx[0] = a;
    xaxisy[0] = 0;
    xaxisx[1] = b;
    xaxisy[1] = 0;
    
    generatePlottingData(xpoints, fxpoints, fpoints);
    generatePlottingData(xaxisx, xaxisy, axisPoints);
    
    plot(fpoints , "b-2", axisPoints, "k-5", NULL);
    
}
