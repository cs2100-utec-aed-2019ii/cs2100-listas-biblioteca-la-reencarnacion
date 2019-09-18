//
// Created by VICTOR on 11/09/2019.
//

#ifndef UNTITLED19_NODE_H
#define UNTITLED19_NODE_H

#include <iostream>

template <typename T>
class Node {
public:
    typedef T value_t;

    value_t value;

    Node(value_t _value) : value(_value){}
    ~Node(){}

    T& operator * () {
        return value;
    }
};

#endif //UNTITLED19_NODE_H
