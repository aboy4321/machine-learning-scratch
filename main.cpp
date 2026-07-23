#include <Matrix.h>
#include <iostream>

int main() {
  Matrix<int> M(3,3);
  Matrix<int> Two(2, 2, 2);
  Matrix<int> N;
  int n = M.data.size();
  for (int i = 0; i < n; i++) {
    M.data[i] = i;
  }
  M.print();
  Matrix<int> T = M.transpose();
  T.print();

  Matrix<int> O = M * M * M;

  O.print();
  return 0;
}
