#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fixedPoint(double (*func)(double), double initialGuess, double eps){
	double x = initialGuess;
	double x0;
	do{
                x0 = x;
		x = (*func)(x0);
	}while(fabs(x - x0) > eps);
	
	return x;
}

double firstF(double x){
	return cos(x);
}
double secondF(double x){
	return exp(-x);
}
double thirdF(double x){
	return 1 - cosh(x);
}

int main(){
	printf("solution a = %5.5f\n", fixedPoint(&firstF, 0, 1e-6));
	printf("solution b = %5.5f\n", fixedPoint(&secondF, 0, 1e-6));
	printf("solution c = %5.5f\n", fixedPoint(&thirdF, 0, 1e-6));
}