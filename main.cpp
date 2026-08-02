#include <Shape.h>
#include <TensorMath.h>
#include <TensorStats.h>
#include <TensorRandom.h>
#include <Tensor.h>
#include <iostream>

int main() {
  nerd::Tensor<int> T({2, 2, 3});
  T = T.reshape({1, 2, 6});
  T = T.squeeze();
  std::cout << T.get_shape() << std::endl;
  std::cout << T << std::endl;
  return 0;
}
