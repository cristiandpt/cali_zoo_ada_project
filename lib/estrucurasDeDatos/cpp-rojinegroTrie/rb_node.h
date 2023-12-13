#pragma once

#include <iostream>
#include <memory>

template <typename V>
class RBNode {
 
    
    public:
        enum class Color { RED, BLACK };
        RBNode(V& value, Color color = Color::RED)
            : value(value), 
              color(color), 
              left(nullptr), 
              right(nullptr), 
              parent(std::weak_ptr<RBNode<V>>()) {}

        bool operator<=(const RBNode<V>& other) const {
            return value <= other.value;
        }

        bool operator>=(const RBNode<V>& other) const {
            return value >= other.value;
        }

        bool operator=(const RBNode<V>& other) const {
            return value == other.value;
        }

         V& getValue() {
            return value;
    }

    // Getter for color
        Color getColor() const {
            return color;
        }

        void setColor(Color  color)  {
            color = color;
        }

        // Getter for left child
        std::shared_ptr<RBNode<V>> getLeft() const {
            return left;
        }

        // Getter for right child
        std::shared_ptr<RBNode<V>> getRight() const {
            return right;
        }

        // Getter for parent
        std::weak_ptr<RBNode<V>> getParent() {
            return parent;
        }

        void setParent(std::weak_ptr<RBNode<V>> parentNode) {
            parent = parentNode;
        }

        void setRight(std::shared_ptr<RBNode<V>> node) {
            parent = std::shared_ptr<RBNode<V>>(node);
        }

        void setLeft(std::shared_ptr<RBNode<V>> node) {
            parent = std::shared_ptr<RBNode<V>>(node);
        }



    private:
        V value;
        Color color;
        std::shared_ptr<RBNode<V>> left;
        std::shared_ptr<RBNode<V>> right;
        std::weak_ptr<RBNode<V>> parent;
};