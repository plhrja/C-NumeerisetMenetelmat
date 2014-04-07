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

Vec_DP getVec(const char *fname){
    Mat_DP temp = getmat(fname);
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
    Mat_DP dirichlet1 = getmat("data/dirichlet2.mat"), 
            dirichlet2 = getmat("data/dirichlet3.mat");
    Vec_DP b1 = getVec("data/b2.mat"), b2 = getVec("data/b3.mat"),
            ans1(dirichlet1.nrows()), ans2(dirichlet2.nrows());
    
    LUsolve(dirichlet1, b1, ans1);
    print_results("case a", ans1);
    cout << endl;
    
    
    LUsolve(dirichlet2, b2, ans2);
    print_results("case b", ans2);
}

