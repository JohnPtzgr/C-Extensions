#pragma once

#include <vector>

template <typename ValuesType>
class Matrix {
  std::vector<ValuesType> values;
 public:
  std::pair<size_t, size_t> shape;
  Matrix(const Matrix&);
  Matrix(const ValuesType&, const std::pair<size_t, size_t>&);
  ValuesType& operator[](size_t);
  ValuesType operator[](size_t) const;
  ValuesType& get(size_t, size_t);
  ValuesType get(size_t, size_t) const;
  Matrix operator+(const Matrix&) const;
  Matrix operator-(const Matrix&) const;
  Matrix& operator+=(const Matrix&);
  Matrix& operator-=(const Matrix&);
  Matrix operator*(const Matrix&) const;
  Matrix operator/(const Matrix&) const;
  Matrix& operator*=(const Matrix&);
  Matrix& operator/=(const Matrix&);
  bool operator==(const Matrix&) const;
  Matrix inverse() const;
};