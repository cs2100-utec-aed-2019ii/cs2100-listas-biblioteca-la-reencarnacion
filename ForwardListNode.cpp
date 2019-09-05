#include "Node.cpp"
#include <iostream>
using namespace std;

template <typename T>
class ForwardListNode : public Node<T> {
protected:
    Node<T> * next;
public:
    ForwardListNode(){}
    ~ForwardListNode(){}
};