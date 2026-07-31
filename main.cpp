#include <Shape.h>
#include <Matrix.h>
#include <MatrixMath.h>
#include <MatrixStats.h>
#include <MatrixRandom.h>
#include <Tensor.h>
#include <iostream>

int main() {
  nerd::Matrix<float> D({{0,1,2,3},
                         {4,5,6,7}});

  nerd::Tensor<int> T({2, 3, 4, 12}, 1);

  std::cout << T.get_shape() << std::endl;
  nerd::Shape stri = T.get_strides();

  std::cout << stri << std::endl;

  std::cout << '\n';
  auto Unif = nerd::unifint({4,3});
  auto Norm = nerd::norm({1000, 1000});
  std::cout << nerd::mean(Norm) << std::endl;
  std::cout << nerd::stdev(Norm) << std::endl;
  return 0;

}
