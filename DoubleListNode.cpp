#include "List.cpp"

template <typename T>
class DoubleListNode : public Node<T> {
public:
    DoubleListNode<T>* next;
    DoubleListNode<T>* prev;
    DoubleListNode(){
        next = NULL;
        prev = NULL;
    }
    DoubleListNode(T data) : Node<T>(data){
        next = NULL;
        prev = NULL;
    }
    ~DoubleListNode(){}


};
