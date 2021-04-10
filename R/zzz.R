.onUnload <- function(libpath) {
  library.dynam.unload("RcppExample", libpath)
}

.onAttach <- function(libname, pkgname) {
  cat("This is RcppExample.\n")
}