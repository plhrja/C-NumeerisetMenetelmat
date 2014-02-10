#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "plot.h"
#include "nr.h"
#include "solve.h"
#include "mutils.h"
#include "matutl02.h"

#define CIRCLENAME "data/circledata"

using namespace std;

double sumRow(Mat_DP& A, int row){
    double sum = 0;
    for (int j = 0; j < A.ncols(); j++) {
        sum += (j != row) ? abs(A[row][j]) : 0;
    }
    return sum;
}

void generateCircledata(double center, double radius, int fileNumber){
    int n = 100;
    Vec_DP circlex(n), circley(n);
    stringstream str;
    str << CIRCLENAME << fileNumber << ".dat";
    for (int i = 0; i < n; i++) {
        double point = ((double) 2 * M_PI * i) / (n - 1);
        circlex[i] = center + (radius * cos(point));
        circley[i] = center + (radius * sin(point));
    }
    generatePlottingData(circlex, circley, str.str());
}

void generateEigendata(Vec_CPLX_DP eig){
    Vec_DP real(eig.size()), imag(eig.size());
    for (int i = 0; i < eig.size(); i++) {
        real[i] = eig[i].real();
        imag[i] = eig[i].imag();
    }
    generatePlottingData(real, imag, "data/eigendata.dat");
}

int main(){
    init_srand();
    int nmax = 25;
    double low = -5;
    double high = 5;
    
    for (int n = 5; n <= nmax; n += 5) {
        Mat_DP A(n, n);
        Vec_DP sums(n);
        Vec_CPLX_DP eig(n);
        eigen(A, eig);

        for (int i = 0; i < n; i++) {
            sums[i] = sumRow(A, i);
        }
        
        for (int i = 0; i < n; i++) {
            generateCircledata(A[i][i], sums[i], i);
        }
        generateEigendata(eig);
    }

}
