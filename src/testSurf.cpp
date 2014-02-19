#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "nr.h"
#include "solve.h"
#include "myplot.h"
#include "mutils.h"
#include "matutl02.h"

using namespace std;

int main() {
    int points = 30;
    double start = -1;
    double end = 1;

    myplot::surf_data_set container;
    myplot::surf_data surface("-");
    for (int i = 0; i < points; i++) {
        double x = start + ((double) i * (end - start)) / (points - 1);
        for (int j = 0; j < points; j++) {
            double y = start + ((double) j * (end - start)) / (points - 1);
            surface.add_point(x, y, x*y);
        }
    }
    container.push_back(surface);
    myplot::surf(container, "f(x,y) = x*y");

}
