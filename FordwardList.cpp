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
    Node<T>* pop_back(void);
    Node<T>* pop_front(void);
    T& operator[] (const int&);

    bool empty();
    unsigned int size(void){
        int value=0;
        head->next();
        while(head!=nullptr){
            head=head->nex();
            value++;
        }
        return value;
    }
    void clear(void);
    ForwardList& sort(void);
    ForwardList& reverse(void);
    
    template<typename __T>
    inline friend std::ostream& operator << (std::ostream& , const ForwardList<__T>& ) = 0; // Imprime la lista con cout

    template<typename __T>
    inline friend ForwardList<T>& operator << (ForwardList<__T>&, const T& ) = 0; // push_back de un elemento

    template<typename __T>
    inline friend ForwardList<T>& operator >> (ForwardList<__T>&, const T& ) = 0; = 0; // pop_back de un elemento
};