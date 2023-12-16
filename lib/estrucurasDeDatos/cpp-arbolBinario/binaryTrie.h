#ifndef BINARYTRIE_H
#define BINARYTRIE_H

#include "./nodeTrie.h"
#include <stdexcept>

template <typename T>
class BinaryTrie: public BaseContainer<T> {
public:
    // Constructor
    BinaryTrie(): root(nullptr){}

    void deleteNode(NodeTrie<T>* node) {
        if (node != nullptr) {
            deleteNode(node->getLeft());
            deleteNode(node->getRight());
            delete node;
        }
    }

    ~BinaryTrie() {
        deleteNode(root);
    }


    std::size_t  aggregate() override {
        return 0;
    }

    double mean() override {
        return 0.0;
    }

    void insertNode(NodeTrie<T>* node, NodeTrie<T>* newNode) {
        if (newNode->getValue() < node->getValue()) {
            if (node->getLeft() == nullptr) {
                node->setLeft(newNode);
            } else {
                insertNode(node->getLeft(), newNode);
            }
        } else {
            if (node->getRight() == nullptr) {
                node->setRight(newNode);
            } else {
                insertNode(node->getRight(), newNode);
            }
        }
    }
    //Agrega un elemento al final de la lista
    void insert(T& value) override{
        NodeTrie<T>* newNode = new NodeTrie<T>(value);
        if (root == nullptr) {
            root = newNode;
        } else {
            insertNode(root, newNode);
        }
    }
    class Iterator: public BaseContainer<T>::Iterator {

        public:
            
            Iterator(std::shared_ptr<RBNode<T>> node) : current(node) {
            // Find the leftmost node in the tree
                while (current != nullptr && current->getLeft() != nullptr) {
                    current = current->getLeft();
                }
            }

            typename BaseContainer<T>::Iterator::reference operator*() const {
                return current->getValue();
            }

            typename BaseContainer<T>::Iterator& operator++() {
                if (current == nullptr) {
                    return *this;
                }

                // If the current node has a right child, find the leftmost node in its right subtree
                if (current->getRight() != nullptr) {
                    current = current->getRight();
                    while (current->getLeft() != nullptr) {
                        current = current->getLeft();
                    }
                } else {
                    // Otherwise, go up the tree until we find the first parent whose value is greater than the current node
                    std::shared_ptr<RBNode<T>> parent = current->getParent().lock();
                    while (parent != nullptr && current == parent->getRight()) {
                        current = parent;
                        parent = parent->getParent().lock();
                    }
                    current = parent;
                }
                return *this;
            }

            bool operator==(const typename BaseContainer<T>::Iterator& other) const override {
                return current == static_cast<const Iterator&>(other).current;
            }

            bool operator!=(const typename BaseContainer<T>::Iterator& other) const override {
                return !(*this == other);
            }

            std::shared_ptr<RBNode<T>> getCurrent() const {
                return current;
            }

        private:
            std::shared_ptr<RBNode<T>> current;

    };

    std::size_t max() override {
        return 0;
    }

    std::size_t min() override {
        return 0;
    }

    std::size_t aggregate() override {
        return 0;
    }

    T& operator[](std::size_t index) override {
        return 0;
    }

    std::size_t sizeC() override {
        return 0;
    }

    double mean() override {
        return 0.0;
    }

    void mergeSort() override {
        return;
    }

    Iterator begin() {
            return Iterator(root);
         }

    Iterator end() {
        return Iterator(nullptr);
    }



    private:
        NodeTrie<T>* root;

};
#endif