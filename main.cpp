#include <Matrix.h>
#include <MatrixFunction.h>
#include <MatrixStats.h>
#include <iostream>

int main() {
  nerd::Matrix<int> D(10,10);
  for (int i = 0; i < D.size(); i++) {
    D[i] = i;
  }
  std::cout << nerd::sum(D) << std::endl;
  std::cout << nerd::mean(D) << std::endl;
  std::cout << nerd::stdev(D) << std::endl;
  std::cout << nerd::var(D) << std::endl;
  std::cout << nerd::min(D) << std::endl;
  std::cout << nerd::max(D) << std::endl;
  std::cout << D.is_square() << std::endl;
  std::cout << D.is_symmetric() << std::endl;
  D.print();
  return 0;
}
