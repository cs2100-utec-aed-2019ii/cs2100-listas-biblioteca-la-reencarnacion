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
ForwardList::T& front(void){
    return head->value();
}
template <typename T>
ForwardList::T& back(void){
    Node *temp=nullptr;
    temp=head;
    while(temp!=nullptr)
        temp=temp->next();
    return temp->value;
}

template <typename T>   
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
template <typename T>
ForwardList::Node<T>* pop_back(void){}
template <typename T>
ForwardList::Node<T>* pop_front(void){}
template <typename T>
ForwardList::T& operator[] (const int&){}
        
template <typename T>
ForwardList::bool empty(void){}
template <typename T>
ForwardList::unsigned int size(void){
    int value=0;
    head->next();
    while(head!=nullptr){
        head=head->nex();
        value++;
    }
    return value;
}
template <typename T>
ForwardList::void clear(void){}
template <typename T>
ForwardList::ForwardList& sort(void){}
template <typename T>
ForwardList::ForwardList& reverse(void){}
template <typename T>
ForwardList::std::ostream& operator << (const ForwardList&, std::ostream&){}