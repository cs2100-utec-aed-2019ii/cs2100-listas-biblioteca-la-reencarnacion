#include "List.cpp"

template <typename T>
class CircularList : public List<T>{
protected:
    ForwardListNode<T> *head;
public:
    CircularList(){}
    ~CircularList(){}
};