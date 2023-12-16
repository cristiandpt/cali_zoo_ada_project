#pragma once
#include <iostream>
#include <memory>
#include "../../evento/parte/parte.h"
#include "../../escena/escena.h"

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

        Color getColor() const {
            return color;
        }

        void setColor(Color  color)  {
            color = color;
        }

        std::shared_ptr<RBNode<V>> getLeft() const {
            return left;
        }
        std::shared_ptr<RBNode<V>> getRight() const {
            return right;
        }

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



template <>
class RBNode<Escena> {
public:
    enum class Color { RED, BLACK };
    RBNode(Escena value, Color color = Color::RED)
        : value(value), color(color), left(nullptr), right(nullptr), parent(std::weak_ptr<RBNode<Escena>>()) {}

    Escena& getValue() {
        return value;
    }

    Color getColor() const {
        return color;
    }

    void setColor(Color newColor) {
        color = newColor;
    }

    std::shared_ptr<RBNode<Escena>> getLeft() const {
        return left;
    }

    std::shared_ptr<RBNode<Escena>> getRight() const {
        return right;
    }

    std::weak_ptr<RBNode<Escena>> getParent() const {
        return parent;
    }

    void setParent(std::weak_ptr<RBNode<Escena>> parentNode) {
        parent = parentNode;
    }

    void setRight(std::shared_ptr<RBNode<Escena>> node) {
        right = node;
    }

    void setLeft(std::shared_ptr<RBNode<Escena>> node) {
        left = node;
    }

private:
    Escena value;
    Color color;
    std::shared_ptr<RBNode<Escena>> left;
    std::shared_ptr<RBNode<Escena>> right;
    std::weak_ptr<RBNode<Escena>> parent;
};

template <>
class RBNode<Parte> {
public:
    enum class Color { RED, BLACK };
    RBNode(Parte value, Color color = Color::RED)
        : value(value), color(color), left(nullptr), right(nullptr), parent(std::weak_ptr<RBNode<Parte>>()) {}

    Parte& getValue() {
        return value;
    }

    Color getColor() const {
        return color;
    }

    void setColor(Color newColor) {
        color = newColor;
    }

    std::shared_ptr<RBNode<Parte>> getLeft() const {
        return left;
    }

    std::shared_ptr<RBNode<Parte>> getRight() const {
        return right;
    }

    std::weak_ptr<RBNode<Parte>> getParent() const {
        return parent;
    }

    void setParent(std::weak_ptr<RBNode<Parte>> parentNode) {
        parent = parentNode;
    }

    void setRight(std::shared_ptr<RBNode<Parte>> node) {
        right = node;
    }

    void setLeft(std::shared_ptr<RBNode<Parte>> node) {
        left = node;
    }

private:
    Parte value;
    Color color;
    std::shared_ptr<RBNode<Parte>> left;
    std::shared_ptr<RBNode<Parte>> right;
    std::weak_ptr<RBNode<Parte>> parent;
};