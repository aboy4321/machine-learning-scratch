#include <Shape.h>
#include <Matrix.h>
#include <MatrixMath.h>
#include <MatrixStats.h>
#include <MatrixRandom.h>
#include <iostream>

int main() {
  nerd::Matrix<float> D({{0,1,2,3},
                         {4,5,6,7}});

  auto Unif = nerd::unifint({4,3}, 0);
  Unif.print();

  return 0;

}
