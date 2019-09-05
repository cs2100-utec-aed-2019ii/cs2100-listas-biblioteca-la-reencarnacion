#include "Node.cpp"
#include "ForwardListNode.cpp"
#include "DoubleListNode.cpp"
#include <iostream>
using namespace std;

template <typename T>
class List : public ForwardListNode<T>, public DoubleListNode<T> {
protected:
    Node<T> *head;

public:
    List(List<T>* lista){
        head = lista->head;
    }

    List(T* lista){}

    List(Node<T>*){}

    List(int n){}

    List(){}​

    ~List(){}

    T& front() = 0; // Retorna una referencia al primer elemento
    T& back() = 0; // Retorna una referencia al ultimo elemento

    void push_back(const T& element) = 0; // Inserta un elemento al final
    void push_front(const T& element) = 0; // Inserta un elemento al inicio

    Node<T>* pop_back(void) = 0; // Quita el ultimo elemento de la lista y retorna una referencia
    Node<T>* pop_front(void) = 0; // Quita el primer elemento de la lista y retorna una referencia

    T& operator[] (const int&); // devuelve el valor de un nodo en una posicion determinada

    bool empty(void) = 0; // la lista esta vacia?
    unsigned int size(void) = 0; // retorna el tamaño de la lista
    void clear(void) = 0; // Elimina toda la lista

    void erase(Node<T>*) = 0; // Elimina un elemento de la lista en base a un puntero
    void insert(Node<T>*, const T&) = 0; // Inserta un elemento en la lista en base a un puntero
    void drop(const T&) = 0; // Elimina todos los elementos de la lista que tienen el valor igual al parametro


    ForwardList<T>& sort() = 0; // ordena la lista
    ForwardList<T>& reverse() = 0; // invierte la lista

    template<typename __T>
    inline friend std::ostream& operator << (std::ostream& , const ForwardList<__T>& ) = 0; // Imprime la lista con cout

    template<typename __T>
    inline friend ForwardList<T>& operator << (ForwardList<__T>&, const T& ) = 0; // push_back de un elemento

    template<typename __T>
    inline friend ForwardList<T>& operator >> (ForwardList<__T>&, const T& ) = 0; // pop_back de un elemento
};