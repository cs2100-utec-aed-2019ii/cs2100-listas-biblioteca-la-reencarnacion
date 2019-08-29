
#ifndef UNTITLED14_FORDWARDLIST_H
#define UNTITLED14_FORDWARDLIST_H

#include "Node.cpp"

template <typename T>
class ForwardList : protected Node<T> {
    protected:
        Node<T> *head;
    public:
        ForwardList(void);
        ~ForwardList(void);
        T& front(void);
        T& back(void);
        
        void push_back(const T& element);
        void push_front(const T& element);
        Node<T>* pop_back(void);
        Node<T>* pop_front(void);
        T& operator[] (const int&);
        
        bool empty(){
            if(head == nullptr){
                return true;
            }
            else{
                return false;
            }
        };
        unsigned int size(void);
        void clear(void);
        ForwardList& sort(void);
        ForwardList& reverse(void);
        std::ostream& operator << (const ForwardList&, std::ostream&);
};


#endif //UNTITLED14_FORDWARDLIST_H
