#include "List.cpp"


template <typename T>
class DoubleCircularListNode : public Node<T> {
protected:
    DoubleCircularListNode<T> * next;
    DoubleCircularListNode<T> * prev;
public:
    DoubleCircularListNode(){}
    ~DoubleCircularListNode(){}
};

template <typename T>
class DoubleCircularList : public List<T>{
protected:
    DoubleCircularListNode<T> *head;
    DoubleCircularListNode<T> *last;    
public:
    DoubleCircularList<T>(){}
    ~DoubleCircularList(){}
    T& front(){
        return head->value();
    }
    T& back(){
        Node<T> *temp=nullptr;
        temp=head;
        if(temp!= nullptr){
            do{
                temp=temp->next()
            }while (temp!=head);            
        }
        return temp->value;
    }
    void push_back(const T& element){
        DoubleCircularListNode<T> *final = new DoubleCircularListNode<T>(element);
        if(head!=nullptr){
            last->next=value_insert;
            value_insert->next=head;
            value_insert->prev=last;
            last=value_insert;
            head->prev=last;
        }else
        {
            head=insert;
            head->next=head;
            last=head;
            head->prev=last;
        }

    }
    void push_front(const T& element){
        DoubleCircularListNode<T> *value_insert = new DoubleCircularListNode<T>(element);
        if(head!=nullptr){
            last->next=value_insert;
            value_insert->next=head;
            value_insert->prev=last;
            last=value_insert;
            head->prev=last;
        }else
        {
            head=insert;
            head->next=head;
            last=head;
            head->prev=last;
        }
    }
    Node<T>* pop_back(){
    }
    Node<T>* pop_front(){}
    T& operator[] (const int&){}

    bool empty() { return head == nullptr; }
    unsigned int size(){
        int value=0;
        head->next();
        while(head!=nullptr){
            head=head->next;
            value++;
        }
        return value;
    }
    void clear(){
        head=nullptr;
    }
    List<T>& sort(){}
    List<T>& reverse(){}

    template<typename __T>
    inline friend std::ostream& operator << (std::ostream& , const List<__T>& ) {}

    template<typename __T>
    inline friend List<T>& operator << (List<__T>&, const T& ) {}

    template<typename __T>
    inline friend List<T>& operator >> (List<__T>&, const T& ) {}
};
