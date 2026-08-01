#pragma once

#include <numeric>
#include <execution>

namespace nerd {

template <typename Type>
double sum(const Tensor<Type>& M) {
  return std::accumulate(M.begin(), M.end(), 0.0); 
}

template <typename Type>
double mean(const Tensor<Type>& M) {
  return sum(M) / M.size();
}

template <typename Type>
double stdev(const Tensor<Type>& M) {
  double _mean = mean(M);

  double sqrd_diff_sum = 0.0;
  for (auto& x : M) {
    double diff = x - _mean;
    sqrd_diff_sum += diff * diff;
  }
  return std::sqrt(sqrd_diff_sum / M.size());
}

template <typename Type>
double var(const Tensor<Type>& M) {
  double _mean = mean(M);

  double sqrd_diff_sum = 0.0;
  for (auto& x : M) {
    double diff = x - _mean;
    sqrd_diff_sum += diff * diff;
  }
  return sqrd_diff_sum / M.size();
}

template <typename Type>
Type min(const Tensor<Type>& M) {
  auto min_it = std::min_element(M.begin(), M.end());
  return *min_it;
}

template <typename Type>
Type max(const Tensor<Type>& M) {
  auto max_it = std::max_element(M.begin(), M.end());
  return *max_it;
} 

}
