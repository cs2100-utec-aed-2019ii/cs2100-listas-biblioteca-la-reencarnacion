//
// Created by VICTOR on 11/09/2019.
//

#ifndef UNTITLED19_LIST_H
#define UNTITLED19_LIST_H

#include "Node.h"

template <typename T>
class List{
protected:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
public:
    List(){}

    explicit List(List& lista);

    explicit List(T* lista, int n);

    explicit List(Node<T>* node);

    explicit List(int num);

    ~List(){}

    virtual T& front() = 0;
    virtual T& back() = 0;

    virtual void push_front(const T& element) = 0;
    virtual void push_back(const T& element) = 0;

    virtual Node<T>* pop_back() = 0;
    virtual Node<T>* pop_front() = 0;

    virtual T& operator[] (const unsigned int& num) = 0;

    virtual bool empty(void) = 0;
    virtual unsigned int size(void) = 0;
    virtual void clear() = 0;

    virtual void erase(Node<T>* node) = 0;
    virtual void insert(Node<T>* node, const T& n) = 0;
    virtual void drop(const T& value) = 0;


    //List<T>& sort();
    //virtual List<T>& reverse() = 0;

    inline friend std::ostream& operator << (std::ostream& os, const List<T>& lista);

    List& operator<< (const T& _value){
        this->push_back(_value);
        return *this;
    }

    List& operator>> (const T& _value){
        this->push_front(_value);
        return *this;
    }
};

#endif //UNTITLED19_LIST_H

