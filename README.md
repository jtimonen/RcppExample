## Example R-package using Rcpp

* All C++ code is in `src`
* Code that uses only basic `Rcpp` is in `src/examples.cpp`
* Code that uses `RcppArmadillo` is in `src/examples_arma.cpp`
* Code that uses `RcppEigen` is in `src/examples_eigen.cpp`

Installation:

```{r}
devtools::install_github('jtimonen/RcppExample')
```

Example use:

```{r}
library(RcppExample)
hello_world() # prints message to standard output stream

# Returns an array with dim(A) equal to c(2,2,3)
A <- arma_3_matrices(c(1,2)) 

# Returns a list with length 2, so that
# - B[[1]] is a 2x2 matrix
# - B[[2]] is a 3x2 matrix
B <- eigen_2_matrices()
```
