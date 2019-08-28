//
// Created by VICTOR on 28/08/2019.
//

#include "FordwardList.h"

ForwardList::ForwardList(void){}
ForwardList::~ForwardList(void){}

ForwardList::T& front(void){}
ForwardList::T& back(void){}
        
ForwardList::void push_back(const T& element){}
ForwardList::void push_front(const T& element){}

ForwardList::Node<T>* pop_back(void){}
ForwardList::Node<T>* pop_front(void){}
ForwardList::T& operator[] (const int&){}
        
ForwardList::bool empty(void){}
ForwardList::unsigned int size(void){}
ForwardList::void clear(void){}
ForwardList::ForwardList& sort(void){}
ForwardList::ForwardList& reverse(void){}
ForwardList::std::ostream& operator << (const ForwardList&, std::ostream&){}