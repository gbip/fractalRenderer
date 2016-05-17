//
// Created by paul on 16/05/16.
//

#include <cmath>

namespace Math {

// Struct representing a complex number
struct Complex {
  double Real;
  double Imaginary;
  ~Complex(){};
};

// Classic math operator
inline Complex operator+(const Complex &a, const Complex &b) {
  return {a.Real + b.Real, a.Imaginary + b.Imaginary};
}
inline Complex operator*(const Complex &a, const Complex &b) {
  return {a.Real * b.Real - a.Imaginary * b.Imaginary,
          a.Real * b.Real + a.Imaginary * b.Imaginary};
}

// Return the module of a complex number
inline double module(const Complex &a) {
  return sqrt((a.Real, 2) + pow(a.Imaginary, 2));
};
}
