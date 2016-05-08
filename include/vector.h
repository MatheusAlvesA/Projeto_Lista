#ifndef _FLISTA_H_
#define _FLISTA_H_

#include <stdexcept>
#include <iostream>

typedef unsigned long long int size_type;

template <typename T>
class Vector {

public:

class iterator {
  public:

  iterator (Vector<T> &ptr) : current (0), ponteiro(ptr) {/*vazio*/};

  const T operator* () const {return this->ponteiro.vetor[this->current];} // retorna o atual
  iterator &operator++ (int); // incrementa para o proximo
  iterator &operator-- (int); // decrementa para o anterior
  bool operator== (const iterator &rhs) const {if(ponteiro.vetor[current] == *rhs) return true; else return false;} // compara os dados com outro interator
  bool operator!= (const iterator &rhs) const {if(ponteiro.vetor[current] != *rhs) return true; else return false;} // compara os dados com outro interator

  protected:

  size_type current; // index atual no vector
  Vector<T> &ponteiro; /* isso é uma referencia para evitar que quando essa classe iterator
  seja destruida acabe destruindo jundo o Vector recebido. */
  friend class Vector <T>;
 };

Vector(); // aloca o vetor inicial

~Vector(); // deleta o que precisar

Vector(const Vector &); // já começa como copia de outro

T & operator[]( size_type idx);// checar limites
T & at ( size_type idx ); // checar limite
size_type capacity() const {return capacidade;}
void reserve( size_type new_capacity ); // aloca mais espaço

size_type size() const {return _size;} // retorna tamanho
bool empty() const {if(_size <= 0) return true; else return false;} // verifica se está vazio
void clear(); // apaga tudo
const T & front(); // retorna o primeiro
const T & back(); // retorna o ultimo
void push_back(const T &x); // coloca no final
const T & pop_back(); //remove e retorna o ultimo
void assign(const T &value); // coloca value em todos os elementos

private:

T *vetor;
size_type _size = 0;
size_type capacidade = 10;

};

#include "vector.cpp"
#endif
