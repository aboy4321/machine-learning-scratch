#pragma once

#include <Shape.h>
#include <vector>
#include <cassert>
#include <iostream>

namespace nerd {

template <typename Type>
class Tensor {
  private:
    Shape shape;
    std::vector<Type> data;
    Shape strides;    

    Shape compute_strides() {
      Shape strides(shape.rank());

      for (int i = shape.rank() - 2; i >= 0; --i ) {
        strides[i] = strides[i + 1] * shape[i + 1];
      }

      return strides;
    }

  public:

    Tensor() = default;

    Tensor(const Shape& shape, const Type& val)
      : shape(shape), data(shape.size(), val) {
        strides = compute_strides();
      } 
  
    Type& operator[](std::size_t i) {
      assert(i < data.size());
      return data[i];
    }

    const Type& operator[](std::size_t i) const {
      assert(i < data.size());
      return data[i];
    }

    /*
    Type& operator()(std::vector<std::size_t>& index) {
      assert(index.size() == shape.rank());
      return data[]
    }
    */

    /*
     * Iterators
     */ 

    auto begin() {
      return data.begin();
    }

    auto end() {
      return data.end();
    }
    auto begin() const {
      return data.begin();
    }

    auto end() const {
      return data.end();
    }

    void fill(const Type& T) {
      for (auto& x : data) {
        x = T;
      }
    }

    bool empty() {
      return data.empty();
    }

    bool same_shape(Tensor& other) {
      return shape == other.shape;
    }

    /* 
     * getter functions
     */ 

    // return shape of tensor
    const Shape& get_shape() const {
      return shape;
    }

    const Shape get_strides() const {
      return strides;
    }


    // return size of tensor/number of elements 
    std::size_t size() const {
      return shape.size();
    }
};
  
}
