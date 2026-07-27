#pragma once

#include <Matrix.h>
#include <MatrixStats.h>
#include <random>
#include <vector>

std::random_device rd;
std::mt19937 gen(rd());

namespace nerd {

Matrix<double> unifloat(std::size_t rows, std::size_t cols, const double low = 0.0, const double high = 1.0)  {
  Matrix<double> res(rows, cols);
  std::uniform_real_distribution<double> dist(low, high);
  for (double& x : res) {
    x = dist(gen);
  }
  return res;
}

Matrix<double> unifloat(std::size_t dim, const double low = 0.0, const double high = 1.0)  {
  Matrix<double> res(dim, dim);
  std::uniform_real_distribution<double> dist(low, high);
  for (double& x : res) {
    x = dist(gen);
  }
  return res;
}

Matrix<int> unifint(std::size_t rows, std::size_t cols, const int low = 0, const int high = 1)  {
  Matrix<int> res(rows, cols);
  std::uniform_int_distribution<int> dist(low, high);
  for (int& x : res) {
    x = dist(gen);
  }
  return res;
}

Matrix<int> unifint(std::size_t dim, const int low = 0, const int high = 1)  {
  Matrix<int> res(dim, dim);
  std::uniform_int_distribution<int> dist(low, high);
  for (int& x : res) {
    x = dist(gen);
  }
  return res;
}
  
}
