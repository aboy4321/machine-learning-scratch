#pragma once

#include <Shape.h>
#include <vector>
#include <iostream>
#include <tuple>
#include <cassert>
#include <iterator>
#include <cstddef>

namespace nerd {

template <typename Type> 
class Matrix {
  private:
    Shape shape;
    std::vector<Type> data;

  public:

    auto begin() { return data.begin(); }
    auto end() { return data.end(); }

    auto begin() const { return data.begin(); }
    auto end() const { return data.end(); }

    /* 
     * Basic Constructors
     */

    // default constructor
    Matrix(const Shape shape)
      : shape(shape), data(shape.size()) {
        assert(shape.is_matrix());
      }

    // creates matrix filled with inputted values
    Matrix(const Shape shape, const Type val)
      : shape(shape), data(shape.size(), val) {
        assert(shape.is_matrix());
      }

    Matrix(std::initializer_list<std::initializer_list<Type>> values)
      : shape({values.size(), values.begin()->size()}) {
        assert(values.size() > 0);

        std::size_t cols = values.begin()->size();

        for (const auto& row : values) {
            assert(row.size() == cols);

            data.insert(data.end(), row.begin(), row.end());
        }
      }

    /*
     * Some basic matrices
     * Zero
     * Ones
     * Identity
     * Diagonal
    */

    static Matrix zeros(const Shape shape) {
      return Matrix(shape, Type{});
    }

    static Matrix ones(const Shape shape) {
      return Matrix(shape, Type{1});
    }

    static Matrix identity(const std::size_t dim) {
      Matrix<Type> res({dim, dim});
      for (std::size_t i = 0; i < dim; ++i) {
            res(i,i) = Type{1};
      }
      return res;
    }

    static Matrix diagonal(const std::vector<Type>& arr) {
      std::size_t dim = arr.size();
      Matrix<Type> res({dim, dim});
      for (std::size_t i = 0; i < dim; ++i) {
            res(i,i) = arr[i];
      }
      return res;
    }

    // printing contents of matrix
    void print() const {
      for (std::size_t i = 0; i < shape[0]; ++i) {
        for (std::size_t j = 0; j < shape[1]; ++j) {
          std::cout << (*this)(i,j) << ",";
        }
        std::cout << std::endl;
      }
      std::cout << std::endl;
    }

    // modifies matrix entry
    Type& operator()(std::size_t row, std::size_t col) {
      assert(row < shape[0] && col < shape[1]);
      return data[row * shape[1] + col];
    }

    // only reads variable
    const Type& operator()(std::size_t row, std::size_t col) const {
      assert(row < shape[0] && col < shape[1]);
      return data[row * shape[1] + col];
    }

    bool operator==(const Matrix& other) const {
      return data == other.data
          && same_shape(other);
    }

    bool operator!=(const Matrix& other) const {
      return !(*this == other);
    }

    /*
     * Basic Operators for Matrix arithemetic:
     * Addition
     * Subtraction
     * Scalar Multiplication
     */

    // Modification by addition
    Matrix& operator+=(const Matrix& other) {
      assert(same_shape(other));
      for (size_t i = 0; i < data.size(); ++i) {
        data[i] += other.data[i];
      }
      return *this;
    }

    // Creates another matrix via addition
    Matrix operator+(const Matrix& other) const {
      Matrix res = *this;
      res += other;
      return res;
    }

    // Modification by subtraction
    Matrix& operator-=(const Matrix& other) {
      assert(same_shape(other));
      for (size_t i = 0; i < data.size(); ++i) {
        data[i] -= other.data[i];
      }
      return *this;
    }

    // Creates another matrix via subtraction
    Matrix operator-(const Matrix& other) const {
      Matrix res = *this;
      res -= other;
      return res;
    }

    Matrix& operator*=(const Type& n) {
      for (Type& x : data) {
        x *= n;
      }
      return *this;
    }

    // Creates another matrix via scalar multiplication
    Matrix operator*(const Type& n) const {
      Matrix res = *this;
      res *= n;
      return res;
    }

    // and below is scalar division
    Matrix& operator/=(const Type& n) {
      for (Type& x : data) {
        x /= n;
      }
      return *this;
    }

    Matrix operator/(const Type& n) const {
      Matrix res = *this;
      res /= n;
      return res;
    }

    /*
     * Very Basic Linear Algebra Methods:
     * Matrix Multiplication
     * Transposing of Matrix
     */
    
    // multiplies matrices
    Matrix operator*(const Matrix& other) const {
      assert(can_multiply(other));
      Matrix res({shape[0], other.shape[1]});
      for (std::size_t i = 0; i < res.shape[0]; ++i) {
        for (std::size_t j = 0; j < res.shape[1]; ++j) {
          for (std::size_t k =0; k < shape[1]; ++k) {
            res(i, j) += (*this)(i, k) * other(k, j);
          }
        }
      }
      return res;
    }

    // tranposes the matrix
    Matrix transpose() const {
      Matrix res({shape[1], shape[0]});
      for (std::size_t i = 0; i < shape[0]; ++i) {
        for (std::size_t j = 0; j < shape[1]; ++j) {
          res(j, i) = (*this)(i, j);
        }
      }
      return res;
    }

    /*
     * Getter functions
     */

    std::size_t rows() const {
      return shape[0];
    }

    std::size_t cols() const {
      return shape[1];
    }
    
    std::size_t size() const {
      return data.size();
    }

    const std::vector<Type> values() const {
      return data;
    }

    const Shape& get_shape() const {
      return shape;
    }

    /*
     * Setter functions and quality of life stuff idk
     */
    Type& operator[](std::size_t i) {
        assert(i < data.size());
        return data[i];
    }

    const Type& operator[](std::size_t i) const {
        assert(i < data.size());
        return data[i];
    }
    void fill(const Type& T) {
      for (auto& x : data) {
        x = T;
      }
    }

    bool empty() const {
      return data.empty();
    }

    bool is_square() const {
      return shape.is_square();
    }

    bool is_symmetric() const {
      return (*this) == (*this).transpose();
    }

    bool same_shape(const Matrix& other) const {
      return shape == other.shape;
    }

    bool can_multiply(const Matrix& other) const {
      return shape[1] == other.shape[0];
    }
};
}
