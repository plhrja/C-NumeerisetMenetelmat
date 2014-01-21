#include <cstdio>
#include <cstdlib>
#include <cmath>
#include "plot.h"
#include "nr.h"
#include "matutl02.h"

using namespace std;

int main(){
    Mat_DP A = getmat("A202.mat");
    Mat_DP b = getmat("b202.mat");
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
    
    char* filename1 = "data.tmp";
    char* filename2 = "fitted.tmp";
    FILE* file1 = fopen(filename1, "w");
    FILE* file2 = fopen(filename2, "w");

    int i;
    for (i = 0; i < A.nrows(); i++) {
        fprintf(file1, "%5.5f %5.5f\n", A[i][0], b[i][0]);
        fprintf(file2, "%5.5f %5.5f\n", A[i][0], x[0][0] * A[i][0] + x[1][0]);
    }
    fclose(file1);
    fclose(file2);
    
    plot(filename1, "k.", filename2, "r-", NULL);
}