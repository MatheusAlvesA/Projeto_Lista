#include "Flist.h"

template <typename T>
List<T>::List() {
    this->m_head = List<T>::Node(); //alocando o no cabeça
    this->m_tail = List<T>::Node(); //alocando o no calda
    this->m_head.next = &m_tail;
    this->m_tail.last = &m_head;
    this->m_size = 0;
}

template <typename T>
List<T>::List(const List & original) {
    this->m_head = original.m_head; // setando o no cabeça
    this->m_tail = original.m_tail; // setando o no rabo
    this->m_size = original.m_size; // setando o tamanho
}

template <typename T>
List<T>::~List() {
    this->clear(); // deletando todos os nodes
}

template <typename T>
List<T> & List<T>::operator= (const List &original) {
    this->m_head = original.m_head; // setando o no cabeça
    this->m_tail = original.m_tail; // setando o no rabo
    this->m_size = original.m_size; // setando o tamanho
}

template <typename T>
void List<T>::push_front(const T &x) {
  Node *novo = new Node();
  novo->next = this->m_head.next; // aponta para o primeiro
  novo->last = &(this->m_head); // o aterior é o cabeça
  this->m_head.next->last = novo; // aponta para o primeiro
  novo->data = x;
  m_head.next = novo; // registrando esse como sendo o novo primeiro
  this->m_size++;
}

template <typename T>
void List<T>::push_back(const T &x) {
  Node *novo = new Node();
  novo->next = &this->m_tail; // aponta para o tail
  novo->last = this->m_tail.last; // aponta para o que antes era o ultimo
  this->m_tail.last->next = novo; // aponta para o novo ultimo
  novo->data = x;
  m_tail.last = novo; // registrando esse como sendo o novo ultimo
  this->m_size++;
}

template <typename T>
typename List<T>::iterator List<T>::before_begin () {
  List<T>::iterator iterador;
  iterador = &(this->m_head); // apenas retorna o nó cabeça
  return iterador;
}

template <typename T>
typename List<T>::const_iterator List<T>::cbefore_begin() const {
  List<T>::const_iterator iterador;
  iterador = &(this->m_head);
  return iterador;
}

template <typename T>
typename List<T>::iterator List<T>::begin () {
  List<T>::iterator iterador;
  if(this->m_head.next == &this->m_tail) iterador = &this->m_head; // seta como o nó cabeça caso não tenha elementos
  else iterador = this->m_head.next;
  return iterador;
}

template <typename T>
typename List<T>::const_iterator List<T>::cbegin() const {
  List<T>::const_iterator iterador;
  if(this->m_head.next == &this->m_tail) iterador = &this->m_head;
  else iterador = this->m_head.next;
  return iterador;
}

template <typename T>
typename List<T>::iterator List<T>::end() {
  List<T>::iterator iterador;
  if(this->m_tail.last == &this->m_head) iterador = &this->m_tail; // seta como o nó cabeça caso não tenha elementos
  else iterador = this->m_tail.last;
  return iterador;
}

template <typename T>
typename List<T>::const_iterator List<T>::cend() const {
  List<T>::const_iterator iterador;
  if(this->m_tail.last == &this->m_head) iterador = &this->m_tail; // seta como o nó cabeça caso não tenha elementos
  else iterador = this->m_tail.last;
  return iterador;
}

template <typename T>
int List<T>::size() const {
    return this->m_size;
}

template <typename T>
bool List<T>::empty() const {
    if(this->m_size <= 0) return true;
    else return false;
}

template <typename T>
void List<T>::clear() {
    Node *auxiliar = this->m_head.next;
    Node *temp;
    while(auxiliar->next != nullptr) { // só para no final da lista
        temp = auxiliar->next; // guarda para não perder quando executar o delete
        delete auxiliar;
        auxiliar = temp;
        this->m_size--; // vai se tornar zero no final desse loop
    }
    this->m_head.next = &(this->m_tail); // recria o nó inicial
    this->m_tail.last = &(this->m_head);
}

template <typename T>
const T & List<T>::front() const {
    if(this->m_head.next == &this->m_tail) throw std::runtime_error("Lista vazia");
    return (this->m_head.next)->data; // retorna o que está logo após o inicio
}

template <typename T>
T & List<T>::front() {
    if(this->m_head.next == &this->m_tail) throw std::runtime_error("Lista vazia");
    return (this->m_head.next)->data;
}


template <typename T>
T & List<T>::back() {
   if(this->m_head.next == &this->m_tail) throw std::runtime_error("Lista vazia");
    return (this->m_tail.last)->data;
}

template <typename T>
T List<T>::pop_front() {
   if(this->m_head.next == &(this->m_tail)) throw std::runtime_error("Lista vazia");
   Node *temp = this->m_head.next; // o primeiro node
   this->m_head.next = temp->next; // pulando o primeiro node
   temp->next->last = &this->m_head;
   T retorno = temp->data;
   delete temp;
   this->m_size--;
   return retorno;
}

