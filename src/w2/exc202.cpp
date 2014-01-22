#include <cstdio>
#include <cstdlib>
#include <cmath>
#include "plot.h"
#include "nr.h"
#include "mutils.cpp"
#include "matutl02.h"

using namespace std;

int main(){
    Mat_DP A = getmat("data/A202.mat");
    Mat_DP b = getmat("data/b202.mat");
    Mat_DP invAtA(2,2);
    Mat_DP x;
    
    //A'
    Mat_DP At = !A;
    
    //A'A
    Mat_DP AtA = At * A;
    
    //A'b
    Mat_DP Atb = At * b;
    
    //inv(A'A)
    invmat(AtA, invAtA);
    
    x = invAtA * Atb;
    showmat(x);
    
    //-------------------plotting-----------------------------
    
    const char* filename1 = "data/data.tmp";
    const char* filename2 = "data/fitted.tmp";
    
    generatePlottingData(A,b,filename1);
    
    Mat_DP ydata(A.nrows(), 1);
    for (int i = 0; i < A.nrows(); i++) {
        ydata[i][0] = x[0][0] * A[i][0] + x[1][0];
    }
    generatePlottingData(A, ydata, filename2);
    
    plot(filename1, "k.", filename2, "r-", NULL);
}