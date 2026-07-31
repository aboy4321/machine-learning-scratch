#pragma once

#include <cmath>
#include <vector>
#include <tuple>

namespace nerd {
  

template <typename Type>
class Adam {
  private:
    // our parameters
    static std::vector<Type> theta;

    // also known as stepsize or learning rate
    static double alpha;

    // exponential decay rates of moment estimations
    static std::tuple<double, double> betas;

    // baby number to prevent division by 0
    static double eps;

    // first moment vector
    static std::vector<double> m;
    
    // second moment vector
    static std::vector<double> v;

    // number of epochs
    static int t;

  public:

    // default constructor from paper
    Adam(std::vector<Type>& theta, double alpha = 0.01, std::tuple<double, double> betas = {0.9, 0.999}, double eps = 10e-8)
      : theta(theta) alpha(alpha), betas(betas), eps(eps), t(0) {
        m = std::vector<Type>(theta.size(), 0.0);
        v = std::vector<Type>(theta.size(), 0.0);

      }

    /*
    void update(std::vector<Type> grads) {
      ++t;
      while (t  < theta.size()) {

        m[t] = betas[0] * m[t-1] + (1 - betas[0]) * grad_t;

      }
    }
    */
};
}
