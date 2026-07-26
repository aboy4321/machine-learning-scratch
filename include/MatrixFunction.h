#pragma once

#include <Matrix.h>
#include <cmath>

namespace nerd {

// for getting the square root of an entire matrix
template <typename Type>
Matrix<double> sqrt(const Matrix<Type>& M) {
  Matrix<double> res(M.get_rows(), M.get_cols());
  for (std::size_t i = 0; i < M.size(); ++i) {
    res[i] = std::sqrt(M[i]);
  }
  return res;
}

template <typename Type>  
Matrix<double> exp(const Matrix<Type>& M) {
  Matrix<double> res(M.get_rows(), M.get_cols());
  for (std::size_t i = 0; i < M.size(); ++i) {
    res[i] = std::exp(M[i]);
  }
  return res;
}

template <typename Type, typename Scalar>
Matrix<double> pow(const Matrix<Type>& M, Scalar n) {
  Matrix<double> res(M.get_rows(), M.get_cols());
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

template <typename Type>  
Matrix<Type> abs(const Matrix<Type>& M) {
  Matrix<Type> res(M.get_rows(), M.get_cols());
  for (std::size_t i = 0;  i < M.size(); ++i) {
    res[i] = std::abs(M[i]);
  }
  return res;
}

// trig functions, returns in radians
template <typename Type>
Matrix<double> sin(const Matrix<Type>& M) {
  Matrix<double> res(M.get_rows(), M.get_cols());
  for (std::size_t i = 0;  i < M.size(); ++i) {
    res[i] = std::sin(M[i]);
  }
  return res;
}

template <typename Type>
Matrix<double> cos(const Matrix<Type>& M) {
  Matrix<double> res(M.get_rows(), M.get_cols());
  for (std::size_t i = 0;  i < M.size(); ++i) {
    res[i] = std::cos(M[i]);
  }
  return res;
}

template <typename Type>
Matrix<double> tan(const Matrix<Type>& M) {
  Matrix<double> res(M.get_rows(), M.get_cols());
  for (std::size_t i = 0;  i < M.size(); ++i) {
    res[i] = std::tan(M[i]);
  }
  return res;
}
}
