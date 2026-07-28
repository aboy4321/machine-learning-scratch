#include <Shape.h>
#include <Matrix.h>
#include <MatrixMath.h>
#include <MatrixStats.h>
#include <MatrixRandom.h>
#include <iostream>

int main() {
  nerd::Matrix<float> D({{0,1,2,3},
                         {4,5,6,7}});

  auto Unif = nerd::unifint({4,3});
  auto Norm = nerd::norm({1000, 1000});
  std::cout << nerd::mean(Norm) << std::endl;
  std::cout << nerd::stdev(Norm) << std::endl;
  return 0;

}
