//
// Created by VICTOR on 11/09/2019.
//

#ifndef UNTITLED19_FORWARDLISTNODE_H
#define UNTITLED19_FORWARDLISTNODE_H

#include "Node.h"

template <typename T>
class ForwardListNode : public Node<T> {
public:
    typedef typename Node<T>::value_t value_t;

    ForwardListNode<T>* next;

    ForwardListNode(const T& _value = NULL) : Node<T>(_value),next(nullptr){}

    ~ForwardListNode(){}

};

#endif //UNTITLED19_FORWARDLISTNODE_H
