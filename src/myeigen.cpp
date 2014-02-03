/* FILE myeigen.cpp begins */
#include <iostream>
#include <iomanip>
#include "nr.h"

#include "matutl02.cpp"

void eigen(Mat_DP a, Vec_CPLX_DP &w )
{
  NR::balanc(a);
  NR::elmhes(a);
  NR::hqr(a,w);
}
/* FILE myeigen.cpp ends */
