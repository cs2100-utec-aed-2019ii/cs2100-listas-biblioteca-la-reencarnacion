#include "List.cpp"
template <typename T>
class DoubleList : public List<T>{
protected:
    DoubleListNode<T> *head;
    DoubleListNode<T> *tail;
public:
    DoubleList(){}
    ~DoubleList(){}​
};