//
// Created by VICTOR on 11/09/2019.
//

#ifndef UNTITLED19_DOUBLELIST_H
#define UNTITLED19_DOUBLELIST_H


#include <iostream>
#include "DoubleListNode.h"
#include "List.h"
#include "Iterator.h"
using namespace std;

template <typename T>
class DoubleList : public List<T> {
public:
    typedef DoubleListNode<T> node_t;
protected:
    node_t *head = nullptr;
    node_t *tail = nullptr;
public:

    friend class DoubleIterator;
    class DoubleIterator : public Iterator<node_t> {
    public:
        typedef typename Iterator<node_t>::node_t node_t;
        typedef typename Iterator<node_t>::value_t value_t;

        DoubleIterator(node_t* _pointer = nullptr) : Iterator<node_t>(_pointer){}
        ~DoubleIterator(){}
    };

    DoubleList(): List<T>() {}

    DoubleList(DoubleList& lista): List<T>(){
        if (!lista.empty()) {
            node_t* temp = lista.get_head();
            while (temp) {
                push_back(**temp);
                temp = temp->next;
            }
        }
    }

    DoubleList(T* lista, int n): List<T>(){
        for (int i = 0; i < n; ++i) {
            push_back(lista[i]);
        }
    }

    DoubleList(Node<T>* node): List<T>(){
        head = new DoubleListNode<T>();
        tail = new DoubleListNode<T>();
        head->value = **node;
        tail = head;
    }

    DoubleList(int num): List<T>(){
        for (int i = 0; i < num; i++){
            push_back(NULL);
        }
    }

    T& front() override {
        return **head;
    }

    T& back()override {
        return **tail;
    }

    void push_front(const T& data) override {
        node_t *new_node = new DoubleListNode<T>(data);
        node_t *temp = head;

        if (!head) {
            head = new_node;
            tail = head;
        } else {
            head->prev = new_node;
            new_node->next = head;
            head = new_node;
        }
    }
    void push_back(const T& data) override {
        node_t *new_node = new DoubleListNode<T>(data);
        node_t *temp = tail;

        if (!tail) {
            head = new_node;
            tail = head;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }

    Node<T>* pop_back() override {
        node_t* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        return temp;
    }
    Node<T>* pop_front() override {
        node_t* temp = head;
        head = head->next;
        return temp;
    }

    T& operator[] (const unsigned int& index) override {
        node_t* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return **temp;
    }

    bool empty() override {
        return head == nullptr;
    }

    unsigned int size() override {
        int cont = 0;
        node_t* temp = head;
        while (temp) {
            temp = temp->next;
            cont++;
        }
        return cont;
    }

    void clear() override {
        head = nullptr;
        tail = nullptr;
    }

    void erase(Node<T>* node) override {
        node_t* temp1 = head->next;
        node_t* temp2 = head;
        while (temp1 != node) {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next = temp1->next;
    }

    void insert(Node<T>* node, const T& n) override {
        node_t* temp1 = head;
        node_t* temp2;
        DoubleListNode<T>* new_node = new DoubleListNode<T>();
        for(int i = 0; i < n; i++){
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        new_node->value = **node;
        temp1->next = new_node;
        new_node->next = temp2;
    }

    void drop(const T& value) override {
        node_t* temp1 = head->next;
        node_t* temp2 = head;
        while (temp1 != nullptr) {
            if(**temp1 == value){
                temp2->next = temp1->next;
            }
            temp2 = temp1;
            temp1 = temp1->next;
        }
    }

    DoubleIterator begin() {
        return DoubleIterator(head);
    }

    DoubleIterator end() {
        return DoubleIterator(tail);
    }
    DoubleListNode<T>* get_head() {
        return head;
    }

    inline friend std::ostream& operator << (std::ostream& os, const DoubleList<T>& lista){
        DoubleListNode<T> *temp = lista.head;
        if (!lista.head) {
            std::cout << "La Lista esta vacia " << std::endl;
        } else {
            while (temp) {
                std::cout << **temp << " -> ";
                if (!temp->next) std::cout << "NULL";
                temp = temp->next;
            }
        }
        std::cout << std::endl << std::endl;
        return os;
    }

    ~DoubleList(){}
};

#endif //UNTITLED19_DOUBLELIST_H
