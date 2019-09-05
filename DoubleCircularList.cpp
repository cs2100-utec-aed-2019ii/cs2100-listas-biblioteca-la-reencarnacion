#include "List.cpp"

template <typename T>
class DoubleCircularList : public List<T>{
protected:
    DoubleListNode<T> *head;
public:
    DoubleCircularList<T>(){}
    ~DoubleCircularList(){}
};