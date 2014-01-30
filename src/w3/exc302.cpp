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
    for (int i = 0; i < n; i++) {
        sum += (*consts)[i] * pow(x, n - i);
    }
    return sum;
}

double integPolyf(double a, double b, vector<double>* consts){
    double sum = 0;
    int n = consts->size();
    for (int i = 0; i < n; i++) {
        sum += (*consts)[i] * (pow(b, (n + 1) - i) - pow(a, (n + 1) - i));
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
    vector<double> consts(4);
    double low = -10;
    double high = 10;
    
    cout << "f(x) = ";
    for (int i = 0; i < 4; i++) {
        consts[i] = rdm(low, high);
        
        const char* sign = (signbit(consts[i])) ? " - " : (i != 0) ? " + " : "";
        cout << sign << abs(consts[i]) << "x^" << 4 - i;
    }
    cout << endl << endl;
    
    double a = -2;
    double b = 2;
    int testCount = 5;
    
    printf("n \t\t I(a,b,n) \t\t |I(a,b,n) - I(a,b)| \t\t h*h");
    for (int i = 10; i < pow(10, testCount); i *= 10) {

    }
}