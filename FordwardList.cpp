//
// Created by VICTOR on 28/08/2019.
//

#include "FordwardList.h"
#include <iostream>

ForwardList::ForwardList(void){}
ForwardList::~ForwardList(void){}

ForwardList::T& front(void){}
ForwardList::T& back(void){}
        
void ForwardList<T>::push_back(const T& element){
    Node *node = nullptr;
    Node *final = new Node(element);
    node = head;
    while(node != nullptr){
        node = node->next();
    }
    node->next() = final;
}
template <typename T>
void ForwardList<T>::push_front(const T& element){
    Node *node = new Node(element);
    node->next() = head;
    head = node;
}

ForwardList::Node<T>* pop_back(void){}
ForwardList::Node<T>* pop_front(void){}
ForwardList::T& operator[] (const int&){}
        
ForwardList::bool empty(void){}
ForwardList::unsigned int size(void){}
ForwardList::void clear(void){}
ForwardList::ForwardList& sort(void){}
ForwardList::ForwardList& reverse(void){}
ForwardList::std::ostream& operator << (const ForwardList&, std::ostream&){}