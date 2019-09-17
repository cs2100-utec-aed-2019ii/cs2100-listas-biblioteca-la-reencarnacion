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
    node_t* pointer;
public:
    Iterator(node_t* _pointer) : pointer(_pointer){}
    ~Iterator(){}
    virtual Iterator& operator++() = 0;
    virtual Iterator& operator++(int n) = 0;
    //virtual Iterator& operator--() const = 0;
    //virtual Iterator& operator--(int n) const = 0;
    virtual value_t& operator*() {
        return **pointer;
    }
    //virtual bool operator == (const Iterator& it) const = 0;
    //virtual bool operator != (const Iterator& it) const = 0;
    //virtual bool operator <= (const Iterator& it) const = 0;
    //virtual bool operator >= (const Iterator& it) const = 0;
    //virtual bool operator < (const Iterator& it) const = 0;
    //virtual bool operator > (const Iterator& it) const = 0;

    //virtual void operator = (const V& value) const = 0;
};

#endif //UNTITLED19_ITERATOR_H
