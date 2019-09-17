//
// Created by VICTOR on 11/09/2019.
//

#ifndef UNTITLED19_FORWARDLIST_H
#define UNTITLED19_FORWARDLIST_H

#include "ForwardListNode.h"
#include "List.h"
#include "Iterator.h"
using namespace std;

template <typename T>
class ForwardList : public List<T> {
public:
    typedef ForwardListNode<T> node_t;

protected:
    node_t *head = nullptr;
public:

    friend class ForwardIterator;
    class ForwardIterator : public Iterator<node_t> {
    public:
        typedef typename Iterator<node_t>::node_t node_t;
        typedef typename Iterator<node_t>::value_t value_t;

        ForwardIterator(node_t* _pointer = nullptr) : Iterator<node_t>(_pointer){}
        ~ForwardIterator(){}

        ForwardIterator& operator++() {
            Iterator<node_t>::pointer = Iterator<node_t>::pointer->next;
            return *this;
        }
        ForwardIterator& operator++(int n) {
            for (int i = 0; i < n; i++){
                Iterator<node_t>::pointer = Iterator<node_t>::pointer->next;
            }
            return *this;
        }
    };

    ForwardList(): List<T>() {}

    ForwardList(ForwardList& lista): List<T>(){
        if (!lista.empty()) {
            node_t* temp = lista.get_head();
            while (temp != nullptr) {
                push_back(**temp);
                temp = temp->next;
            }
        }
    }

    ForwardList(T* lista, int n): List<T>(){
        for (int i = 0; i < n; ++i) {
            push_back(lista[i]);
        }
    }

    ForwardList(Node<T>* node): List<T>(){
        head = new ForwardListNode<T>();
        head->value = **node;
    }

    ForwardList(int num): List<T>(){
        for (int i = 0; i < num; i++){
            push_back(NULL);
        }
    }

    T& front() override {
        return **head;
    }

    T& back()override {
        node_t* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return **head;
    }

    void push_front(const T& element) override {
        node_t *new_node = new ForwardListNode<T>(element);
        if (!head) {
            head = new_node;
        } else {
            new_node->next = head;
            head = new_node;
        }
    }
    void push_back(const T& _value) override {
        node_t* new_node = new ForwardListNode<T> (_value);
        node_t* temp = head;

        if (!head) {
            head = new_node;
        } else {
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }

    Node<T>* pop_back() override {
        node_t* temp1 = head;
        node_t* temp2;
        while (temp1->next != nullptr) {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next = nullptr;
        return temp1;
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
        return head == NULL;
    }

    unsigned int size() override {
        int cont = 0;
        node_t* temp = head;
        while (temp != NULL) {
            temp = temp->next;
            cont++;
        }
        return cont;
    }

    void clear() override {
        head = NULL;
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
        **new_node = **node;
        temp1->next = new_node;
        new_node->next = temp2;
    }

    void drop(const T& value) override {
        node_t* temp1 = head->next;
        node_t* temp2 = head;
        while (temp1 != NULL) {
            if(**temp1 == value){
                temp2->next = temp1->next;
            }
            temp2 = temp1;
            temp1 = temp1->next;
        }
    }

    node_t* get_head() {
        return head;
    }

    ForwardIterator begin() {
        return ForwardIterator(head);
    }

    ForwardIterator end() {
        ForwardListNode<T>* temp1 = head;
        while (temp1->next != NULL) {
            temp1 = temp1->next;
        }
        return ForwardIterator(temp1);
    }

    inline friend std::ostream& operator << (std::ostream& os, const ForwardList<T>& lista){
        ForwardListNode<T> *temp = lista.head;
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

    ~ForwardList(){}
};

#endif //UNTITLED19_FORWARDLIST_H
