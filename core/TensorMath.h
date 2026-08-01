#pragma once

#include <Tensor.h>
#include <cmath>

namespace nerd {

// for getting the square root of an entire Tensor
template <typename Type>
Tensor<double> sqrt(const Tensor<Type>& M) {
  Tensor<double> res(M.get_shape());
  for (std::size_t i = 0; i < M.size(); ++i) {
    res[i] = std::sqrt(M[i]);
  }
  return res;
}

template <typename Type>  
Tensor<double> exp(const Tensor<Type>& M) {
  Tensor<double> res(M.get_shape());
  for (std::size_t i = 0; i < M.size(); ++i) {
    res[i] = std::exp(M[i]);
  }
  return res;
}

template <typename Type, typename Scalar>
Tensor<double> pow(const Tensor<Type>& M, Scalar n) {
  Tensor<double> res(M.get_shape());
  for (std::size_t i = 0;  i < M.size(); ++i) {
    res[i] = std::pow(M[i], n);
  }
  return res;  
}


template <typename Type>  
Tensor<double> log(const Tensor<Type>& M) {
  Tensor<double> res(M.get_shape());
  for (std::size_t i = 0;  i < M.size(); ++i) {
    res[i] = std::log(M[i]);
  }
  return res;
}

template <typename Type>  
Tensor<Type> abs(const Tensor<Type>& M) {
  Tensor<Type> res(M.get_shape());
  for (std::size_t i = 0;  i < M.size(); ++i) {
    res[i] = std::abs(M[i]);
  }
  return res;
}

// trig functions, returns in radians
template <typename Type>
Tensor<double> sin(const Tensor<Type>& M) {
  Tensor<double> res(M.get_shape());
  for (std::size_t i = 0;  i < M.size(); ++i) {
    res[i] = std::sin(M[i]);
  }
  return res;
}

template <typename Type>
Tensor<double> cos(const Tensor<Type>& M) {
  Tensor<double> res(M.get_shape());
  for (std::size_t i = 0;  i < M.size(); ++i) {
    res[i] = std::cos(M[i]);
  }
  return res;
}

template <typename Type>
Tensor<double> tan(const Tensor<Type>& M) {
  Tensor<double> res(M.get_shape());
  for (std::size_t i = 0;  i < M.size(); ++i) {
    res[i] = std::tan(M[i]);
  }
  return res;
}
}
