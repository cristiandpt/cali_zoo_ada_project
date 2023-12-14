#ifndef NODE_H
#define NODE_H
template <typename T>
class Node {
    public:
        Node(T value) : value(value), next(nullptr) {} // Constructor

        T& getValue() { return value; } // Versión no constante
        //const T& getValue() const { return value; } // Versión constante

        Node<T>* getNext() const { return next; } // Accesor para next
        void setNext(Node<T>* next) { this->next = next; } // Mutador para next

    private:
        T value; // Valor del nodo
        Node<T>* next; // Puntero al siguiente nodo
};
#endif