#pragma once

#include <Shape.h>
#include <vector>
#include <cassert>

namespace nerd {

template <typename Type>
class Tensor {
  private:
    Shape shape;
    std::vector<Type> data;
    Shape stride;

  public:
    Tensor(const Shape shape, std::vector<Type>& data)
      : shape(shape), data(shape.size()) {}

    Tensor(const Shape shape, Type val)
      : shape(shape), data(shape.size(), val) {} 
  




    Shape shape() {
      return shape;
    }
}
  
}
