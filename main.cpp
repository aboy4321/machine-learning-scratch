#include <Matrix.h>
#include <MatrixFunction.h>
#include <MatrixStats.h>
#include <iostream>
#include <vector>

int main() {
  nerd::Matrix<int> M(3,3);

  int n = M.size();
  for (int i = 0; i < n; i++) {
    M.set_data(i, i);
  }
  nerd::Matrix<int> N(3,3);
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

  auto Ones = nerd::Matrix<float>::identity(4);
  Ones.print();
  nerd::Matrix<int> D(4,4);
  D.fill(5);
  D.print();
  auto Dnu = nerd::sqrt(D);
  Dnu.print();
  std::cout << nerd::sum(D) << std::endl;
  return 0;
}
