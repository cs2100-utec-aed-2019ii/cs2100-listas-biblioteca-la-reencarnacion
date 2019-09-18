//
// Created by VICTOR on 12/09/2019.
//

#ifndef UNTITLED19_ITERATOR_H
#define UNTITLED19_ITERATOR_H

template <typename T>
class Iterator {
public:
    typedef T node_t;
    typedef typename node_t::value_t value_t;
protected:
    node_t* pointer = nullptr;
public:
    Iterator(node_t* _pointer) : pointer(_pointer){}
    ~Iterator(){}
    Iterator& operator ++ () {
        pointer = pointer->next;
        return *this;
    }
    Iterator& operator ++ (int n) {
        for (int i = 0; i < n; i++){
            pointer = pointer->next;
        }
        return *this;
    }
    //virtual Iterator& operator--() const = 0;//¿Se debe hacer?
    //virtual Iterator& operator--(int n) const = 0;//¿Se debe hacer?
    value_t& operator*() {
        return **pointer;
    }
    bool operator == (const Iterator& it) const {
        return pointer == it.pointer;
    }
    bool operator != (const Iterator& it) const {
        return pointer != it.pointer;
    }
    bool operator <= (const Iterator& it) const {
        return pointer <= it.pointer;
    }
    bool operator >= (const Iterator& it) const {
        return pointer >= it.pointer;
    }
    bool operator < (const Iterator& it) const {
        return pointer < it.pointer;
    }
    bool operator > (const Iterator& it) const {
        return pointer > it.pointer;
    }

    void operator = (const value_t& _value) const {
        pointer->value = _value;
    }
};

#endif //UNTITLED19_ITERATOR_H
