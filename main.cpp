#include <Shape.h>
#include <Tensor.h>
#include <TensorMath.h>
#include <TensorRandom.h>
#include <iostream>

int main() {
  nerd::Tensor<int> T(nerd::Shape{4, 3}, 1);
  for (int i = 0; i < T.size(); i++) {
    T[i] = i;
  }
  std::cout << T.get_shape() << std::endl;
  auto X = T.sum(1);
  auto Y = T.mean(1);

  std::cout << T << std::endl;
  std::cout << X << std::endl;
  std::cout << Y << std::endl;
  return 0;
}
