#include <Shape.h>
#include <Matrix.h>
#include <TensorMath.h>
#include <TensorStats.h>
#include <TensorRandom.h>
#include <Tensor.h>
#include <iostream>

int main() {
  nerd::Tensor<int> T({2, 2, 3});
  auto M = nerd::Tensor<float>::ones({1,2});
  auto N = nerd::Tensor<int>::diagonal({1,2,3,4});

  std::cout << N << std::endl;
  auto I = nerd::Tensor<int>::identity(3);

  auto I2 = nerd::Tensor<int>::identity(3);

  std::cout << T.get_shape() << std::endl;
  nerd::Shape stri = T.get_strides();

  std::cout << stri << std::endl;

  auto I3 = I + I2;
  std::cout << nerd::sum(I3) << std::endl;
  auto unif = nerd::unifloat({1,3});
  std::cout << unif << std::endl;

  return 0;

}
