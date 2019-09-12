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
protected:
    ForwardListNode<T> *head =  NULL;
public:
    CircularList(): List<T>() {}

    CircularList(CircularList& lista): List<T>(){
        if (!lista.empty()) {
            ForwardListNode<T>* temp = lista.get_head();
            while (temp->next != lista.get_head()) {
                push_back(temp->data);
                temp = temp->next;
            }
            push_back(temp->data);
        }
    }

    CircularList(T* lista, int n): List<T>(){
        for (int i = 0; i < n; ++i) {
            push_back(lista[i]);
        }
    }

    CircularList(Node<T>* node): List<T>(){
        head = new ForwardListNode<T>();
        head->data = node->data;
        head->next = head;
    }

    CircularList(int num): List<T>(){
        for (int i = 0; i < num; i++){
            push_back(NULL);
        }
    }

    T& front() override {
        return head->data;
    }

    T& back()override {
        ForwardListNode<T>* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        return temp->data;
    }

    void push_front(const T& data) override {
        ForwardListNode<T> *new_node = new ForwardListNode<T>(data);
        ForwardListNode<T> *temp = head;

        if (!head) {
            head = new_node;
            head->next = head;
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
        ForwardListNode<T> *new_node = new ForwardListNode<T>(data);
        ForwardListNode<T> *temp = head;

        if (!head) {
            head = new_node;
            head->next = head;
        } else {
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->next = head;
        }
    }

    Node<T>* pop_back() override {
        ForwardListNode<T>* temp1 = head;
        ForwardListNode<T>* temp2;
        while (temp1->next != head) {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next = head;
        return temp1;
    }
    Node<T>* pop_front() override {
        ForwardListNode<T>* temp = head;
        head = head->next;
        while (temp->next != head){
            temp = temp->next;
        }
        temp->next = head;
        return temp;
    }

    T& operator[] (const unsigned int& index) override {
        ForwardListNode<T>* temp = head;
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
        ForwardListNode<T>* temp = head;
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
        ForwardListNode<T>* temp1 = head->next;
        ForwardListNode<T>* temp2 = head;
        while (temp1 != node) {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next = temp1->next;
    }

    void insert(Node<T>* node, const T& n) override {
        ForwardListNode<T>* temp1 = head;
        ForwardListNode<T>* temp2;
        ForwardListNode<T>* new_node = new ForwardListNode<T>();
        for(int i = 0; i < n; i++){
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        new_node->data = node->data;
        temp1->next = new_node;
        new_node->next = temp2;
    }

    void drop(const T& value) override {
        ForwardListNode<T>* temp1 = head->next;
        ForwardListNode<T>* temp2 = head;
        while (temp1->next != head) {
            if(temp1->data == value){
                temp2->next = temp1->next;
            }
            temp2 = temp1;
            temp1 = temp1->next;
        }
    }

    ForwardListNode<T>* get_head() {
        return head;
    }

    inline friend std::ostream& operator << (std::ostream& os, const CircularList<T>& lista){
        ForwardListNode<T> *temp = lista.head;
        if (!lista.head) {
            std::cout << "La Lista esta vacia " << std::endl;
        } else {
            while (temp->next != lista.head) {
                std::cout << temp->data << " -> ";
                if (!temp->next) std::cout << "NULL";
                temp = temp->next;
            }
            std::cout << temp->data;
        }
        std::cout << std::endl << std::endl;
        return os;
    }

    ~CircularList(){}
};

#endif //UNTITLED19_CIRCULARLIST_H
