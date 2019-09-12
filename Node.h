//
// Created by VICTOR on 11/09/2019.
//

#ifndef UNTITLED19_NODE_H
#define UNTITLED19_NODE_H

#include <iostream>

template <typename T>
class Node {
public:
    T data;

    Node() {
        data = NULL;
    }
    Node(T data) : data(data){}
    ~Node(){}
};

#endif //UNTITLED19_NODE_H
