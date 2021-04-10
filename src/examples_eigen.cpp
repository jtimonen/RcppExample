#include <RcppEigen.h>
#include <vector>

// [[Rcpp::depends(RcppEigen)]]

// Create two matrices and return them in a list
// [[Rcpp::export]]
std::vector<Eigen::MatrixXd> eigen_2_matrices() {
  Eigen::MatrixXd m1(2,2);
  Eigen::MatrixXd m2(3,2);
  m1 << 1, 2, 3, 4;
  m2 << 1, 0, 1, 0, 1, 0;
  std::vector<Eigen::MatrixXd> arr = {m1, m2};
  return arr;
}
