#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>
#include "nr.h"
#include "matutl02.h"

namespace mutils {

    typedef std::vector<double(*)(const Vec_DP &)> Fun_vec;
    
    void isolateRow(const Mat_DP& mtr, int row, Mat_DP& rowMtr);

    void isolateCol(const Mat_DP& mtr, int col, Mat_DP& colMtr);

    void isolateRow(const Mat_DP& mtr, int row, Vec_DP& rowVec);

    void isolateCol(const Mat_DP& mtr, int col, Vec_DP& colVec);

    void generatePlottingData(const Mat_DP &xdata, const Mat_DP &ydata, const char* fname);

    void generatePlottingData(const Vec_DP &xdata, const Vec_DP &ydata, const char* fname);

    void generatePlottingData(const std::vector<double> &xdata, const std::vector<double> &ydata, const char* fname);

    void generatePlottingData(const Mat_DP &xdata, const Mat_DP &ydata, std::string fnameString);

    void generatePlottingData(const std::vector<double> &xdata, const std::vector<double> &ydata, std::string fnameString);

    void generatePlottingData(const Vec_DP &xdata, const Vec_DP &ydata, std::string fnameString);

    void eigen(Mat_DP &a, Vec_CPLX_DP &w);

    void DDmatrix(Mat_DP& A, double mul, double low, double high);

    bool isDDmatrix(const Mat_DP &A);

    void LUsolve(Mat_DP a, Vec_DP b, Vec_DP &x);
    
    double deriv(double (*f)(double), double x);

    void polyfit_LU(const Vec_DP &xdata, const Vec_DP &ydata, Vec_DP &coeffs, int degree);

    void polyfit_SVD(const Vec_DP &xdata, const Vec_DP &ydata, Vec_DP &coeffs, int degree);
    
    void polyfit_HOUSE(const Vec_DP &xdata, const Vec_DP &ydata, Vec_DP &coeffs, int degree);
    
    double newton_next_iter(double (*f)(double), double xn);
    
    double newton(double (*f)(double), double init_guess, int max_iter, double tol);
    
    double newton_next_iter(double (*f)(double), double (*d_f)(double), double xn);
    
    double newton(double (*f)(double), double (*d_f)(double), double init_guess, int max_iter, double tol);
    
    void generate_Jacobian(Fun_vec f , Mat_DP &jacob, const Vec_DP &x);
    
    Vec_DP newton_next_iter(Fun_vec f, const Vec_DP &xn);
    
    Vec_DP newton(Fun_vec f, Vec_DP init_guess, int max_iter, double tol);
    
    Vec_DP steepest_descent(double (*f)(const Vec_DP&), Vec_DP init_guess, int max_iter, double tol);
    
    double barzilai_borwein(double (*f)(double), double init_guess);
    
    double barzilai_borwein(double (*f)(double), double init_guess, double tol, int max_iter);
}
