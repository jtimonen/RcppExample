#include <Rcpp.h>
#include <iostream>
#include <vector>
using namespace Rcpp;

// [[Rcpp::export]]
void hello_world() {
  std::cout << "Hello world!" << std::endl;
}

// [[Rcpp::export]]
std::vector<int> std_vector_example() {
  std::vector<int> v = {1, 2, 3};
  return v;
}



