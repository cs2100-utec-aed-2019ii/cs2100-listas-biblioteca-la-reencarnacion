template <typename T>
class DoubleListNode : public Node<T>{
    protected:
        Node<T> * next;
        Node<T> * prev;
​
    public:
        Node(void){
        }
​
        ~Node(void){
        }
};