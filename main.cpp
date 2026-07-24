#include <Matrix.h>
#include <iostream>
#include <vector>

int main() {
  Matrix<int> M(3,3);
  int n = M.get_size();
  for (int i = 0; i < n; i++) {
    M.set_data(i, i);
  }
  return 0;
}
