//
// Created by VICTOR on 28/08/2019.
//

#include "FordwardList.h"
#include <iostream>

template <typename T>
ForwardList<T>::ForwardList(void){}
template <typename T>
ForwardList<T>::~ForwardList(void){}

template <typename T>
T& ForwardList<T>::front(void){}
template <typename T>
T& ForwardList<T>::back(void){}
        
ForwardList::void push_back(const T& element){}
ForwardList::void push_front(const T& element){}

template <typename T>
Node<T>* ForwardList<T>::pop_back(void){}
template <typename T>
Node<T>* ForwardList<T>::pop_front(void){}
template <typename T>
T& ForwardList<T>::operator[] (const int&){}

template <typename T>
bool ForwardList<T>::empty(void){}
template <typename T>
unsigned int ForwardList<T>::size(void){}
template <typename T>
void ForwardList<T>::clear(void){}
template <typename T>
ForwardList<T>& ForwardList<T>::sort(void){}
template <typename T>
ForwardList<T>& ForwardList<T>::reverse(void){}
template <typename T>
ostream& ForwardList<T>::std::operator << (const ForwardList<T>&, std::ostream&){}