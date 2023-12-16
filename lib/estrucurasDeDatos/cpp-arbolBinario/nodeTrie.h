#ifndef NODETRIE_H
#define NODETRIE_H

template <typename T>
class NodeTrie {
    public:
        NodeTrie(T value) : value(value), left(nullptr), right(nullptr) {} // Constructor

        T& getValue() { return value; } // Versión no constante
        NodeTrie<T>* getLeft() const { return left; } // Accesor para left
        NodeTrie<T>* getRight() const { return right; } // Accesor para right

        void setLeft(NodeTrie<T>* left) { this->left = left; } // Mutador para left
        void setRight(NodeTrie<T>* right) { this->right = right; } // Mutador para right

    private:
        T value; // Valor del nodo
        NodeTrie<T>* left; //puntero al nodo izquierdo
        NodeTrie<T>* right; // Puntero al nodo derecho
};

#endif
