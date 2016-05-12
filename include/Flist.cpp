#include "Flist.h"

template <typename T>
Forward_list<T>::Forward_list() {
    this->m_head = Forward_list<T>::Node(); //alocando o no cabeça
    this->m_tail = Forward_list<T>::Node(); //alocando o no calda
    this->m_head.next = &m_tail;
    this->m_size = 0;
}

template <typename T>
Forward_list<T>::Forward_list(const Forward_list & original) {
    this->m_head = original.m_head; // setando o no cabeça
    this->m_htail = original.m_tail; // setando o no rabo
    this->m_size = original.m_size; // setando o tamanho
}

template <typename T>
Forward_list<T>::~Forward_list() {
    this->clear(); // deletando todos os nodes
}

template <typename T>
Forward_list<T> & Forward_list<T>::operator= (const Forward_list &original) {
    this->m_head = original.m_head; // setando o no cabeça
    this->m_htail = original.m_tail; // setando o no rabo
    this->m_size = original.m_size; // setando o tamanho
}

template <typename T>
void Forward_list<T>::push_front(const T &x) {
  Node *novo = new Node();
  novo->next = this->m_head.next; // aponta para o primeiro
  novo->data = x;
  m_head.next = novo; // registrando esse como sendo o novo primeiro
  this->m_size++;
}

template <typename T>
void Forward_list<T>::push_back(const T &x) {
  Node *novo = new Node();
  Node *auxiliar = &this->m_head;
  novo->data = x;
  novo->next = &(this->m_tail); // aponta para o ultimo
  while(auxiliar->next != &m_tail) // precorre até achar o ultimo
      auxiliar = auxiliar->next;
  auxiliar->next = novo; // registrando esse como sendo o novo ultimo
  this->m_size++;
}

template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::before_begin () {
  Forward_list<T>::iterator iterador;
  iterador = &(this->m_head); // apenas retorna o nó cabeça
  return iterador;
}

template <typename T>
typename Forward_list<T>::const_iterator Forward_list<T>::cbefore_begin() const {
  Forward_list<T>::const_iterator iterador;
  iterador = &(this->m_head);
  return iterador;
}

template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::begin () {
  Forward_list<T>::iterator iterador;
  if(this->m_head.next == &this->m_tail) iterador = &this->m_head; // seta como o nó cabeça caso não tenha elementos
  else iterador = this->m_head.next;
  return iterador;
}

template <typename T>
typename Forward_list<T>::const_iterator Forward_list<T>::cbegin() const {
  Forward_list<T>::const_iterator iterador;
  if(this->m_head.next == &this->m_tail) iterador = &this->m_head;
  else iterador = this->m_head.next;
  return iterador;
}

template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::end() {
  Forward_list<T>::iterator iterador;
    Node *auxiliar = &(this->m_head); // cria um auxiliar para não perder o inicio da lista
    while(auxiliar->next != &this->m_tail) // só para no final da lista
        auxiliar = auxiliar->next;
  iterador = auxiliar; // cria iterator
  return iterador;
}

template <typename T>
typename Forward_list<T>::const_iterator Forward_list<T>::cend() const {
  Forward_list<T>::const_iterator iterador;
    Node *auxiliar = &(this->m_head); // cria um auxiliar para não perder o inicio da lista
    while(auxiliar->next != &this->m_tail) // só para no final da lista
        auxiliar = auxiliar->next;
  iterador = auxiliar;
  return iterador;
}

template <typename T>
int Forward_list<T>::size() const {
    return this->m_size;
}

template <typename T>
bool Forward_list<T>::empty() const {
    if(this->m_size <= 0) return true;
    else return false;
}

template <typename T>
void Forward_list<T>::clear() {
    Node *auxiliar = this->m_head.next;
    Node *temp;
    while(auxiliar->next != nullptr) { // só para no final da lista
        temp = auxiliar->next; // guarda para não perder quando executar o delete
        delete auxiliar;
        auxiliar = temp;
        this->m_size--;
    }
    this->m_head.next = &(this->m_tail); // recria o nó inicial
}

template <typename T>
const T & Forward_list<T>::front() const {
    if(this->m_head.next == &this->m_tail) throw std::runtime_error("Lista vazia");
    return (this->m_head.next)->data; // retorna o que está logo após o inicio
}

template <typename T>
T & Forward_list<T>::front() {
    if(this->m_head.next == &this->m_tail) throw std::runtime_error("Lista vazia");
    return (this->m_head.next)->data;
}


template <typename T>
T & Forward_list<T>::back() {
   if(this->m_head.next == &this->m_tail) throw std::runtime_error("Lista vazia");

    Node *auxiliar = this->m_head.next;
    while(auxiliar->next != &(this->m_tail)) { // percorre até achar o ultimo
        auxiliar = auxiliar->next;
    }
    return auxiliar->data;
}

