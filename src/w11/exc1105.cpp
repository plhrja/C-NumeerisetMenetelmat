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
double theta;

double f(double k){
    return sin(k * theta);
}

double dg(double k){
    double numerator = k * (cos(k*theta) * sin(0.5*theta) - sin(k*theta) * cos(0.5*theta));
    double denominator = pow(k * sin(0.5*theta), 2);
    return numerator / denominator;
}

void test_a(int partition_size, int max_iter, double tol){
    for (int i = 1; i < partition_size; i++) {
        theta = ((double) i * M_PI) / (partition_size - 1);
        double Sn = 0;
        double target = (M_PI - theta) / 2;
        bool convergence = false;
        for (int k = 1; k <= max_iter; k++) {
            Sn += f(k) / k;
            if(abs(target - Sn) < tol){
                convergence = true;
                break;
            }
        }
        
        cout << "theta = " << theta;
        cout << ", error = " << abs(target - Sn);
        if(!convergence){
            cout << " iteration did not converge!";
        }
        cout << endl;
    }
}

void test_b(int max_iter){
    myplot::data_set thetas = {myplot::plot_data("b-", "theta_1"), myplot::plot_data("c-", "theta_2"),
        myplot::plot_data("g-", "theta_3"), myplot::plot_data("r-", "theta_4")};
    int n = thetas.size();
    for (int i = 0; i < n; i++) {
        theta = ((double) (i + 1) * M_PI) / (n + 1);
        double Sn = 0;
        for (int k = 1; k <= max_iter; k++) {
            Sn += f(k) / k;
            thetas[i].add_point(k, Sn);
        }
    }
    myplot::plot(thetas);
}

void test_c(int max_iter){
    myplot::data_set thetas = {myplot::plot_data("b-", "theta_1"), myplot::plot_data("c-", "theta_2"),
        myplot::plot_data("g-", "theta_3"), myplot::plot_data("r-", "theta_4")};
    int n = thetas.size();
    for (int i = 0; i < n; i++) {
        theta = ((double) (i + 1) * M_PI) / (n + 1);
        double sum = 0;
        for (int k = 1; k <= max_iter; k++) {
            sum += dg(k);
            thetas[i].add_point(k, sum);
        }
    }
    myplot::plot(thetas);
}



int main(){
    cout << "case a)" << endl;
    test_a(23, 1e6, 1e-6);
    
    getchar();
    
    test_b(500);
    
    test_c(500);
}
