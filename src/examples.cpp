#include <Rcpp.h>
#include <vector>
using namespace Rcpp;

//' Hello world
//' 
//' @export
// [[Rcpp::export]]
void hello_world() {
  Rcpp:Rcout << "Hello world!\n";
}

// [[Rcpp::export]]
std::vector<int> std_vector_example() {
  std::vector<int> v = {1, 2, 3};
  return v;
}



