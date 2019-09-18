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
    node_t *tail = nullptr;
public:

    friend class ForwardIterator;
    class ForwardIterator : public Iterator<node_t> {
    public:
        typedef typename Iterator<node_t>::node_t node_t;
        typedef typename Iterator<node_t>::value_t value_t;

        ForwardIterator(node_t* _pointer = nullptr) : Iterator<node_t>(_pointer){}
        ~ForwardIterator(){}

    };

    ForwardList(): List<T>() {}

    ForwardList(ForwardList& lista): List<T>(){
        if (!lista.empty()) {
            ForwardIterator it;
            for (it = lista.begin();it != lista.end();++it) {
                push_back(*it);
            }
            push_back(*it);
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
        return **tail;
    }

    void push_front(const T& element) override {
        node_t *new_node = new ForwardListNode<T>(element);
        if (!head) {
            head = new_node;
            tail = head;
        } else {
            new_node->next = head;
            head = new_node;
        }
    }
    void push_back(const T& element) override {
        node_t *new_node = new ForwardListNode<T>(element);
        if (!head) {
            head = new_node;
            tail = head;
        } else {
            tail->next = new_node;
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
        temp2->next = nullptr;
        tail = temp2;
        return temp1;
    }
    Node<T>* pop_front() override {
        node_t* temp = head;
        head = head->next;
        return temp;
    }

    T& operator[] (const unsigned int& index) override {
        Iterator it = begin();
        for (int i = 0; i < index; i++) {
            ++it;
        }
        return *it;
    }

    bool empty() override {
        return head == nullptr;
    }

    unsigned int size() override {
        int cont = 0;
        Iterator it = begin();
        while (it != end()) {
            ++it;
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
        **new_node = **node;
        temp1->next = new_node;
        new_node->next = temp2;
    }

    void drop(const T& value) override {
        node_t* temp1 = head->next;
        node_t* temp2 = head;
        while (temp1) {
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
        return ForwardIterator(tail);
    }

    inline friend ostream& operator << (ostream& os, const ForwardList<T>& lista){
        ForwardListNode<T> *temp = lista.head;
        if (!lista.head) {
            cout << "La Lista esta vacia " << endl;
        } else {
            while (temp) {
                cout << **temp << " -> ";
                if (!temp->next) cout << "NULL";
                temp = temp->next;
            }
        }
        cout << endl << endl;
        return os;
    }

    ~ForwardList(){}
};

#endif //UNTITLED19_FORWARDLIST_H
