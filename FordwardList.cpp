//
// Created by VICTOR on 28/08/2019.
//

#include "FordwardList.h"
#include <iostream>

template <typename T>
ForwardList<T>::ForwardList(void){}
template <typename T>
ForwardList<T>::~ForwardList(void){}

ForwardList::T& front(void){
    return head->value();
}
ForwardList::T& back(void){
    Node *temp=nullptr;
    temp=head;
    while(temp!=nullptr)
        temp=temp->next();
    return temp->value;
}
        
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
ForwardList::unsigned int size(void){
    int value=0;
    head->next();
    while(head!=nullptr){
        head=head->nex();
        value++;
    }
    return value;
}
ForwardList::void clear(void){}
ForwardList::ForwardList& sort(void){}
ForwardList::ForwardList& reverse(void){}
ForwardList::std::ostream& operator << (const ForwardList&, std::ostream&){}