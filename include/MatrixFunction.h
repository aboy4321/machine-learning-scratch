#pragma once

#include "Matrix.h"
#include <cmath>

namespace MatrixMath {
// for getting the square root of an entire matrix
template <typename Type>
Matrix<Type> sqrt(const Matrix<Type>& M) {
  Matrix<Type> res(M.get_rows(), M.get_cols());
  for (std::size_t i = 0; i < M.size(); ++i) {
    res[i] = std::sqrt(M[i]);
  }
  return res;
}

template <typename Type>  
Matrix<Type> exp(const Matrix<Type>& M) {
  Matrix<Type> res(M.get_rows(), M.get_cols());
  for (std::size_t i = 0; i < M.size(); ++i) {
    res[i] = std::exp(M[i]);
  }
  return res;
}

}
