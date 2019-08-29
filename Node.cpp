//
// Created by VICTOR on 28/08/2019.
//

#include "Node.h"

template<typename T>
Node<T>::Node() {
    value = NULL;
    next = NULL;
}

template<typename T>
Node<T>::Node(T value) : value(value){
    next = NULL;

}

template<typename T>
Node<T>::~Node() {}