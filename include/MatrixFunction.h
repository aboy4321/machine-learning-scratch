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

template <typename Type, typename Scalar>
Matrix<Type> pow(const Matrix<Type>& M, Scalar n) {
  Matrix<Type> res(M.get_rows(), M.get_cols());
  for (std::size_t i = 0;  i < M.size(); ++i) {
    res[i] = std::pow(M[i], n);
  }
  return res;  
}


template <typename Type>  
Matrix<double> log(const Matrix<Type>& M) {
  Matrix<double> res(M.get_rows(), M.get_cols());
  for (std::size_t i = 0;  i < M.size(); ++i) {
    res[i] = std::log(M[i]);
  }
  return res;
}
}
