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

double m;

double f(double x){
    return cos(M_PI * m * x);
}

int main(){
    init_srand();
    int test_count = 100;
    double low = -1;
    double high = 1;
    double start = 0;
    double end = 1;
    myplot::data_set container;
    myplot::plot_data trapz("b-", "trapz"), romb("c-", "romb"), gauss("g-", "gauss"), simp("m-", "simp");
    
    for (int i = 0; i < test_count; i++) {
        m = rdm(low, high);
        double abs_val = sin(M_PI * m * end)/(M_PI * m);
        
        double trapz_error = abs(NR::qtrap(f, start, end) - abs_val);
        double romb_error = abs(NR::qromb(f, start, end) - abs_val);
        double gauss_error = abs(NR::qgaus(f, start, end) - abs_val);
        double simp_error = abs(NR::qsimp(f, start, end) - abs_val);
        
        trapz.add_point(i + 1, trapz_error);
        romb.add_point(i + 1, romb_error);
        gauss.add_point(i + 1, gauss_error);
        simp.add_point(i + 1, simp_error);
    }
    container.push_back(trapz);
    container.push_back(romb);
    container.push_back(gauss);
    container.push_back(simp);
    myplot::plot(container);
}
