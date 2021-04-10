## Example R-package using Rcpp

* All C++ code is in `src`
* Code that uses only basic `Rcpp` is in `src/examples.cpp`
* Code that uses `RcppArmadillo` is in `src/examples_arma.cpp`
* Run R CMD build to build the package tarball
* Run R CMD check to check the package tarball
