//
// Created by VICTOR on 28/08/2019.
//

#ifndef UNTITLED14_NODE_H
#define UNTITLED14_NODE_H

template <typename T>
class Node {
    protected:
        T value;
        Node<T> * next;
    public:
        Node(void);
        ~Node(void);
};


#endif //UNTITLED14_NODE_H
