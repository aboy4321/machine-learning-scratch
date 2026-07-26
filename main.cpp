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
  Matrix<int> D(4,4);
  D.fill(5);
  D.print();
  auto Dnu = MatrixMath::sqrt(D);
  Dnu.print();
  return 0;
}
