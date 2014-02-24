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

Vec_DP coeffs(6);

double g(double x, double y){
    return coeffs[0]*pow(x,2) + coeffs[1]*pow(y,2) + coeffs[2]*x*y + coeffs[3]*x +
            coeffs[4]*y + coeffs[5];
}

void extract_data(Vec_DP &data_x, Vec_DP &data_y, Vec_DP &data_z, const Mat_DP &A){
    mutils::isolateCol(A, 0, data_x);
    mutils::isolateCol(A, 1, data_y);
    mutils::isolateCol(A, 2, data_z);
}

void solve_system(Vec_DP &data_x, Vec_DP &data_y, Vec_DP &data_z){
    Mat_DP A(data_x.size(), 6);
    for (int i = 0; i < data_x.size(); i++) {
        double x = data_x[i];
        double y = data_y[i];
        
        A[i][0] = pow(x, 2);
        A[i][1] = pow(y, 2);
        A[i][2] = x * y;
        A[i][3] = x;
        A[i][4] = y;
        A[i][5] = 1;
    }
    SVDsolve(A, data_z, coeffs);
}

void print_cities(double (*f)(double x, double y)){
    printf("City\t\tx\ty\treal temp\tfrom model\n");
    printf("Jyväskylä\t%-8.2f%-8.2f%-16.2f%-8.2f\n", 5.3, 3.4, 0.3, f(5.3,3.4));
    printf("Mikkeli\t\t%-8.2f%-8.2f%-16.2f%-8.2f\n", 6.3, 2.7, 0.4, f(6.3,2.7));
    printf("Lahti\t\t%-8.2f%-8.2f%-16.2f%-8.2f\n", 5.2, 1.6, 0.9, f(5.2,1.6));
    printf("Pori\t\t%-8.2f%-8.2f%-16.2f%-8.2f\n", 2.7, 2.5, 1.0, f(2.7,2.5));
    printf("Kuopio\t\t%-8.2f%-8.2f%-16.2f%-8.2f\n", 6.4, 4.2, 0.4, f(6.4,4.2));
}

int main(){
    Mat_DP temps = getmat("data/temps.mat");
    Vec_DP data_x(temps.nrows()), data_y(temps.nrows()), real_temps(temps.nrows());

    extract_data(data_x, data_y, real_temps, temps);
    solve_system(data_x, data_y, real_temps);
    
    myplot::surf_data_set container;
    myplot::surf_data surface("-");
    myplot::surf_data points("+");
    
    myplot::generate_data(g, container, surface, -1, 9, -1, 9);
    for (int i = 0; i < data_x.size(); i++) {
        points.add_point(data_x[i], data_y[i], real_temps[i]);
    }
    container.push_back(points);
    print_cities(g);
    myplot::surf(container, "Fitting of temperature-curve", true);

}

