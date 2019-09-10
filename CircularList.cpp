#include "List.cpp"
#include "ForwardListNode.cpp"

template <typename T>
class CircularList : public List<T>{
protected:
    ForwardListNode<T> *head;
public:
    CircularList(){
        back()->next() = head;
    }
    ~CircularList(){}
};