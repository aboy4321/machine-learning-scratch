#pragma once

#include <vector>
#include <cstddef>

namespace nerd {

class Shape {
  private:
    std::vector<std::size_t> dim;

  public:
    Shape(std::initializer_list<std::size_t> dims) : dim(dims) {}

    std::size_t ndim() const {
      return dim.size();
    }

    std::size_t size() const {
      std::size_t total = 1;
      for (std::size_t d : dim) {
        total *= d;
      }
      return total;
    }


}

  
}
