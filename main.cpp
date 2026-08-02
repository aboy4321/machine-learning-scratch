#include <Shape.h>
#include <TensorMath.h>
#include <TensorStats.h>
#include <TensorRandom.h>
#include <Tensor.h>
#include <iostream>

int main() {
  nerd::Tensor<int> T(nerd::Shape{4, 3});
  std::cout << T.get_shape() << std::endl;
  std::cout << T << std::endl;
  T = T.m_transpose();
  std::cout << T.get_shape() << std::endl;
  std::cout << T << std::endl;
  return 0;
}
