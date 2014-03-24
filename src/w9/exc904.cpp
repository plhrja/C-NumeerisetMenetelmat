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

void printResult(const Vec_DP &vec){
    for (int i = 0; i < vec.size(); i++) {
        cout << "x" << i + 1 << " = " << vec[i] << endl;
    }
}

int main(){
    Vec_DP init_guess_A(2), init_guess_B(3);
    init_guess_A[0] = 2;
    init_guess_A[1] = 0;
    
    init_guess_B[0] = 3;
    init_guess_B[1] = 4;
    init_guess_B[2] = 5;

    mutils::Fun_vec system_A = {[](const Vec_DP &x){return 2*pow(x[0] + x[1], 2) + pow(x[0] - x[1], 2) - 8;},
                                [](const Vec_DP &x){return 5*pow(x[0], 2) + pow(x[1] - 3, 2) - 9;}};
    
    mutils::Fun_vec system_B = {[](const Vec_DP &x){return 3*x[0] - cos(x[1]*x[2]) - 0.5;},
                                [](const Vec_DP &x){return pow(x[0], 2) - 81*pow(x[1] + 0.1, 2) + sin(x[2]) + 10.6;},
                                [](const Vec_DP &x){return exp(-x[0]*x[1]) + 20*x[2] + ((10*M_PI - 3)/3);}};
    
    Vec_DP case_A = mutils::newton(system_A, init_guess_A, 1000, 1e-8);
    Vec_DP case_B = mutils::newton(system_B, init_guess_B, 1000, 1e-8);
    
    cout << "Case a)" << endl;
    printResult(case_A);
    
    cout << endl << "Case b)" << endl;
    printResult(case_B);
}
