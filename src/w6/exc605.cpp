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

double a1, a2, b1, b2;

double f(double x){
    return a1*sin(b1*x) + a2*sin(b2*x);
}

double d_f(double (*f)(double), double x){
    return mutils::deriv(f, x);
}

double integ_f(double (*f)(double), double x){
    return NR::qsimp(f, 0, x);
}

int main(){
    init_srand();
    double low = 0;
    double high = 2;
    double x_low = 0;
    double x_high = M_PI;
    int points = 100;
    
    a1 = rdm(low, high);
    a2 = rdm(low, high);
    b1 = rdm(low, high);
    b2 = rdm(low, high);

    myplot::data_set container;
    myplot::plot_data function("b-2", "f(x)");
    myplot::plot_data derivative("c-2", "f'(x)");
    myplot::plot_data integral("g-2", "g(x)");
    myplot::plot_data x_axis("k-3");
    
    for (int i = 0; i < points; i++) {
        double x = x_low + ((double) i * (x_high - x_low))/(points - 1);
        function.add_point(x, f(x));
        derivative.add_point(x, d_f(f, x));
        integral.add_point(x, integ_f(f, x));
    }
    x_axis.add_point(x_low, 0);
    x_axis.add_point(x_high, 0);
    
    container.push_back(function);
    container.push_back(derivative);
    container.push_back(integral);
    container.push_back(x_axis);
    
    cout << "a1 = " << a1 << endl;
    cout << "a2 = " << a2 << endl;
    cout << "b1 = " << b1 << endl;
    cout << "b2 = " << b2 << endl;
    myplot::plot(container);
    
}
