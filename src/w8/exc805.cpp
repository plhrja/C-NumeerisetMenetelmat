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

double catalan(int iter){
    double sum = 0;
    for (int i = 0; i < iter; i++) {
        sum += pow(-1, i) / pow(2*i + 1, 2);
    }
    return sum;
}

int main(){
    int iter = 1e7;
    auto K = [](double x){return NR::ellf(0.5*M_PI,x);};
    auto E = [](double x){return NR::elle(0.5*M_PI,x);};
    auto arc = [](double x){return atan(x)/x;};
    
    double f_a = 0.5 * NR::qgaus(K,0,1);
    double f_b = -0.5 + NR::qgaus(E,0,1);
    double f_c = NR::qgaus(arc,0,1);
    double cat = catalan(iter);
    
    cout.precision(10);
    cout << endl << "case A: " << f_a << endl;
    cout << "error = " << abs(f_a - cat) << endl << endl;

    cout << "case B: " << f_b << endl;
    cout << "error = " << abs(f_b - cat) << endl << endl;
    
    cout << "case C: " << f_c << endl;
    cout << "error = " << abs(f_c - cat) << endl << endl;
}
