#include <Matrix.h>
#include <MatrixFunction.h>
#include <iostream>
#include <vector>

int main() {
  Matrix<int> M(3,3);

  int n = M.size();
  for (int i = 0; i < n; i++) {
    M.set_data(i, i);
  }
  Matrix<int> N(3,3);
  int k = M.size();
  for (int i = 0; i < k; i++) {
    N.set_data(i, i);
  }
  
  if (M != N) {
    std::cout << "not equal" << std::endl;
  }
  if (M == N) {
    std::cout << "equal" << std::endl;
  }

  auto Ones = Matrix<float>::identity(4);
  Ones.print();
  Matrix<double> D(4,4);
  D.fill(1);
  D.print();
  auto DSquared = MatrixMath::sqrt(D);
  DSquared.print();
  auto DExpo = MatrixMath::exp(D);
  DExpo.print();
  return 0;
}
