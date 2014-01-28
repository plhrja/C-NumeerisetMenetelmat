#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "plot.h"
#include "nr.h"
#include "mutils.h"
#include "matutl02.h"

using namespace std;

void generateSequence(vector<double>* container, double lastElem, int elemCount) {
    (*container)[elemCount - 1] = lastElem;
    for (int i = elemCount - 1; i > 1; i--) {
        double constraint = (double) (i + 1) / (i - 1);
        (*container)[i-1] = constraint * (*container)[i];
    }
    (*container)[0] = (*container)[1] * 1;
}

double f(double (*func)(double), vector<double>* sequence, double x, bool sin){
    double sum = 0;
    for (int i = (sin) ? 1 : 0; i < sequence->size(); i++) {
        sum += (*sequence)[i] * (*func)(i * x);
    }
    return sum;
}

double getMin(vector<double> vec){
    double min = INFINITY;
    for (int i = 0; i < vec.size(); i++) {
        if(vec[i] < min){
            min = vec[i];
        }
    }
    return min;
}

int main() {
    init_srand();
    for (int i = 2; i <= pow(2, 6); i *= 2) {
        int sequenceSize = i;   
        int ppoints = 50;

        vector<double> seq(sequenceSize);
        vector<double> x(ppoints);
        vector<double> f1(ppoints);
        vector<double> f2(ppoints);

        generateSequence(&seq, 0.01, sequenceSize);

        for (int i = 0; i < ppoints; i++) {
            double xx = i * ((double) M_PI / ppoints);
            xx += (i == 0) ? 1e-4 : (i == ppoints - 1) ? -1e-4 : 0;

            x[i] = xx;
            f1[i] = f(&sin, &seq, xx, true);
            f2[i] = f(&cos, &seq, xx, false);
        }

        const char* f1points = "data/f1points.dat";
        const char* f2points = "data/f2points.dat";
        generatePlottingData(x, f1, f1points);
        generatePlottingData(x, f2, f2points);

        cout << "sequence size = " << i << endl;
        cout << "min f1(x) = " << getMin(f1) << endl;
        cout << "min f2(x) = " << getMin(f2) << endl << endl;
        plot(f1points, "r-2", f2points, "b-2", NULL);
        getchar();
    }
}

