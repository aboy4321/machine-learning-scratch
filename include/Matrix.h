#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <tuple>
#include <cassert>

template <typename Type> class Matrix {
  private:
    std::size_t rows, cols;

  public:
    std::vector<Type> data;
    // constructors

    // default constructor
    Matrix(std::size_t rows, std::size_t cols)
      : rows(rows), cols(cols), data({}) {
      data.resize(rows * cols, Type());
    }

    // creates matrix filled with inputted values
    Matrix(std::size_t rows, std::size_t cols, Type val)
      : rows(rows), cols(cols), data({}) {
      data.resize(rows * cols, val);
      }

    // creates matrix from inputted vector
    Matrix(std::vector<Type> arr);

    // no params constructor
    Matrix() : rows(0), cols(0), data({}) {}

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

    /*
     * Basic Operators for Matrix arithemetic:
     * Addition
     * Subtraction
     * Scalar Multiplication
     */

    // Modification by addition
    Matrix& operator+=(const Matrix& other) {
      assert(rows == other.rows && cols == other.cols);
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
      assert(rows == other.rows && cols == other.cols);
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

    // Modification by scalar multiplication 
    Matrix operator*=(const double n) {
      for (std::size_t i = 0; i < data.size(); ++i) {
        data[i] *= n;
      }
      return *this;
    }

    // Creates another matrix via scalar multiplication
    Matrix operator*(const double n) const {
      Matrix res = *this;
      res *= n;
      return res;
    }

    /*
     * Linear Algebra Methods:
     * 
     * Matrix Multiplication
     * Transposing of Matrix
     *
     */
    
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

    /*
     * Getter functions
     */

    std::size_t get_rows() const {
      return rows;
    }

    std::size_t get_cols() const {
      return cols;
    }
    
    std::size_t get_size() const {
      return rows * cols;
    }

    std::tuple<std::size_t, std::size_t> get_shape() const {
      return std::make_tuple(rows, cols);
    }
};

