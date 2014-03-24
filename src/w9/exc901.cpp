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

Mat_DP cons_hilb(int n){
    Mat_DP hilb(n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int r = i + 1;
            int c = j + 1;
            hilb[i][j] = 1/((double) r + c - 1);
        }
    }
    return hilb;
}

Vec_DP cons_b(int n){
    Mat_DP hilb = cons_hilb(n);
    Vec_DP b(n);
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < n; j++) {
            sum += hilb[i][j];
        }
        b[i] = sum;
    }
    return b;
}

double error(const Vec_DP &x){
    Vec_DP error(x.size());
    for (int i = 0; i < x.size(); i++) {
        error[i] = 1 - x[i];
    }
    return vnormp(error, 2); 
}

Vec_DP min_error_and_index(const Vec_DP &x){
    double min = INFINITY;
    int index = -1;
    for (int i = 0; i < x.size(); i++) {
        if(x[i] < min){
            min = x[i];
            index = i;
        }
    }
    Vec_DP min_and_index(2);
    min_and_index[0] = min;
    min_and_index[1] = index;
    return min_and_index;
}

int main(){
    Vec_DP eps(10);
    for (int i = 0; i < eps.size(); i++) {
        eps[i] = pow(0.1, i*2);
    }
    cout << "eps = " << eps << endl;
    
    for (int i = 0; i < 4; i++) {
        int n = 5 * (i + 1);
        Mat_DP hilb = cons_hilb(n);
        Vec_DP b = cons_b(n), x_LU(n), x_SVD(n);
        
        LUsolve(hilb, b, x_LU);
        Vec_DP errors_SVD(eps.size());
        for (int k = 0; k < eps.size(); k++) {
            SVDsolve2(hilb, b, x_SVD, eps[k]);
            errors_SVD[k] = error(x_SVD);
        }
        Vec_DP min = min_error_and_index(errors_SVD);

        cout << "iteration nr." << i+1 << endl;
        cout << "error of LU-solve = " << error(x_LU) << endl;
        cout << "minimal error of truncated SVD-solve = " << min[0];
        cout << ", with eps = " << eps[(int) min[1]] << endl << endl;
    }
}
