#pragma once

#include <vector>
#include <cstddef>
#include <cassert>
#include <iostream>
#include <algorithm>

namespace nerd {

class Shape {
  private:
    std::vector<std::size_t> dim;

  public:
    Shape() = default;
    Shape(std::initializer_list<std::size_t> dim) : dim(dim) {}
    Shape(std::size_t rank) : dim(rank, 1) {}

    std::size_t& operator[](std::size_t i) {
      assert(i < dim.size());
      return dim[i];
    }

    const std::size_t& operator[](std::size_t i) const {
      assert(i < dim.size());
      return dim[i];
    }


    friend std::ostream& operator<<(std::ostream& os, const Shape& shape) {
      os << "{";
      for (size_t i = 0; i < shape.rank(); ++i) {
          os << shape[i];
          if (i + 1 != shape.rank()) {
              os << ", ";
          }
      }
      os << "}";
      return os;
    }
    auto begin() { return dim.begin(); }
  
    auto end() { return dim.end(); }
    
    auto begin() const { return dim.begin(); }

    auto end() const { return dim.end(); }

    std::size_t rank() const {
      return dim.size();
    }
    
    void remove() {
      dim.erase(std::remove(dim.begin(), dim.end(), 1), dim.end());
    }

    std::size_t ndim() const {
      return rank();
    }

    std::size_t size() const {
      if (dim.empty()) return 0;
      std::size_t total = 1;
      for (std::size_t d : dim) {
        total *= d;
      }
      return total;
    }

    bool operator==(const Shape& other) const {
        return dim == other.dim;
    }

    bool operator!=(const Shape& other) const {
        return !(*this == other);
    }

    bool is_matrix() const {
      return dim.size() == 2;
    }

    bool is_square() const {
      return dim[0] == dim[1];
    }

    bool empty() const {
      return dim.empty();
    }
};

}
