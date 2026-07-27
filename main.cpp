#include <Matrix.h>
#include <MatrixMath.h>
#include <MatrixStats.h>
#include <MatrixRandom.h>
#include <iostream>

int main() {
  nerd::Matrix<int> D(3,3);
  for (int i = 0; i < D.size(); i++) {
    D[i] = i;
  }
  auto Unif = nerd::unifint(4, 3, 0);
  Unif.print();

  std::cout << nerd::stdev(D) << std::endl;
  std::cout << nerd::var(D) << std::endl;

  /*
  std::cout << nerd::sum(D) << std::endl;
  std::cout << nerd::mean(D) << std::endl;
  std::cout << nerd::stdev(D) << std::endl;
  std::cout << nerd::var(D) << std::endl;
  std::cout << nerd::min(D) << std::endl;
  std::cout << nerd::max(D) << std::endl;
  std::cout << D.is_square() << std::endl;
  std::cout << D.is_symmetric() << std::endl;
  D.print();
  */
  return 0;
}
