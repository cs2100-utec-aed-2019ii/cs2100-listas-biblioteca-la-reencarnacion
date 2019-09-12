//
// Created by VICTOR on 11/09/2019.
//

#ifndef UNTITLED19_DOUBLELISTNODE_H
#define UNTITLED19_DOUBLELISTNODE_H


#include "Node.h"

template <typename T>
class DoubleListNode : public Node<T> {
public:
    DoubleListNode<T>* next;
    DoubleListNode<T>* prev;
    DoubleListNode(){
        next = NULL;
        prev = NULL;
    }
    DoubleListNode(T data) : Node<T>(data){
        next = NULL;
        prev = NULL;
    }
    ~DoubleListNode(){}


};

#endif //UNTITLED19_DOUBLELISTNODE_H
