#include <Shape.h>
#include <Tensor.h>
#include <TensorMath.h>
#include <TensorStats.h>
#include <TensorRandom.h>
#include <iostream>

int main() {
  nerd::Tensor<double> T(nerd::Shape{3, 4}, 1);
  for (int i = 4; i < T.size(); i++) {
    T[i] = i;
  }

  std::cout << T.get_shape() << std::endl;
  std::cout << T.get_strides() << std::endl;
  auto X = nerd::sum(T, 1);
  auto Y = nerd::mean(T, 1);
  auto Z = nerd::var(T, 1);
  auto W = nerd::stdev(T, 1);
  auto M = nerd::min(T, 1);
  auto B = nerd::max(T, 1);

  std::cout << T << std::endl;
  std::cout << X << std::endl;
  std::cout << Y << std::endl;
  std::cout << Z << std::endl;
  std::cout << W << std::endl;
  std::cout << M << std::endl;
  std::cout << B << std::endl;
  return 0;
}
