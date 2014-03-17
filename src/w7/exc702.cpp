#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "nr.h"
#include "solve.h"
#include "myplot.h"
#include "mutils.h"
#include "matutl02.h"

#define DATA_SIZE 20
using namespace std;

double sigma1, sigma2, sigma3;
Vec_DP xdata(DATA_SIZE), ydata(DATA_SIZE);

double f(double s, double x){
    double exponent = -pow(x, 2)/(2 * pow(s, 2));
    return (x/s) * exp(exponent);
}

double g(double s){
    double sum = 0;
    for (int i = 0; i < xdata.size(); i++) {
        sum += pow(ydata[i] - f(s, xdata[i]), 2);
    }
    return sum;
}

int main(){
    double init_guess1 = .2;
    double init_guess2 = 1;
    double init_guess3 = 100;
    
    Mat_DP data = getmat("data/data702.dat");
    mutils::isolateCol(data, 0, xdata);
    mutils::isolateCol(data, 1, ydata);
    
    sigma1 = mutils::barzilai_borwein(g, init_guess1, 1e-8, 1000);
    sigma2 = mutils::barzilai_borwein(g, init_guess2, 1e-8, 1000);
    sigma3 = mutils::barzilai_borwein(g, init_guess3, 1e-8, 1000);
    
    cout << "sigma1 = " << sigma1 << endl;
    cout << "g(sigma1) = " << g(sigma1) << endl <<endl;
    cout << "sigma2 = " << sigma2 << endl;
    cout << "g(sigma2) = " << g(sigma2) << endl << endl;
    cout << "sigma3 = " << sigma3 << endl;
    cout << "g(sigma3) = " << g(sigma3) << endl;
    
    //-------------------------------------plotting-------------------------------------
    
    myplot::data_set container1;
    myplot::data_set container2;
    myplot::data_set container3;
    myplot::plot_data curve1("c-");
    myplot::plot_data curve2("c-");
    myplot::plot_data curve3("c-");
    myplot::plot_data point1("k.");
    myplot::plot_data point2("k.");
    myplot::plot_data point3("k.");
    point1.add_point(sigma1, g(sigma1));
    point2.add_point(sigma2, g(sigma2));
    point3.add_point(sigma3, g(sigma3));
    
    myplot::generate_data(g, container1, curve1, .1, 150, 1000);
    container1.push_back(point1);
    container1.push_back(point2);
    container1.push_back(point3);
    myplot::plot(container1);
    
    myplot::generate_data(g, container2, curve2, .01, 2.5, 1000);
    container2.push_back(point1);
    container2.push_back(point2);
    myplot::plot(container2);
    
    myplot::generate_data(g, container3, curve3, 80, 250, 1000);
    container3.push_back(point3);
    myplot::plot(container3);
    
}
