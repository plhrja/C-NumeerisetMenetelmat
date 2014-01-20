/* FILE: h011.c begins.          */
/*  gcc -Wall h011.c -o a -lm   */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double WindChill(double T, double V) {
    return 0.045 * (5.27 * sqrt(V) + 10.45 - 0.28 * V)* (T - 33.0) + 33.0;
}

int Prompt_TV() {
    double T, V;
    printf("Enter temperature in Celsius:");
    scanf("%lf", &T);
    printf("Enter wind speed in km/h:");
    scanf("%lf", &V);
    printf("For T = %lf, V = %lf, wind chill is: %lf\n\n", T, V, WindChill(T, V));
    return 0;
}

int main() {
    int i, j, k;
    double T, V, WC;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            T = 10 - j * 5.0;
            V = i * 2;
            WC = WindChill(T, V*3.6);
            if (j == 0) {
                printf("% 5d ", (int) V);
            }
            if (i == 0)
                printf("% 5d ", (int) T);
            else
                printf("% 5d ", (int) WC);
        }
        printf("\n");
    }
}

