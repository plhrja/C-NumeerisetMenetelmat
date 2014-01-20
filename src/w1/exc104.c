#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* fitExchangeRate(double xdata[], double ydata[], int size){
 double sumOfProducts = 0; 
 double sumOfX = 0; 
 double sumOfY = 0;
 double avgX;
 double leastSqEr = 0;
 
 int i;
 for(i = 0; i < size; i++){
	sumOfProducts = sumOfProducts + (xdata[i] * ydata[i]);
	sumOfY = sumOfY + ydata[i];
	sumOfX = sumOfX + xdata[i];
 }
 avgX = 1/size * sumOfX;

 for(i = 0; i < size; i++){
	leastSqEr = leastSqEr + pow(xdata[i] - avgX, 2);
 }
 
 double firstParam = (sumOfProducts - ((1/size) * sumOfX * sumOfY))/leastSqEr;
 double secondParam = (sumOfY - (firstParam * sumOfX))/size;
 double fittedParams[2] = {firstParam, secondParam};

 return fittedParams;
}