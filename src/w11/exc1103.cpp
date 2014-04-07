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

Vec_DP getVec(){
    Mat_DP temp = getmat("data/b1.mat");
    Vec_DP b(temp.nrows());
    mutils::isolateCol(temp, 0, b);
    return b;
}

void print_results(string vecname, const Vec_DP &vec){
    cout << vecname << " = " << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
}

int main(){
    Mat_DP dirichlet = getmat("data/dirichlet1.mat");
    Vec_DP b = getVec(), ans(dirichlet.nrows());
    SVDsolve(dirichlet, b, ans);
    print_results("answer", ans);
}
