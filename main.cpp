#include <Matrix.h>
#include <MatrixFunction.h>
#include <MatrixStats.h>
#include <iostream>
#include <vector>

int main() {


  auto Ones = nerd::Matrix<float>::identity(4);
  Ones.print();
  nerd::Matrix<int> D(10,10);
  for (int i = 0; i < D.size(); i++) {
    D[i] = i;
  }

  std::cout << nerd::sum(D) << std::endl;
  std::cout << nerd::mean(D) << std::endl;
  std::cout << nerd::stdev(D) << std::endl;
  std::cout << nerd::var(D) << std::endl;
  std::cout << nerd::min(D) << std::endl;
  D.print();
  return 0;
}
