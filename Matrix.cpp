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
    std::tuple<std::size_t, std::size_t> shape;
  public:
    
    std::vector<Type> data;
    // constructors

    // default constructor
    Matrix(std::size_t rows, std::size_t cols)
      : rows(rows), cols(cols), data({}) {
      data.resize(rows * cols, Type());
      shape = {rows, cols};
    }

    // creates matrix filled with inputted values
    Matrix(std::size_t rows, std::size_t cols, Type val)
      : rows(rows), cols(cols), data({}) {
      data.resize(rows * cols, val);
      shape = {rows, cols};
      }

    // creates matrix from inputted vector
    Matrix(std::vector<Type> arr);

    // no params constructor
    Matrix() : rows(0), cols(0), data({}) { shape = {rows, cols}; }

    // printing shape of matrix 
    void print_shape() const {
      std::cout << "Shape : (" << rows << ", " << cols << ")" << std::endl;
    }

    // printing contents of matrix
    void print() const {
      for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
          std::cout << (*this)(i,j) << ",";
        }
        std::cout << std::endl;
      }
      std::cout << std::endl;
    }

    // modifies matrix entry
    Type& operator()(std::size_t row, std::size_t col) {
      return data[row * cols + col];
    }

    // only reads variable
    const Type& operator()(std::size_t row, std::size_t col) const {
      return data[row * cols + col];
    }

    // basic operators for matrix arithmetic

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

    // linear algebra methods/operations
    
    // multiplies matrices
    Matrix operator*(const Matrix& other) const {
      assert(cols == other.rows);
      Matrix res(rows, other.cols);
      for (int i = 0; i < res.rows; ++i) {
        for (int j = 0; j < res.cols; ++j) {
          for (int k =0; k < other.rows; ++k) {
            res(i, j) += (*this)(i, k) * other(k, j);
          }
        }
      }
      return res;
    }

    // tranposes the matrix
    Matrix transpose() const {
      Matrix res(cols, rows);
      for (std::size_t i = 0; i < rows; ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
          res(j, i) = (*this)(i, j);
        }
      }
      return res;
    }

    // getter functions
    std::size_t get_rows() const {
      return rows;
    }

    std::size_t get_cols() const {
      return cols;
    }
};

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
