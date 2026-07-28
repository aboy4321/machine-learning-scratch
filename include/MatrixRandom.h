#pragma once

#include <Matrix.h>
#include <MatrixStats.h>
#include <random>
#include <vector>

std::random_device rd;
std::mt19937 gen(rd());

namespace nerd {

Matrix<double> unifloat(Shape shape, const double low = 0.0, const double high = 1.0)  {
  Matrix<double> res(shape);
  std::uniform_real_distribution<double> dist(low, high);
  for (double& x : res) {
    x = dist(gen);
  }
  return res;
}

Matrix<int> unifint(Shape shape, const int low = 0, const int high = 1)  {
  Matrix<int> res(shape);
  std::uniform_int_distribution<int> dist(low, high);
  for (int& x : res) {
    x = dist(gen);
  }
  return res;
}

Matrix<double> norm(Shape shape, const float mean = 0, const float stdev = 1) {
  Matrix <double> res(shape);
  std::normal_distribution<double> dist(mean, stdev);
  for (double& x : res) {
    x = dist(gen);
  }
  return res;
}

}
