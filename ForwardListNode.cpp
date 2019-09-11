#include "List.cpp"

template <typename T>
class ForwardListNode : public Node<T> {
public:
    ForwardListNode<T>* next;
    ForwardListNode(){
        next = NULL;
    }
    ForwardListNode(T data) : Node<T>(data){
        next = NULL;
    }
    ~ForwardListNode(){}


};
