#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "plot.h"
#include "nr.h"
#include "solve.h"
#include "mutils.h"
#include "matutl02.h"

#define EPS 1e-8

using namespace std;

void computeColumnNorms(Mat_DP& A, Vec_DP& norms, double p){
    for (int i = 0; i < A.ncols(); i++) {
        Vec_DP col(A.nrows());
        isolateCol(A, i, col);
        norms[i] = vnormp(col, p);
    }
}

void generateNormalizedMtr(Mat_DP& A, double p, Mat_DP& B){
    Vec_DP norms(A.ncols());
    computeColumnNorms(A, norms, p);
    for (int i = 0; i < A.nrows(); i++) {
        for (int j = 0; j < A.ncols(); j++) {
            B[j][i] = A[j][i] / norms[i];
        }
    }
}

bool isNormalized(Mat_DP& A, double p){
    Vec_DP norms(A.ncols());
    computeColumnNorms(A, norms, p);
    for (int i = 0; i < norms.size(); i++) {
        if(abs(norms[i] - 1) > EPS){
            return false;
        }
    }
    return true;
}

double dotProdOfCols(Mat_DP& A, int col1, int col2){
    double sum = 0;
    for (int i = 0; i < A.nrows(); i++) {
        sum += A[i][col1] * A[i][col2];
    }
}

void generateDotProdMtr(Mat_DP& A, double p, Mat_DP& B){
    if(!isNormalized(A, p)){
        cout << "Matrix arg 1 not normalized!" << endl;
        return;
    }
    for (int i = 0; i < A.nrows(); i++) {
        for (int j = 0; j < A.ncols(); j++) {
            B[i][j] = dotProdOfCols(A, i, j);
        }
    }
}

int main(){
    double p = 2;
    
    //a)
    Mat_DP A = getmat("data/exc404A.mat");
    Vec_DP norms(A.ncols());
    cout << "A = \n" << A << endl;
    
    computeColumnNorms(A, norms, p);
    cout << "p-norms of A = \n" << norms << endl;
    getchar();
    
    //b)
    Mat_DP B(A.nrows(), A.ncols());
    generateNormalizedMtr(A, p, B);
    cout << "B = \n" << B << endl;
    
    computeColumnNorms(B, norms, p);
    cout << "p-norms of B = \n" << norms << endl;
    getchar();
    
    //c)
    Mat_DP C(B.ncols(), B.ncols());
    generateDotProdMtr(B, p, C);
    cout << "C = \n" << C << endl;
    
    computeColumnNorms(C, norms, p);
    cout << "p-norms of C = \n" << norms << endl;
}