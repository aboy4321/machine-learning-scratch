#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <tuple>
#include <cassert>

template <typename Type>
class Matrix {
  private:
    std::size_t rows, cols;

  public:
    std::vector<Type> data;
    std::tuple<std::size_t, std::size_t> shape;

    Matrix(std::size_t rows, std::size_t cols)
      : rows(rows), cols(cols), data({}) {
      data.resize(rows * cols, Type());
      shape = {rows, cols};
    }

    Matrix() : rows(0), cols(0), data({}) { shape = {rows, cols}; };

    // Modifies matrix
    Matrix& operator+=(const Matrix& other) {
      assert(shape == other.shape);
      for (size_t i = 0; i < data.size(); ++i) {
        data[i] += other.data[i];
      }
      return *this;
    }

    // Creates another matrix 
    Matrix operator+(const Matrix& other) const {
      Matrix res = *this;
      res += other;
      return res;
    }

    Matrix& operator-=(const Matrix& other) {
      assert(shape == other.shape);
      for (size_t i = 0; i < data.size(); ++i) {
        data[i] -= other.data[i];
      }
      return *this;
    }

    Matrix operator-(const Matrix& other) const {
      Matrix res = *this;
      res -= other;
      return res;
    }
    
    // modifies variables
    Type& operator()(std::size_t row, std::size_t col) {
      return data[row * cols + col];
    }

    // only reads variable
    const Type& operator()(std::size_t row, std::size_t col) const {
      return data[row * cols + col];
    }

    std::size_t get_rows() const {
      return rows;
    }

    std::size_t get_cols() const {
      return cols;
    }
    // printing shape of matrix 
    void print_shape() const {
      std::cout << "Shape : (" << rows << ", " << cols << ")" << std::endl;
    }

    void print() const {
      for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
          std::cout << (*this)(i,j) << ",";
        }
        std::cout << std::endl;
      }
      std::cout << std::endl;
    }

    Matrix mat_mult(Matrix& other);

    Matrix transpose() const {
      Matrix res(cols, rows);
      for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
          res(j, i) = (*this)(i, j);
        }
      }
      return res;
    }

};

int main() {
  Matrix<int> M(3,3);
  int n = M.data.size();
  for (int i = 0; i < n; i++) {
    M.data[i] = i;
  }
  M.print();
  Matrix<int> T = M.transpose();
  T.print();

  return 0;
}
