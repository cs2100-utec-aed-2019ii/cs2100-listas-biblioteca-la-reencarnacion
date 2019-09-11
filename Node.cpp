template <typename T>
class Node {
public:
    T data;

    Node() {
        data = NULL;
    }
    Node(T data) : data(data){}
    ~Node(){}
};
