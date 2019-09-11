
#include <iostream>
#include "ForwardListNode.cpp"
using namespace std;

template <typename T>
class ForwardList : public List<T> {
protected:
    ForwardListNode<T> *head;
public:
    ForwardList(): List<T>() {
        head = NULL;
    }

    ForwardList(ForwardList& lista): List<T>(){
        if (!lista.empty()) {
            ForwardListNode<T>* temp = lista.get_head();
            while (temp != NULL) {
                push_back(temp->data);
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
        head->data = node->data;
    }

    ForwardList(int num): List<T>(){
        for (int i = 0; i < num; i++){
            push_back(NULL);
        }
    }

    T& front() override {
        return head->data;
    }

    T& back()override {
        ForwardListNode<T>* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        return temp->data;
    }

    void push_front(const T& data) override {
        ForwardListNode<T> *new_node = new ForwardListNode<T>(data);
        if (!head) {
            head = new_node;
        } else {
            new_node->next = head;
            head = new_node;
        }
    }
    void push_back(const T& data) override {
        ForwardListNode<T>* new_node = new ForwardListNode<T> (data);
        ForwardListNode<T>* temp = head;

        if (!head) {
            head = new_node;
        } else {
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }

    Node<T>* pop_back() override {
        ForwardListNode<T>* temp1 = head;
        ForwardListNode<T>* temp2;
        while (temp1->next != NULL) {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next = NULL;
        return temp1;
    }
    Node<T>* pop_front() override {
        ForwardListNode<T>* temp = head;
        head = head->next;
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
        while (temp1 != NULL) {
            if(temp1->data == value){
                temp2->next = temp1->next;
            }
            temp2 = temp1;
            temp1 = temp1->next;
        }
    }

    void print() override {
        ForwardListNode<T> *temp = head;
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

    ForwardListNode<T>* get_head() {
        return head;
    }

    ~ForwardList(){}
};
