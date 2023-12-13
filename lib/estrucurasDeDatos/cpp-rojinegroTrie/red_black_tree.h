#pragma once
#include <iostream>
#include <memory>
#include "../../escena/escena.h"
#include "../base_container/base_container.h"
#include <stdexcept>
#include "./rb_node.h"

template <typename T>
class RedBlackTree: public BaseContainer<T> {

    public:

        RedBlackTree() : root(nullptr) {}

        std::size_t max() {
            const std::shared_ptr<RBNode<T>> current = root;
/* 
            if (current == nullptr) {
                throw std::logic_error("Tree is empty");
            }

            while (current->right != nullptr) {
                current = current->right;
            } */

            return 0; 
        }

        std::size_t  sizeC() {
            return this->length;
        };


        std::size_t min() override {

            const std::shared_ptr<RBNode<T>>& firstElement = begin().getCurrent();
            if (firstElement == nullptr) {
                throw std::logic_error("Tree is empty");
            }     

            return firstElement->getValue().getAnimalGreatness();
        }

        std::size_t aggregate() override {

            std::size_t sum = 0;
            for (const auto& node : *this)  {
                sum += node.getAnimalGreatness();
            }
            return sum;
        }

        double mean() override {
            return 0.0;
        }

        void insert(T& value) {
            std::shared_ptr<RBNode<T>> node = std::make_shared<RBNode<T>>(value);
            insertNode(node);
        }

        void insertNode(std::shared_ptr<RBNode<T>> node) {
            // Step 1: Perform a standard BST insertion
            std::shared_ptr<RBNode<T>> parentNode = nullptr;
            std::shared_ptr<RBNode<T>> currentNode = root;

            while (currentNode != nullptr) {
                parentNode = currentNode;
                if (node->getValue() < currentNode->getValue()) {
                    currentNode = currentNode->getLeft();
                } else {
                    currentNode = currentNode->getRight();
                }
            }

            node->setParent(parentNode);

            if (parentNode == nullptr) {
                root = node;
            } else if (node->getValue() < parentNode->getValue()) {
                parentNode->getLeft() = node;
            } else {
                parentNode->getRight() = node;
            }

            // Step 2: Color the newly inserted node as RED
            node->setColor(RBNode<T>::Color::RED); 

            this->length++;

            // Rectifica el arbol para que siga conservado
            // las propiedades de ser un arbol rojinegro.
            fixInsertionViolations(node);
        }

        void rotateLeft(std::shared_ptr<RBNode<T>> node) {
            std::shared_ptr<RBNode<T>> pivot = node->getRight();

            node->getRight() = pivot->getLeft();
            if (pivot->getLeft() != nullptr) {
                pivot->getLeft()->setParent(node);
            }

            pivot->setParent(node->getParent());
            if (node->getParent().lock() == nullptr) {
                root = pivot;
            } else if (node == node->getParent().lock()->getLeft()) {
                node->getParent().lock()->setLeft(pivot);
            } else {
                node->getParent().lock()->setRight(pivot);
            }

            pivot->setLeft(node);
            node->setParent(pivot);
        }

        void rotateRight(std::shared_ptr<RBNode<T>> node) {
            std::shared_ptr<RBNode<T>> pivot = node->getLeft();

            node->getLeft() = pivot->getRight();
            if (pivot->getRight() != nullptr) {
                pivot->getRight()->setParent(node);
            }

            pivot->setParent(node->getParent());
            if (node->getParent().lock() == nullptr) {
                root = pivot;
            } else if (node == node->getParent().lock()->getRight()) {
                node->getParent().lock()->setRight(pivot);
            } else {
                node->getParent().lock()->setLeft(pivot);
            }

            pivot->setRight(node);
            node->setParent(pivot);
        }


