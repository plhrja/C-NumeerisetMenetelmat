#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "plot.h"
#include "nr.h"
#include "mutils.h"
#include "matutl02.h"

using namespace std;

int main(){
    
    auto g = [ ] (double x) {return pow(sin(x), 2);};
    auto f = [g] (double x) {return NR::qtrap(g, 0, x);};
    auto h = [f] (double x) {return f(x) - 5;};
    cout.precision(10);
    
    int maxIter = 100;
    double eps = 1e-8;
    double a = 0;
    double b = 20;
    double c;
    
    for (int i = 0; i < maxIter; i++) {
        
        c = (a + b) / 2;
        if (abs(h(c)) < eps) break;

        if (h(a) * h(c) < 0) {
            b = c;
        } else {
            a = c;
        }
        
        cout << "Iteration: " << i << endl;
        cout << "x = " << c << endl;
        cout << "f(x) = " << f(c) << endl << endl;
    }
    
    cout << "x = " << c << endl;
    cout << "f(x) = " << f(c) << endl;
    cout << "error = " << abs(h(c)) << endl;
}