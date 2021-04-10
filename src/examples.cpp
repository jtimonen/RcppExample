#include <Rcpp.h>
#include <stdio.h>
using namespace Rcpp;

// [[Rcpp::export]]
void hello_world() {
  std::cout << "Hello world!" << std::endl;
}
