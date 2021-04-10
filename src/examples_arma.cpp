// [[Rcpp::depends(RcppArmadillo)]]
#include "RcppArmadillo.h"

// Outer product
// [[Rcpp::export]]
arma::mat arma_outerproduct(const arma::colvec & x) {
    arma::mat m = x * x.t();
    return m;
}

// Outer products multiplied by different integers (1, ..., 3)
// [[Rcpp::export]]
arma::Cube<double> arma_3_matrices(const arma::colvec & x) {
    const int N = x.size();
    Rcpp::Rcout << "Creating " << N << "x" << N << " matrices... ";
    arma::Cube<double> A = arma::cube(N, N, 3);
    for(int i = 0; i < 3; ++i) {
        A.slice(i) = (i+1) * arma_outerproduct(x);
    }
    Rcpp::Rcout << "done.\n";
    return A;
}

// Inner product
// [[Rcpp::export]]
double arma_innerproduct(const arma::colvec & x) {
    double v = arma::as_scalar(x.t() * x);
    return v;
}

// Linear regression
// http://dirk.eddelbuettel.com/code/rcpp.armadillo.html
// [[Rcpp::export]]
Rcpp::List arma_fastLm(const arma::mat& X, const arma::colvec& y) {
    int n = X.n_rows, k = X.n_cols;
    
    arma::colvec coef = arma::solve(X, y);    // fit model y ~ X
    arma::colvec res  = y - X*coef;           // residuals
    
    // std.errors of coefficients
    double s2 = std::inner_product(res.begin(), res.end(), res.begin(), 0.0)/(n - k);
    
    arma::colvec std_err = arma::sqrt(s2 * arma::diagvec(arma::pinv(arma::trans(X)*X)));  
    
    return Rcpp::List::create(Rcpp::Named("coefficients") = coef,
                              Rcpp::Named("stderr")       = std_err,
                              Rcpp::Named("df.residual")  = n - k);
}
