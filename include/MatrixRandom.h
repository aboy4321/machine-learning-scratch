#pragma once

#include <Matrix.h>
#include <MatrixStats.h>
#include <random>
#include <vector>

std::random_device rd;
std::mt19937 gen(rd());

namespace nerd {

static Matrix<double unif(const double low = 0.0, const double high = 0.0, std::size_t dim) {
  Matrix<double> res(dim, dim);
  std::uniform_real_distribution<double> dist(low, high);
  double random_double = dist(gen);
  for (std::size_t i = 0; i < dim; ++i) {
    res[i] = dist(gen);
  }
  return res;
}
  
}
