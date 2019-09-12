//
// Created by VICTOR on 11/09/2019.
//

#ifndef UNTITLED19_FORWARDLISTNODE_H
#define UNTITLED19_FORWARDLISTNODE_H

#include "Node.h"

template <typename T>
class ForwardListNode : public Node<T> {
public:
    ForwardListNode<T>* next;
    ForwardListNode(){
        next = NULL;
    }
    ForwardListNode(T data) : Node<T>(data){
        next = NULL;
    }
    ~ForwardListNode(){}


};

#endif //UNTITLED19_FORWARDLISTNODE_H
