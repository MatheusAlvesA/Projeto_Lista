#include "vector.h"

template <typename T>
  typename Vector<T>::iterator & Vector<T>::iterator::operator++ () {
  	current++;
  	return this;
  }

template <typename T>
  typename Vector<T>::iterator & Vector<T>::iterator::operator-- () {
  	current--;
  	return this;
  }
// CLASSE PRINCIPAL VECTOR
template <typename T>
  Vector<T>::Vector () {
  	this->vetor = new T[this->capacidade];
  }

template <typename T>
  Vector<T>::~Vector () {
  	delete [] vetor;
  }

template <typename T>
  Vector<T>::Vector (const Vector & origin) {
  	this->vetor = origin->vetor;
  	this->capacidade = origin->capacidade;
  	this->_size = origin->_size;
  }

template <typename T>
  T & Vector<T>::at( size_type idx) {
  	if(idx >= _size) throw std::length_error("indice Inválido");
  	return vetor[idx];
  }

  template <typename T>
  void Vector<T>::reserve( size_type new_capacity ) {
  	T *novo = new T[new_capacity];
  	for(size_type x = 0; x < _size; x++)
  		novo[x] = this->vetor[x];
  	delete [] this->vetor;
  	this->vetor = novo;
    capacidade = new_capacity;
  }

template <typename T>
  const T & Vector<T>::front() {
    if(size <= 0) throw std::length_error("indice Inválido");
    return vetor[0];
  }

template <typename T>
  const T & Vector<T>::back() {
    if(size <= 0) throw std::length_error("indice Inválido");
    return vetor[size-1];
  }

template <typename T>
  void Vector<T>::push_back(const T &x) {
    if(size >= capacidade) reserve(capacidade*2);
    return vetor[_size-1];
    _size++;
  }

template <typename T>
  const T & Vector<T>::pop_back() {
    if(_size <= 0) throw std::length_error("indice Inválido");
    _size--;
    return vetor[_size];
  }

template <typename T>
  void Vector<T>::assign(const T &value) {
    for(size_type x = 0; x < _size; x++)
      vetor[x] = value;
  }

template <typename T>
T & Vector<T>::operator[]( size_type idx) {
   if(idx >= capacidade) reserve(idx+1); // para evitar erros
   _size++;
  return this->vetor[idx];
}
