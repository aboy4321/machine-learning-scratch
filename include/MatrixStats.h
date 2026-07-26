#pragma once

#include <Matrix.h>
#include <MatrixFunction.h>
#include <cmath>
#include <numeric>

namespace nerd {

template<typename Type>
double sum(const Matrix<Type>& M) {
  return std::accumulate(M.begin(), M.end(), 0.0); 
}
  
}
