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
protected:
    DoubleListNode<T> *head =  NULL;
    DoubleListNode<T> *tail =  NULL;
public:
    DoubleCircularList(): List<T>() {}

    DoubleCircularList(DoubleCircularList& lista): List<T>(){
        if (!lista.empty()) {
            DoubleListNode<T>* temp = lista.get_head();
            while (temp->next != lista.get_head()) {
                push_back(temp->data);
                temp = temp->next;
            }
            push_back(temp->data);
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
        head->data = node->data;
        head->next = head;
        tail = head;
    }

    DoubleCircularList(int num): List<T>(){
        for (int i = 0; i < num; i++){
            push_back(NULL);
        }
    }

    T& front() override {
        return head->data;
    }

    T& back()override {
        DoubleListNode<T>* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        return temp->data;
    }

    void push_front(const T& data) override {
        DoubleListNode<T> *new_node = new DoubleListNode<T>(data);
        DoubleListNode<T> *temp = head;

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
        DoubleListNode<T> *new_node = new DoubleListNode<T>(data);
        DoubleListNode<T> *temp = tail;

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
        DoubleListNode<T>* temp = tail;
        tail = tail->prev;
        tail->next = head;
        return temp;
    }
    Node<T>* pop_front() override {
        DoubleListNode<T>* temp = head;
        head = head->next;
        while (temp->next != head){
            temp = temp->next;
        }
        temp->next = head;
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
        while (temp->next != head) {
            temp = temp->next;
            cont++;
        }
        return cont;
    }

    void clear() override {
        head = NULL;
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
        while (temp1->next != head) {
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
            while (temp->next != head){
                std::cout << temp->data << " -> ";
                temp = temp->next;
            }
            std::cout << temp->data;
        }
        std::cout << std::endl << std::endl;
    }

    DoubleListNode<T>* get_head() {
        return head;
    }

    ~DoubleCircularList(){}
};

#endif //UNTITLED19_DOUBLECIRCULARLIST_H
