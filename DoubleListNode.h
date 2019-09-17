//
// Created by VICTOR on 11/09/2019.
//

#ifndef UNTITLED19_DOUBLELISTNODE_H
#define UNTITLED19_DOUBLELISTNODE_H


#include "Node.h"

template <typename T>
class DoubleListNode : public Node<T> {
public:
    typedef typename Node<T>::value_t value_t;

    DoubleListNode<T>* next;
    DoubleListNode<T>* prev;
    DoubleListNode(const T& _value = NULL) : Node<T>(_value), next(nullptr),prev(nullptr){}
    ~DoubleListNode(){}


};

#endif //UNTITLED19_DOUBLELISTNODE_H
