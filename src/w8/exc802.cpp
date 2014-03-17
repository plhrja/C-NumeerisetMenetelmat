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

void run_tests(int max_iter){
    Vec_DP number_of_hist(2 * max_iter), height_of_hist(2 * max_iter),
           high_bound(2 * max_iter);
    
    for (int m = 0; m <= 1; m++) {
        int n = m + 3;
        Mat_DP A(n, n);
        
        for (int i = 0; i < max_iter; i++) {
            ranmat2(A, -1, 1);
            
            number_of_hist[i + (m*max_iter)] = i + (m*max_iter) + 1;
            height_of_hist[i + (m*max_iter)] = abs(detmat(A));
            high_bound[i + (m*max_iter)] = pow(n, (double) n/2);
        }
    }
    
    mutils::generatePlottingData(number_of_hist, height_of_hist, "data/hist.dat");
    mutils::generatePlottingData(number_of_hist, high_bound, "data/bound.dat");
    system("gnuplot hist_plot.cmd");
}

int main(){
    run_tests(1000);
}
