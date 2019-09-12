//
// Created by VICTOR on 11/09/2019.
//

#ifndef UNTITLED19_DOUBLELIST_H
#define UNTITLED19_DOUBLELIST_H


#include <iostream>
#include "DoubleListNode.h"
#include "List.h"
using namespace std;

template <typename T>
class DoubleList : public List<T> {
protected:
    DoubleListNode<T> *head = NULL;
    DoubleListNode<T> *tail = NULL;
public:
    DoubleList(): List<T>() {}

    DoubleList(DoubleList& lista): List<T>(){
        if (!lista.empty()) {
            DoubleListNode<T>* temp = lista.get_head();
            while (temp != NULL) {
                push_back(temp->data);
                temp = temp->next;
            }
            tail = temp;
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
        head->data = node->data;
        tail = head;
    }

    DoubleList(int num): List<T>(){
        for (int i = 0; i < num; i++){
            push_back(NULL);
        }
    }

    T& front() override {
        return head->data;
    }

    T& back()override {
        return tail->data;
    }

    void push_front(const T& data) override {
        DoubleListNode<T> *new_node = new DoubleListNode<T>(data);
        DoubleListNode<T> *temp = head;

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
        DoubleListNode<T> *new_node = new DoubleListNode<T>(data);
        DoubleListNode<T> *temp = tail;

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
        DoubleListNode<T>* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        return temp;
    }
    Node<T>* pop_front() override {
        DoubleListNode<T>* temp = head;
        head = head->next;
        return temp;
    }

    T& operator[] (const unsigned int& index) override {
        DoubleListNode<T>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    bool empty() override {
        return head == NULL;
    }

    unsigned int size() override {
        int cont = 0;
        DoubleListNode<T>* temp = head;
        while (temp != NULL) {
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
        DoubleListNode<T>* temp1 = head->next;
        DoubleListNode<T>* temp2 = head;
        while (temp1 != node) {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next = temp1->next;
    }

    void insert(Node<T>* node, const T& n) override {
        DoubleListNode<T>* temp1 = head;
        DoubleListNode<T>* temp2;
        DoubleListNode<T>* new_node = new DoubleListNode<T>();
        for(int i = 0; i < n; i++){
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        new_node->data = node->data;
        temp1->next = new_node;
        new_node->next = temp2;
    }

    void drop(const T& value) override {
        DoubleListNode<T>* temp1 = head->next;
        DoubleListNode<T>* temp2 = head;
        while (temp1 != NULL) {
            if(temp1->data == value){
                temp2->next = temp1->next;
            }
            temp2 = temp1;
            temp1 = temp1->next;
        }
    }

    void print() override {
        DoubleListNode<T> *temp = head;
        if (!head) {
            std::cout << "La Lista esta vacia " << std::endl;
        } else {
            while (temp) {
                std::cout << temp->data << " -> ";
                if (!temp->next) std::cout << "NULL";
                temp = temp->next;
            }
        }
        std::cout << std::endl << std::endl;
    }

    DoubleListNode<T>* get_head() {
        return head;
    }

    ~DoubleList(){}
};

#endif //UNTITLED19_DOUBLELIST_H
