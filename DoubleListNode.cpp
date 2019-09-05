#include "Node.cpp"
#include <iostream>
using namespace std;

template <typename T>
class DoubleListNode : public Node<T>{
protected:
    Node<T> * next;
    Node<T> * prev;
public:
    DoubleListNode(){}
    ~DoubleListNode(){}
};