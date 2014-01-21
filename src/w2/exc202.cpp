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
}