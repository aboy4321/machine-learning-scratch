#pragma once

#include <numeric>
#include <execution>

namespace nerd {

template <typename Type>
double sum(const Matrix<Type>& M) {
  return std::accumulate(M.begin(), M.end(), 0.0); 
}

template <typename Type>
double mean(const Matrix<Type>& M) {
  return sum(M) / M.size();
}

template <typename Type>
double stdev(const Matrix<Type>& M) {
  double _mean = mean(M);

  double sqrd_diff_sum = 0.0;
  for (int i = 0; i < M.size(); ++i) {
    double diff = M[i] - _mean;
    sqrd_diff_sum += diff * diff;
  }
  return std::sqrt(sqrd_diff_sum / M.size());
}

template <typename Type>
double var(const Matrix<Type>& M) {
  double _mean = mean(M);

  double sqrd_diff_sum = 0.0;
  for (int i = 0; i < M.size(); ++i) {
    double diff = M[i] - _mean;
    sqrd_diff_sum += diff * diff;
  }
  return sqrd_diff_sum / M.size();
}

template <typename Type>
Type min(const Matrix<Type>& M) {
  auto min_it = std::min_element(M.begin(), M.end());
  int min_val_stl = *min_it;
  return min_val_stl;
}

template <typename Type>
Type max(const Matrix<Type>& M) {
  auto max_it = std::max_element(M.begin(), M.end());
  int max_val_stl = *max_it;
  return max_val_stl;
} 


}
