#include "Flist.h"

template <typename T>
Forward_list<T>::Forward_list() {
// falta implemetar
}

template <typename T>
Forward_list<T>::Forward_list(const Forward_list &) {
// falta implemetar
}

template <typename T>
Forward_list<T>::Forward_list(Forward_list &&) {
// falta implemetar
}

template <typename T>
Forward_list<T>::~Forward_list() {
// falta implemetar
}

template <typename T>
Forward_list<T> & Forward_list<T>::operator= (const Forward_list &) {
// falta implemetar
}

template <typename T>
Forward_list<T> & Forward_list<T>::operator= (Forward_list &&) {
// falta implemetar
}

template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::before_begin () {
// falta implemetar
}

template <typename T>
typename Forward_list<T>::const_iterator Forward_list<T>::cbefore_begin() const {
// falta implemetar
}

template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::begin () {
// falta implemetar
}

template <typename T>
typename Forward_list<T>::const_iterator Forward_list<T>::cbegin() const {
// falta implemetar
}

template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::end() {
// falta implemetar
}

template <typename T>
typename Forward_list<T>::const_iterator Forward_list<T>::cend() const {
// falta implemetar
}

template <typename T>
int Forward_list<T>::size() const {
// falta implemetar
	return 0;
}

template <typename T>
bool Forward_list<T>::empty() const {
// falta implemetar
	return false;
}

template <typename T>
void Forward_list<T>::clear() {
// falta implemetar
}

template <typename T>
const T & Forward_list<T>::front() const {
// falta implemetar
}

template <typename T>
T & Forward_list<T>::back() {
// falta implemetar
}

template <typename T>
void Forward_list<T>::pop_front() {
// falta implemetar
}

template <typename T>
void Forward_list<T>::pop_back() {
// falta implemetar
}

template <typename T>
void Forward_list<T>::assign(const T &value) {
// falta implemetar
}
/*
template <class InItr, typename T>
void Forward_list<InItr>::assing (InItr first, InItr last) {
	// falta implementar
}
*/
template <typename T>
void Forward_list<T>::assign (std::initializer_list <T> ilist) {
// falta implemetar
}

template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::insert_after(typename Forward_list<T>::const_iterator itr, const T &x) {
// falta implemetar
}

template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::insert_after(typename Forward_list<T>::const_iterator pos, std::initializer_list <T> ilist) {
// falta implemetar
}

template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::erase_after(typename Forward_list<T>::const_iterator itr) {
// falta implemetar
}

template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::erase_after(typename Forward_list<T>::const_iterator first , typename Forward_list<T>::const_iterator last ) {
// falta implemetar
}

template <typename T>
typename Forward_list<T>::const_iterator Forward_list<T>::find(const T &x) const {
// falta implemetar
}

// ITERATOR CONSTANT

template <typename T>
Forward_list<T>::const_iterator::const_iterator() {
// falta implemetar
}

template <typename T>
const T & Forward_list<T>::const_iterator::operator* () const {
// falta implemetar
}

template <typename T>
typename Forward_list<T>::const_iterator & Forward_list<T>::const_iterator::operator++ () {
// falta implemetar
}

template <typename T>
typename Forward_list<T>::const_iterator Forward_list<T>::const_iterator::operator++ (int) {
// falta implemetar
}

template <typename T>
typename Forward_list<T>::const_iterator & Forward_list<T>::const_iterator::operator-- () {
// falta implemetar
}

template <typename T>
typename Forward_list<T>::const_iterator Forward_list<T>::const_iterator::operator-- (int) {
// falta implemetar
}

template <typename T>
bool Forward_list<T>::const_iterator::operator== (const typename Forward_list<T>::const_iterator &rhs) const {
// falta implemetar
	return false;
}

template <typename T>
bool Forward_list<T>::const_iterator::operator!= (const typename Forward_list<T>::const_iterator &rhs) const {
// falta implemetar
	return false;
}

// ITERATOR

template <typename T>
const T & Forward_list<T>::iterator::operator* () const {
// falta implemetar
}

template <typename T>
T & Forward_list<T>::iterator::operator* () {
// falta implemetar
}

template <typename T>
typename Forward_list<T>::iterator & Forward_list<T>::iterator::operator++ () {
// falta implemetar
}

template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::iterator::operator++ (int) {
// falta implemetar
}

template <typename T>
typename Forward_list<T>::iterator & Forward_list<T>::iterator::operator-- () {
// falta implemetar
}

template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::iterator::operator-- (int) {
// falta implemetar
}

