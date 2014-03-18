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

int main(){
    Vec_DP init_guess1(2), init_guess2(3);
    init_guess1[0] = 2;
    init_guess1[1] = 0;

    mutils::Fun_vec f1 = {[](const Vec_DP &x){return 2*pow(x[0] + x[1], 2) + pow(x[0] - x[1], 2) - 8;},
                          [](const Vec_DP &x){return 5*pow(x[0], 2) + pow(x[1] - 3, 2) - 9;}};
    
    mutils::Fun_vec f2 = {[](const Vec_DP &x){return 3*x[0] - cos(x[1]*x[2]) - 5;},
                          [](const Vec_DP &x){return pow(x[0], 2) - 81*pow(x[1] + 0.1, 2) + sin(x[2]) + 10.6;},
                          [](const Vec_DP &x){return exp(x[0]*x[1]);}};
    
    Vec_DP ans1 = mutils::newton(f1, init_guess1, 100, 1e-6);
    cout << "ans = " << ans1 << endl;
}
