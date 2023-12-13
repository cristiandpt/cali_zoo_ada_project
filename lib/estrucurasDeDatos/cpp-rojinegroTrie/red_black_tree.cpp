/* #include <memory>
#include "./red_black_tree.h"
#include "./rb_node.h"
#include "../base_container/base_container.h"

template <typename T>
RedBlackTree<T>::RedBlackTree() : root(nullptr) {}


template <typename T>
std::size_t RedBlackTree<T>::max() {
    const std::shared_ptr<RBNode<T>> current = root;

    if (current == nullptr) {
        throw std::logic_error("Tree is empty");
    }

    while (current->right != nullptr) {
        current = current->right;
    }

    return current->value; 
}

 template <typename T>
std::size_t RedBlackTree<T>::min() {
    const std::shared_ptr<RBNode<T>>& firstElement = begin().current;

    if (firstElement == nullptr) {
        throw std::logic_error("Tree is empty");
    }     

    return firstElement->value;
}

template <typename T>
std::size_t RedBlackTree<T>::aggregate() {
    std::size_t sum = 0;
    for (const std::shared_ptr<RBNode<T>>& node : *this) {
        sum += node->value;
    }
    return sum;
}

 template <typename T>
T& RedBlackTree<T>::operator[](std::size_t  index) {
    return root->value;
} 

template <typename T>
double RedBlackTree<T>::mean() {
    return 0.0;
}

template <typename T>
void RedBlackTree<T>::insertNode(std::shared_ptr<RBNode<T>>&& node) {
    // Step 1: Perform a standard BST insertion
    std::shared_ptr<RBNode<T>> parentNode = nullptr;
    std::shared_ptr<RBNode<T>> currentNode = root;

    while (currentNode != nullptr) {
        parentNode = currentNode;
        if (node->value < currentNode->value) {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
    }

    node->parent = parentNode;

    if (parentNode == nullptr) {
        root = node;
    } else if (node->value < parentNode->value) {
        parentNode->left = node;
    } else {
        parentNode->right = node;
    }

    // Step 2: Color the newly inserted node as RED
    node->color = RBNode<T>::Color::RED;

    length++;

    // Step 3: Fix any violations of the Red-Black Tree properties
    fixInsertionViolations(node);
}

template <typename T>
void RedBlackTree<T>::fixInsertionViolations(std::shared_ptr<RBNode<T>>& node) {
    while (node != root && node->parent.lock()->color == RBNode<T>::Color::RED) {
        if (node->parent.lock() == node->parent.lock()->parent.lock()->left) {
            std::shared_ptr<RBNode<T>> uncle = node->parent.lock()->parent.lock()->right;

            if (uncle != nullptr && uncle->color == RBNode<T>::Color::RED) {
                node->parent.lock()->color = RBNode<T>::Color::BLACK;
                uncle->color = RBNode<T>::Color::BLACK;
                node->parent.lock()->parent.lock()->color = RBNode<T>::Color::RED;
                node = node->parent.lock()->parent.lock();
            } else {
                if (node == node->parent.lock()->right) {
                    node = node->parent.lock();
                    rotateLeft(node);
                }

                node->parent.lock()->color = RBNode<T>::Color::BLACK;
                node->parent.lock()->parent.lock()->color = RBNode<T>::Color::RED;
                rotateRight(node->parent.lock()->parent.lock());
            }
        } else {
            std::shared_ptr<RBNode<T>> uncle = node->parent.lock()->parent.lock()->left;

            if (uncle != nullptr && uncle->color == RBNode<T>::Color::RED) {
                node->parent.lock()->color = RBNode<T>::Color::BLACK;
                uncle->color = RBNode<T>::Color::BLACK;
                node->parent.lock()->parent.lock()->color = RBNode<T>::Color::RED;
                node = node->parent.lock()->parent.lock();
            } else {
                if (node == node->parent.lock()->left) {
                    node = node->parent.lock();
                    rotateRight(node);
                }

                node->parent.lock()->color = RBNode<T>::Color::BLACK;
                node->parent.lock()->parent.lock()->color = RBNode<T>::Color::RED;
                rotateLeft(node->parent.lock()->parent.lock());
            }
        }
    }

    root->color = RBNode<T>::Color::BLACK;
}

template <typename T>
void RedBlackTree<T>::rotateLeft(std::shared_ptr<RBNode<T>>& node) {
    std::shared_ptr<RBNode<T>> pivot = node->right;

    node->right = pivot->left;
    if (pivot->left != nullptr) {
        pivot->left->parent = node;
    }

    pivot->parent = node->parent;
    if (node->parent.lock() == nullptr) {
        root = pivot;
    } else if (node == node->parent.lock()->left) {
        node->parent.lock()->left = pivot;
    } else {
        node->parent.lock()->right = pivot;
    }

    pivot->left = node;
    node->parent = pivot;
}

template <typename T>
void RedBlackTree<T>::insert(T& value) {
    std::shared_ptr<RBNode<T>> node = std::make_shared<RBNode<T>>(value);
    insertNode(std::move(node));
}

template <typename T>
void RedBlackTree<T>::rotateRight(std::shared_ptr<RBNode<T>>& node) {
    std::shared_ptr<RBNode<T>> pivot = node->left;

    node->left = pivot->right;
    if (pivot->right != nullptr) {
        pivot->right->parent = node;
    }

    pivot->parent = node->parent;
    if (node->parent.lock() == nullptr) {
        root = pivot;
    } else if (node == node->parent.lock()->right) {
        node->parent.lock()->right = pivot;
    } else {
        node->parent.lock()->left = pivot;
    }

    pivot->right = node;
    node->parent = pivot;
}

template <typename T>
void RedBlackTree<T>::inorderTraversal() {
    inorderTraversal(root);
}

template <typename T>
RedBlackTree<T>::Iterator::Iterator(std::shared_ptr<RBNode<T>> node) : current(node) {
    // Find the leftmost node in the tree
    while (current != nullptr && current->left != nullptr) {
        current = current->left;
    }
}

template <typename T>
typename RedBlackTree<T>::Iterator::reference RedBlackTree<T>::Iterator::operator*() const {
    return current->value;
}

template <typename T>
typename RedBlackTree<T>::Iterator& RedBlackTree<T>::Iterator::operator++() {
    if (current == nullptr) {
        return *this;
    }

    // If the current node has a right child, find the leftmost node in its right subtree
    if (current->right != nullptr) {
        current = current->right;
        while (current->left != nullptr) {
            current = current->left;
        }
    } else {
        // Otherwise, go up the tree until we find the first parent whose value is greater than the current node
        std::shared_ptr<RBNode<T>> parent = current->parent.lock();
        while (parent != nullptr && current == parent->right) {
            current = parent;
            parent = parent->parent.lock();
        }
        current = parent;
    }

    return *this;
}

template <typename T>
bool RedBlackTree<T>::Iterator::operator==(const Iterator& other) const {
    return current == other.current;
}

template <typename T>
bool RedBlackTree<T>::Iterator::operator!=(const Iterator& other) const {
    return !(*this == other);
}

template <typename T>
typename RedBlackTree<T>::Iterator RedBlackTree<T>::begin() {
    return Iterator(root);
}

template <typename T>
typename RedBlackTree<T>::Iterator RedBlackTree<T>::end() {
    return Iterator(nullptr);
}

template <>
std::size_t RedBlackTree<Escena>::aggregate() {
    return root->value.getAggregateValue();
} */ 