template <typename T>
T Forward_list<T>::pop_front() {
   if(this->m_head.next == &(this->m_tail)) throw std::runtime_error("Lista vazia");
   Node *temp = this->m_head.next; // o primeiro node
   this->m_head.next = this->m_head.next->next; // pulando o primeiro node
   T retorno = temp->data;
   delete temp;
   this->m_size--;
   return retorno;
}

template <typename T>
T Forward_list<T>::pop_back() {
   if(this->m_head.next == &this->m_tail) throw std::runtime_error("Lista vazia");

    Node *auxiliar = this->m_head.next;
    Node *anterior = &(this->m_head); // note que dutante o loop essa variavel estára sempre um nó antes do auxiliar
    while(auxiliar->next != &(this->m_tail)) { // para quando achar o penultimo
        auxiliar = auxiliar->next;
        anterior = anterior->next; // sempre um passo atrás
    }

    T retorno = auxiliar->data; // valor de retorno do ultimo
    delete auxiliar; // deletando
    anterior->next = &(this->m_tail); // reamarrando os nós
    this->m_size--;
    return retorno;
}

template <typename T>
void Forward_list<T>::assign(const T &value) {
    Node *auxiliar = this->m_head.next; // começa no primeiro elemento
    while(auxiliar->next != nullptr) { // se chegou na cauda ele para
        auxiliar->data = value; // seta o valor...
        auxiliar = auxiliar->next; //... e vai pro próximo
     }
}

template <typename T>
typename Forward_list<T>::const_iterator Forward_list<T>::insert_after(typename Forward_list<T>::const_iterator itr, const T &x) {
  Node *temp = new Node(); // criando o novo nó
  temp->data = x;
  temp->next = (itr.ptr())->next; // esse novo nó aponta para o que vem depois do nó atraz dele
  (itr.ptr())->next = temp; // o que está atrz agora aponta pra ele
  this->m_size++;
  itr++;
  return itr;
}

template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::erase_after(typename Forward_list<T>::const_iterator itr) {
  Node *temp = (itr.ptr())->next->next; // o elemento depois do que seŕa deletado
  delete (itr.ptr())->next; // deletando o que precisa
  (itr.ptr())->next = temp; // reajustando a lista
  this->m_size--;
  itr++; // andando um no
  Forward_list<T>::iterator retorno = itr.ptr(); //convertendo de const para iterator
  return retorno;
}

template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::erase_after(typename Forward_list<T>::const_iterator first , typename Forward_list<T>::const_iterator last ) {
  Node *temp = (first.ptr())->next; // o elemento depois do que seŕa deletado
  Node *bk_first = first.ptr();
  first++;
  while(first != last) { // a sobrecarga de operador é util aqui
    first++;
    delete temp;
    temp = first.ptr();
    this->m_size--; // cada vez que deleta diminui um
  }
  first++; // andando um no
  bk_first->next = last.ptr(); // reamarra os nós
  Forward_list<T>::iterator retorno = first.ptr(); //convertendo de const para iterator
  return retorno;
}

template <typename T>
typename Forward_list<T>::const_iterator Forward_list<T>::find(const T &x) const {
  typename Forward_list<T>::const_iterator temp(this->m_head.next); // começa pelo primeiro
  while(temp.ptr() != nullptr) { // e não para até achar
    if(*temp == x) return temp;
    else temp++;
  } // ou não achar
  throw std::runtime_error("Valor não encontrado"); // eue não encontrei então não posso retornar
}

// ITERATOR CONSTANT

template <typename T>
Forward_list<T>::const_iterator::const_iterator() {
    this->current = nullptr;
}

template <typename T>
const T & Forward_list<T>::const_iterator::operator* () const {
    if(this->current == nullptr) throw std::runtime_error("Iterator vazio");
    return this->current->data; // retorna o dado para onde está apontando agora
}

template <typename T>
typename Forward_list<T>::const_iterator & Forward_list<T>::const_iterator::operator++ () {
    if(this->current == nullptr) throw std::runtime_error("Iterator vazio");
    this->current = this->current->next; // anda uma unidade
    return this;
}

template <typename T>
typename Forward_list<T>::const_iterator & Forward_list<T>::const_iterator::operator++ (int) {
    if(this->current == nullptr) throw std::runtime_error("Iterator vazio");
    this->current = this->current->next;
    return *this;
}

// ITERATOR

template <typename T>
T & Forward_list<T>::iterator::operator* () {
if(this->current == nullptr) throw std::runtime_error("Iterator vazio");
    return this->current->data;
}

template <typename T>
typename Forward_list<T>::iterator & Forward_list<T>::iterator::operator++ (int) {
    if(this->current == nullptr) throw std::runtime_error("Iterator vazio");
    this->current = this->current->next;
    return *this;
}
