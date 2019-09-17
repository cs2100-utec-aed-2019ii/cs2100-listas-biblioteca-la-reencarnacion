//
// Created by VICTOR on 11/09/2019.
//

#ifndef UNTITLED19_DOUBLECIRCULARLIST_H
#define UNTITLED19_DOUBLECIRCULARLIST_H

#include <iostream>
#include "DoubleListNode.h"
#include "List.h"
using namespace std;

template <typename T>
class DoubleCircularList : public List<T> {
public:
    typedef DoubleListNode<T> node_t;
protected:
    node_t *head = nullptr;
    node_t *tail = nullptr;
public:

    friend class DoubleCircularIterator;
    class DoubleCircularIterator : public Iterator<node_t> {
    public:
        typedef typename Iterator<node_t>::node_t node_t;
        typedef typename Iterator<node_t>::value_t value_t;

        DoubleCircularIterator(node_t* _pointer = nullptr) : Iterator<node_t>(_pointer){}
        ~DoubleCircularIterator(){}

        DoubleCircularIterator& operator++() {
            Iterator<node_t>::pointer = Iterator<node_t>::pointer->next;
            return *this;
        }
        DoubleCircularIterator& operator++(int n) {
            for (int i = 0; i < n; i++){
                Iterator<node_t>::pointer = Iterator<node_t>::pointer->next;
            }
            return *this;
        }
    };

    DoubleCircularList(): List<T>() {}

    DoubleCircularList(DoubleCircularList& lista): List<T>(){
        if (!lista.empty()) {
            node_t* temp = lista.get_head();
            while (temp->next != lista.get_head()) {
                push_back(**temp);
                temp = temp->next;
            }
            push_back(**temp);
            tail = temp;
        }
    }

    DoubleCircularList(T* lista, int n): List<T>(){
        for (int i = 0; i < n; ++i) {
            push_back(lista[i]);
        }
    }

    DoubleCircularList(Node<T>* node): List<T>(){
        head = new DoubleListNode<T>();
        head->value = **node;
        head->next = head;
        tail = head;
    }

    DoubleCircularList(int num): List<T>(){
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
            head->next = head;
            head->prev = head;
            tail = head;
        } else {
            head->prev = new_node;
            new_node->next = head;
            while (temp->next != head){
                temp = temp->next;
            }
            head = new_node;
            temp->next = head;
            head->prev = temp;
        }
    }
    void push_back(const T& data) override {
        node_t* new_node = new DoubleListNode<T>(data);
        node_t* temp = tail;

        if (!tail) {
            head = new_node;
            head->next = head;
            head->prev = head;
            tail = head;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
            tail->next = head;
        }
    }

    Node<T>* pop_back() override {
        node_t* temp = tail;
        tail = tail->prev;
        tail->next = head;
        return temp;
    }
    Node<T>* pop_front() override {
        node_t* temp = head;
        head = head->next;
        while (temp->next != head){
            temp = temp->next;
        }
        temp->next = head;
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
        return head == NULL;
    }

    unsigned int size() override {
        int cont = 0;
        node_t* temp = head;
        while (temp->next != head) {
            temp = temp->next;
            cont++;
        }
        return cont;
    }

    void clear() override {
        head = NULL;
        tail = NULL;
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
        node_t* new_node = new DoubleListNode<T>();
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
        while (temp1->next != head) {
            if(**temp1 == value){
                temp2->next = temp1->next;
            }
            temp2 = temp1;
            temp1 = temp1->next;
        }
    }

    DoubleCircularIterator begin() {
        return DoubleCircularIterator(head);
    }

    DoubleCircularIterator end() {
        return DoubleCircularIterator(tail);
    }

    DoubleListNode<T>* get_head() {
        return head;
    }

    inline friend std::ostream& operator << (std::ostream& os, const DoubleCircularList<T>& lista){
        node_t *temp = lista.head;
        if (!lista.head) {
            std::cout << "La Lista esta vacia " << std::endl;
        } else {
            while (temp->next != lista.head) {
                std::cout << **temp << " -> ";
                if (!temp->next) std::cout << "NULL";
                temp = temp->next;
            }
            std::cout << **temp;
        }
        std::cout << std::endl << std::endl;
        return os;
    }

    ~DoubleCircularList(){}
};

#endif //UNTITLED19_DOUBLECIRCULARLIST_H
