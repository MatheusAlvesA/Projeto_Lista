#ifndef _FLISTA_H_
#define _FLISTA_H_


template <typename T>
class Forward_list {

private:

struct Node {
  T data;
  // <! Data field
  Node *next; // <! Pointer to the next node in the list .
  // <! Basic constructor .
  Node(const T & d = T() , Node *p = nullptr, Node *n = nullptr) : data(d), next(n) { /* Empty */ }
};

public:

class const_iterator {
  public :
  const_iterator ( );
  const T &operator* () const;
  const_iterator &operator++ ();
  // ++ it ;
  const_iterator operator++ (int); // it ++;
  const_iterator &operator-- ();
  // -- it ;
  const_iterator operator-- (int); // it - -;
  bool operator== (const const_iterator &rhs) const;
  bool operator!= (const const_iterator &rhs) const;
  protected:
  Node *current;
  const_iterator (Node* p) : current (p) {};
  friend class Forward_list <T>;
 };

class iterator : public const_iterator {
 public:
  iterator() : const_iterator() {/* Vazio */}
  const T & operator* () const;
  T & operator* ();

  iterator & operator++ ();
  iterator   operator++ (int);
  iterator & operator-- ();
  iterator   operator-- (int);

 protected:
  iterator (Node *p) : const_iterator(p) {};
  friend class Forward_list <T>;
};

Forward_list();

~Forward_list();

Forward_list(const Forward_list &);
Forward_list(Forward_list &&);

Forward_list & operator= (const Forward_list &);
Forward_list & operator= (Forward_list &&);

iterator before_begin ();
const_iterator cbefore_begin ( ) const;
iterator begin ();
const_iterator cbegin ( ) const;
iterator end ();
const_iterator cend ( ) const;
int size() const;
bool empty() const;
void clear();
T & front();
const T & front() const;
T & back();
const T & back() const;
void push_front(const T &x);
void push_back(const T &x);
void pop_front();
void pop_back();
void assign(const T &value);
/*template <class InItr>
void assing (InItr first, InItr last);*/
void assign (std::initializer_list <T> ilist);
iterator insert_after(const_iterator itr, const T &x);
iterator insert_after(const_iterator pos, std::initializer_list <T> ilist);
iterator erase_after(const_iterator itr);
iterator erase_after(const_iterator first , const_iterator last );
const_iterator find(const T &x) const;

private:
int m_size;
Node *m_head;
Node *m_tail;
};

#include "Flist.cpp"
#endif
