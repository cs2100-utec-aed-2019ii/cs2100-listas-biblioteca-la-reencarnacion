#include "List.cpp"
#include "DoubleListNode.cpp"
template <typename T>
class DoubleList : public List<T>{
protected:
    DoubleListNode<T> *head;
    DoubleListNode<T> *tail;
public:
    DoubleList(){}
    ~DoubleList(){}​
    T& front(){
        return head->value();
    }
    T& back(){
        return tail->value();
    }

    void push_back(const T& element){
        Node *node = new Node(element);
        node->next() = tail;
        head = node;
    }
    void push_front(const T& element){
        Node *node = new Node(element);
        node->next() = head;
        head = node;
    }
    Node<T>* pop_back(){}
    Node<T>* pop_front(){
        node_pointer item;
        T data;

        if(this->tail && this->head){
            data = this->head->get_data();
            item = this->head;
            this->head = this->head->get_next();
        }

        return data;
    }
    T& operator[] (const int&){}

    bool empty(){ return head == nullptr; }
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
    DoubleList& sort(){}
    DoubleList& reverse(){}
    
    template<typename __T>
    inline friend std::ostream& operator << (std::ostream& , const ForwardList<__T>& ) {}

    template<typename __T>
    inline friend ForwardList<T>& operator << (ForwardList<__T>&, const T& ) {}

    template<typename __T>
    inline friend ForwardList<T>& operator >> (ForwardList<__T>&, const T& ) {}