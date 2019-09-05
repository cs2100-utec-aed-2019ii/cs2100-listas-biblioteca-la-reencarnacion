#include "List.cpp"
#include "ForwardListNode.cpp"
template <typename T>
class ForwardList : public List<T> {
protected:
    Node<T> *head;
public:
    ForwardList(){}
    ~ForwardList(){}
    T& front(){
        return head->value();
    }
    T& back(){
        Node<T> *temp=nullptr;
        temp=head;
        while(temp!=nullptr)
            temp=temp->next();
        return temp->value;
    }

    void push_back(const T& element){
        Node<T> *node = nullptr;
        Node<T> *final = new Node<T>(element);
        node = head;
        while(node != nullptr){
            node = node->next();
        }
        node->next() = final;
    }
    void push_front(const T& element){
        Node *node = new Node(element);
        node->next() = head;
        head = node;
    }
    Node<T>* pop_back(void){}
    Node<T>* pop_front(){}
    T& operator[] (const int&){}

    bool empty() { return head == nullptr; }
    unsigned int size(){
        int value=0;
        head->next();
        while(head!=nullptr){
            head=head->nex();
            value++;
        }
        return value;
    }
    void clear(){}
    ForwardList& sort(){}
    ForwardList& reverse(){}

    template<typename __T>
    inline friend std::ostream& operator << (std::ostream& , const ForwardList<__T>& ) {}

    template<typename __T>
    inline friend ForwardList<T>& operator << (ForwardList<__T>&, const T& ) {}

    template<typename __T>
    inline friend ForwardList<T>& operator >> (ForwardList<__T>&, const T& ) {}
};