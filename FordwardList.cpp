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
T& ForwardList::front(void){
    return head->value();
}
template <typename T>
T& ForwardList::back(void){
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
Node<T>* ForwardList::pop_back(void){}
template <typename T>
Node<T>* ForwardList::pop_front(void){}
template <typename T>
T& ForwardList::operator[] (const int&){}

template <typename T>
bool ForwardList::empty(void){}
template <typename T>
unsigned int ForwardList::size(void){
    int value=0;
    head->next();
    while(head!=nullptr){
        head=head->nex();
        value++;
    }
    return value;
}
template <typename T>
void ForwardList::clear(void){}
template <typename T>
ForwardList<int>& ForwardList::sort(void){}
template <typename T>
ForwardList<int>& ForwardList::reverse(void){}
template <typename T>
std::ostream& ForwardList::operator << (const ForwardList<int>&, std::ostream&){}