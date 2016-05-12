#ifndef _FLISTA_H_
#define _FLISTA_H_

#include <stdexcept>
#include <iostream>

template <typename T>
class Forward_list {

private:

struct Node {
  T data;
  // <! Data field
  Node *next; // <! Pointer to the next node in the list .
  // <! Basic constructor .
  Node(const T & d = T() , Node *p = nullptr, Node *n = nullptr) : data(d), next(n) { /* Empty  */}
};
int m_size;
Node m_head;
Node m_tail;

public:

class const_iterator {
    
  public :
 
  const_iterator ();
  const T &operator* () const;
  
  const_iterator &operator++ (); // ++ it ;
  const_iterator &operator++ (int);
  Node *operator= (const Node* n) {current = n;}
  bool operator== (const const_iterator &rhs) const {return (this->current == rhs.current);}
  bool operator!= (const const_iterator &rhs) const {return (this->current != rhs.current);}
  Node *ptr() {return current;}
  
  protected:
      
  Node *current;
  const_iterator (Node* p) : current (p) {};
  friend class Forward_list <T>;
 };

class iterator : public const_iterator {
    
 public:
     
  iterator() : const_iterator() {/* Vazio */}
  iterator (Node *p) : const_iterator(p) {};
  
  T & operator* ();
  iterator & operator++ ();
  iterator & operator++ (int);

 protected:

  friend class Forward_list <T>;
};

Forward_list();

~Forward_list();

Forward_list(const Forward_list &);

Forward_list & operator= (const Forward_list &);

iterator before_begin (); // retorna um iterador para o nó cabeça
const_iterator cbefore_begin ( ) const;
iterator begin (); // retorna um iterador para o inicio
const_iterator cbegin ( ) const;
iterator end (); // retorna um iterador para o final
const_iterator cend ( ) const;
int size() const; // retorna o numero de elementos
bool empty() const; // retorna verdadeiro se estiver vazio e falso se não
void clear(); // apaga todos os elementos e reinicia tudo
T & front(); // retorna o valor do primeiro elemento
const T & front() const;
T & back(); // retorna o valor do ultimo elemento
const T & back() const;
void push_front(const T &x); // coloca um valor na frente da lista
void push_back(const T &x); // coloca um valor atrás da lista
T pop_front(); // remove e retorna o primeiro nó
T pop_back(); // remove e retorna o ultimo nó
void assign(const T &value); // seta todos os elementos com o valor de value
const_iterator insert_after(const_iterator itr, const T &x); // insere um elemento apos o iterador passado
iterator erase_after(const_iterator itr); // deleta o elemento apos o iterador passado
iterator erase_after(const_iterator first , const_iterator last ); // deleta tudo que estiver entre os dois iteradores
const_iterator find(const T &x) const; // encontra e retorna um iterador para o elemento passado
};

#include "Flist.cpp"
#endif