        void fixInsertionViolations(std::shared_ptr<RBNode<T>>& node) {
            while (node != root && node->getParent().lock()->getColor() == RBNode<T>::Color::RED) {
                if (node->getParent().lock() == node->getParent().lock()->getParent().lock()->getLeft()) {
                    std::shared_ptr<RBNode<T>> uncle = node->getParent().lock()->getParent().lock()->getRight();

                    if (uncle != nullptr && uncle->getColor() == RBNode<T>::Color::RED) {
                        node->getParent().lock()->setColor(RBNode<T>::Color::BLACK);
                        uncle->setColor(RBNode<T>::Color::BLACK);
                        node->getParent().lock()->getParent().lock()->setColor(RBNode<T>::Color::RED);
                        node = node->getParent().lock()->getParent().lock();
                    } else {
                        if (node == node->getParent().lock()->getRight()) {
                            node = node->getParent().lock();
                            rotateLeft(node);
                        }

                        node->getParent().lock()->setColor(RBNode<T>::Color::BLACK);
                        node->getParent().lock()->getParent().lock()->setColor(RBNode<T>::Color::RED);
                        rotateRight(node->getParent().lock()->getParent().lock());
                    }
                } else {
                    std::shared_ptr<RBNode<T>> uncle = node->getParent().lock()->getParent().lock()->getLeft();

                    if (uncle != nullptr && uncle->getColor() == RBNode<T>::Color::RED) {
                        node->getParent().lock()->setColor(RBNode<T>::Color::BLACK);
                        uncle->setColor(RBNode<T>::Color::BLACK);
                        node->getParent().lock()->getParent().lock()->setColor(RBNode<T>::Color::RED);
                        node = node->getParent().lock()->getParent().lock();
                    } else {
                        if (node == node->getParent().lock()->getLeft()) {
                            node = node->getParent().lock();
                            rotateRight(node);
                        }

                        node->getParent().lock()->setColor(RBNode<T>::Color::BLACK);
                        node->getParent().lock()->getParent().lock()->setColor(RBNode<T>::Color::RED);
                        rotateLeft(node->getParent().lock()->getParent().lock());
                    }
                }
            }

            root->setColor(RBNode<T>::Color::BLACK);
        }

        T& operator[](std::size_t  index) override {
            index++;
            return root->getValue();
        }

        class Iterator {

            public:
                using iterator_category = std::forward_iterator_tag;
                using value_type = T;
                using difference_type = std::ptrdiff_t;
                using pointer = T*;
                using reference = T&;

                   Iterator(std::shared_ptr<RBNode<T>> node) : current(node) {
                    // Find the leftmost node in the tree
                        while (current != nullptr && current->getLeft() != nullptr) {
                            current = current->getLeft();
                        }
                    }

                    reference operator*() const {
                        return current->getValue();
                    }

                    Iterator& operator++() {
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

                    bool operator==(const Iterator& other) const {
                        return current == other.current;
                    }

                    bool operator!=(const Iterator& other) const {
                        return !(*this == other);
                    }

                    std::shared_ptr<RBNode<T>> getCurrent() const {
                        return current;
                    }

            private:
                std::shared_ptr<RBNode<T>> current;

        };

         Iterator begin() {
            return Iterator(root);
         }

        Iterator end() {
            return Iterator(nullptr);
        }

        void inorderTraversal() {
             inorderTraversal(root);
        }

    private:

        std::shared_ptr<RBNode<T>> root;
        int length = 0;
        
        void inorderTraversal(std::shared_ptr<RBNode<T>> node) {
            if (node != nullptr) {
                // Recorrise el subarbol izquierdo
                inorderTraversal(node->getLeft());
                // Cuando regresa al nodo actual, imprime el valor asociado al nodo.
                std::cout << node->getValue() << " ";
                // TRecorrer el subarbol derecho.
                inorderTraversal(node->getRight());
            }
        }
     

};

/* 
template <>
class RedBlackTree<Escena> : public BaseContainer<Escena> {
 
  public:

        std::size_t aggregate() override;

    
};  
  */
