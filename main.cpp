#include <Matrix.h>
#include <iostream>

int main() {
  Matrix<int> M(3,3);
  Matrix<int> Two(2, 2, 2);
  Matrix<int> N;
  int n = M.get_size();
  for (int i = 0; i < n; i++) {
    M.set_data(i, i);
  }
  M.print();
  Matrix<int> T = M.transpose();
  T.print();

  Matrix<int> O = M * 2 * M * M * 2;

  O.T().print();
  auto zero = Matrix<int>::zeros(4, 5);
  zero.print();
  return 0;
}