template <typename T>
T List<T>::pop_back() {
   if(this->m_head.next == &this->m_tail) throw std::runtime_error("Lista vazia");
   Node *temp = this->m_tail.last; // o primeiro node
   this->m_tail.last = temp->last; // pulando o primeiro node
   temp->last->next = &this->m_tail;
   T retorno = temp->data;
   delete temp;
   this->m_size--;
    return retorno;
}

template <typename T>
void List<T>::assign(const T &value) {
    Node *auxiliar = this->m_head.next; // começa no primeiro elemento
    while(auxiliar->next != nullptr) { // se chegou na cauda ele para
        auxiliar->data = value; // seta o valor...
        auxiliar = auxiliar->next; //... e vai pro próximo
     }
}

template <typename T>
typename List<T>::const_iterator List<T>::insert_after(typename List<T>::const_iterator itr, const T &x) {
  Node *temp = new Node(); // criando o novo nó
  temp->data = x;
  temp->next = (itr.ptr())->next; // esse novo nó aponta para o que vem depois do nó atraz dele
  temp->last = itr.ptr();
  (itr.ptr())->next->last = temp; // muito complexo, melhor não comentar
  (itr.ptr())->next = temp; // o que está atraz agora aponta pra ele
  this->m_size++;
  itr++;
  return itr;
}

template <typename T>
typename List<T>::iterator List<T>::erase_after(typename List<T>::const_iterator itr) {
  Node *temp = (itr.ptr())->next; // apontando para o que vai ser deletado
  (itr.ptr())->next = temp->next;
  temp->next->last = itr.ptr();
  delete temp;
  this->m_size--;
  itr++;
  List<T>::iterator retorno = itr.ptr();
  return retorno;
}

template <typename T>
typename List<T>::iterator List<T>::erase_after(typename List<T>::const_iterator first , typename List<T>::const_iterator last ) {
  Node *temp = (first.ptr())->next; // apontando para o que vai ser deletado
  (first.ptr())->next = last.ptr();
  (last.ptr())->last = first.ptr();
  first++;
  while(first != last) { // a sobrecarga de operador é util aqui
    first++;
    delete temp;
    temp = first.ptr();
    this->m_size--; // cada vez que deleta diminui um
  }
  first++; // andando um no
  List<T>::iterator retorno = first.ptr(); //convertendo de const para iterator
  return retorno;
}

template <typename T>
typename List<T>::const_iterator List<T>::find(const T &x) const {
  typename List<T>::const_iterator temp(this->m_head.next); // começa pelo primeiro
  while(temp.ptr() != nullptr) { // e não para até achar
    if(*temp == x) return temp;
    else temp++;
  } // ou não achar
  throw std::runtime_error("Valor não encontrado"); // eue não encontrei então não posso retornar
}

// ITERATOR CONSTANT

template <typename T>
List<T>::const_iterator::const_iterator() {
    this->current = nullptr;
}

template <typename T>
const T & List<T>::const_iterator::operator* () const {
    if(this->current == nullptr) throw std::runtime_error("Iterator vazio");
    return this->current->data; // retorna o dado para onde está apontando agora
}

template <typename T>
typename List<T>::const_iterator & List<T>::const_iterator::operator++ () {
    if(this->current == nullptr) throw std::runtime_error("Iterator vazio");
    this->current = this->current->next; // anda uma unidade
    return this;
}

template <typename T>
typename List<T>::const_iterator & List<T>::const_iterator::operator++ (int) {
    if(this->current == nullptr) throw std::runtime_error("Iterator vazio");
    this->current = this->current->next;
    return *this;
}

template <typename T>
typename List<T>::const_iterator & List<T>::const_iterator::operator-- () {
    if(this->current == nullptr) throw std::runtime_error("Iterator vazio");
    this->current = this->current->last; // volta uma unidade
    return this;
}

template <typename T>
typename List<T>::const_iterator & List<T>::const_iterator::operator-- (int) {
    if(this->current == nullptr) throw std::runtime_error("Iterator vazio");
    this->current = this->current->last; // volta uma unidade
    return *this;
}

// ITERATOR

template <typename T>
T & List<T>::iterator::operator* () {
if(this->current == nullptr) throw std::runtime_error("Iterator vazio");
    return this->current->data;
}

template <typename T>
typename List<T>::iterator & List<T>::iterator::operator++ (int) {
    if(this->current == nullptr) throw std::runtime_error("Iterator vazio");
    this->current = this->current->next;
    return *this;
}

template <typename T>
typename List<T>::iterator & List<T>::iterator::operator-- (int) {
    if(this->current == nullptr) throw std::runtime_error("Iterator vazio");
    this->current = this->current->last;
    return *this;
}
