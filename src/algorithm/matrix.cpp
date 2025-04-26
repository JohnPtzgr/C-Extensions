#include "matrix.hpp"


template <typename ValuesType>
Matrix<ValuesType>::Matrix(const Matrix<ValuesType>& other) {
  this->shape = other.shape;
  this->values = other.values;
}

template <typename ValuesType>
Matrix<ValuesType>::Matrix(const ValuesType& value, const std::pair<size_t, size_t>& shape) {
  this->shape = shape;
  this->values = std::vector<ValuesType>(shape.first * shape.second, ValuesType(0));
  for (size_t i = 0; i < shape.first; ++i) {
    this->get(i, i) = value;
  }
}

template <typename ValuesType>
ValuesType& Matrix<ValuesType>::operator[](size_t index) {
  return this->values[index];
}

template <typename ValuesType>
ValuesType Matrix<ValuesType>::operator[](size_t index) const {
  return this->values[index];
}

template <typename ValuesType>
ValuesType& Matrix<ValuesType>::get(size_t i, size_t j) {
  return this->values[i * this->shape.second + j];
}

template <typename ValuesType>
ValuesType Matrix<ValuesType>::get(size_t i, size_t j) const {
  return this->values[i * this->shape.second + j];
}

template <typename ValuesType>
Matrix<ValuesType>& Matrix<ValuesType>::operator+=(const Matrix<ValuesType>& other) {
  for (size_t i = 0; i < this->shape.first; ++i) {
    for (size_t j = 0; j < this->shape.second; ++j) {
      get(i, j) += other.get(i, j);
    }
  }
  return *this;
}

template <typename ValuesType>
Matrix<ValuesType>& Matrix<ValuesType>::operator-=(const Matrix<ValuesType>& other) {
  return *this;
}

template <typename ValuesType>
Matrix<ValuesType> Matrix<ValuesType>::operator+(const Matrix<ValuesType>& other) const {
  Matrix new_matrix = Matrix(this);
  new_matrix += other;
  return new_matrix;
}

template <typename ValuesType>
Matrix<ValuesType> Matrix<ValuesType>::operator-(const Matrix<ValuesType>& other) const {
  Matrix new_matrix = Matrix(this);
  new_matrix -= other;
  return new_matrix;
}

template <typename ValuesType>
Matrix<ValuesType>& Matrix<ValuesType>::operator*=(const Matrix<ValuesType>& other) {
  for (size_t i = 0; i < shape.first; ++i) {
    std::vector<ValuesType> row(shape.second, ValuesType(0));
    for (size_t j = 0; j < shape.second; ++j) {
      for (size_t k = 0; k < other.shape.second; ++k) {
        row[j] += get(i, k) * other.get(k, j);
      }
    }
    for (size_t j = 0; j < shape.second; ++j) {
      get(i, j) = row[j];
    }
  }
  return *this;
}

template <typename ValuesType>
Matrix<ValuesType> Matrix<ValuesType>::inverse() const {
  return Matrix(ValuesType(1));
}

template <typename ValuesType>
Matrix<ValuesType>& Matrix<ValuesType>::operator/=(const Matrix<ValuesType>& other) {

  return *this;
}

template <typename ValuesType>
Matrix<ValuesType> Matrix<ValuesType>::operator*(const Matrix<ValuesType>& other) const {
  Matrix new_matrix = Matrix(this);
  new_matrix += other;
  return new_matrix;
}

template <typename ValuesType>
Matrix<ValuesType> Matrix<ValuesType>::operator/(const Matrix<ValuesType>& other) const {
  Matrix new_matrix = Matrix(this);
  new_matrix -= other;
  return new_matrix;
}