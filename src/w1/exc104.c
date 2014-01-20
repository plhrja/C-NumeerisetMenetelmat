#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "plot.h"

void fitExchangeRate(double xdata[], double ydata[], int size, double* a, double* b) {
    double sumOfProducts = 0;
    double sumOfX = 0;
    double sumOfY = 0;
    double avgX;
    double leastSqEr = 0;

    int i;
    for (i = 0; i < size; i++) {
        sumOfProducts += xdata[i] * ydata[i];
        sumOfY += ydata[i];
        sumOfX += xdata[i];
    }
    avgX = sumOfX / size;

    for (i = 0; i < size; i++) {
        leastSqEr += pow(xdata[i] - avgX, 2);
    }

    double firstParam = (sumOfProducts - ((sumOfX * sumOfY) / size)) / leastSqEr;
    double secondParam = (sumOfY - (firstParam * sumOfX)) / size;
    *a = firstParam;
    *b = secondParam;
}

int main() {
    double x[6] = {1, 2, 3, 4, 5, 6};
    double y[6] = {0.8969, 0.9005, 0.8961, 0.8919, 0.8793, 0.8818};
    
    double a;
    double b;
    fitExchangeRate(x, y, 6, &a, &b);
    printf("a = %5.5f\t b = %5.5f\n", a, b);

    char* filename1 = "data.tmp";
    char* filename2 = "fitted.tmp";
    FILE* file1 = fopen(filename1, "w");
    FILE* file2 = fopen(filename2, "w");

    int i;
    for (i = 0; i < 6; i++) {
        fprintf(file1, "%5.5f %5.5f\n", x[i], y[i]);
        fprintf(file2, "%5.5f %5.5f\n", x[i], a * x[i] + b);
    }
    fclose(file1);
    fclose(file2);

    plot(filename1, "k.", filename2, "r-", NULL);
}