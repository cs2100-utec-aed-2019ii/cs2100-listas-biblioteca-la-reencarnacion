//
// Created by VICTOR on 11/09/2019.
//

#ifndef UNTITLED19_CIRCULARLIST_H
#define UNTITLED19_CIRCULARLIST_H

#include <iostream>
#include "ForwardListNode.h"
#include "List.h"
using namespace std;

template <typename T>
class CircularList : public List<T> {
public:
    typedef ForwardListNode<T> node_t;
protected:
    node_t *head = nullptr;
    node_t *tail = nullptr;
public:

    friend class CircularIterator;
    class CircularIterator : public Iterator<node_t> {
    public:
        typedef typename Iterator<node_t>::node_t node_t;
        typedef typename Iterator<node_t>::value_t value_t;

        CircularIterator(node_t* _pointer = nullptr) : Iterator<node_t>(_pointer){}
        ~CircularIterator(){}

    };

    CircularList(): List<T>() {}

    CircularList(CircularList& lista): List<T>(){
        if (!lista.empty()) {
            node_t* temp = lista.get_head();
            while (temp->next != lista.get_head()) {
                push_back(**temp);
                temp = temp->next;
            }
            push_back(**temp);
        }
    }

    CircularList(T* lista, int n): List<T>(){
        for (int i = 0; i < n; ++i) {
            push_back(lista[i]);
        }
    }

    CircularList(Node<T>* node): List<T>(){
        head = new ForwardListNode<T>();
        head->value = **node;
        head->next = head;
    }

    CircularList(int num): List<T>(){
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
        node_t *new_node = new ForwardListNode<T>(data);
        node_t *temp = head;

        if (!head) {
            head = new_node;
            tail = head;
            head->next = tail;
        } else {
            new_node->next = head;
            while (temp->next != head){
                temp = temp->next;
            }
            head = new_node;
            temp->next = head;
        }
    }

    void push_back(const T& data) override {
        node_t *new_node = new ForwardListNode<T>(data);
        node_t *temp = head;

        if (!head) {
            head = new_node;
            tail = head;
            head->next = tail;
        } else {
            while (temp != tail) {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->next = head;
            tail = new_node;
        }
    }

    Node<T>* pop_back() override {
        node_t* temp1 = head;
        node_t* temp2;
        while (temp1 != tail) {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        tail = temp2;
        temp2->next = head;
        return temp1;
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
        return head == nullptr;
    }

    unsigned int size() override {
        int cont = 0;
        node_t* temp = head;
        while (temp != tail) {
            temp = temp->next;
            cont++;
        }
        return cont+1;
    }

    void clear() override {
        head = nullptr;
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
        node_t* new_node = new ForwardListNode<T>();
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

    CircularIterator begin() {
        return CircularIterator(head);
    }

    CircularIterator end() {
        node_t* temp1 = head;
        while (temp1->next != head) {
            temp1 = temp1->next;
        }
        return CircularIterator(temp1);
    }

    ForwardListNode<T>* get_head() {
        return head;
    }

    inline friend std::ostream& operator << (std::ostream& os, const CircularList<T>& lista){
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

    ~CircularList(){}
};

#endif //UNTITLED19_CIRCULARLIST_H
