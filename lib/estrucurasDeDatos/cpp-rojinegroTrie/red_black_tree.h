#include "../node/node.h"
#include <memory>


template <typename T>
class RBNode : public BaseContainer<T> {

    private:
        enum class Color { RED, BLACK };
        T value;
        Color color;
        std::shared_ptr<RBNode<T>> left;
        std::shared_ptr<RBNode<T>> right;
        std::weak_ptr<RBNode<T>> parent;
    
    public:
        
        RBNode(const T& value, Color color = Color::RED)
            : value(value), 
              color(color), 
              left(nullptr), 
              right(nullptr), 
              parent(nullptr) {}

};

template <typename T>
class RedBlackTree {

    public:
        RedBlackTree() : root(nullptr) {}

        void insert(const T& data) {
            auto newNode = std::make_shared<RBNode<T>>(std::move(data));
            insertNode(newNode);
        }

     void insertNode(std::shared_ptr<RBNode<T>>&& node) {
        // Step 1: Perform a standard BST insertion
        std::shared_ptr<RBNode<T>> parentNode = nullptr;
        std::shared_ptr<RBNode<T>> currentNode = root;

        while (currentNode != nullptr) {
            parentNode = currentNode;
            if (node->value < current->value) {
                currentNode = current->left;
            } else {
                currentNode = current->right;
            }
        }

        node->parent = parentNode;

        if (parentNode == nullptr) {
            root = node;
        } else if (node->value < parent->value) {
            parent->left = node;
        } else {
            parent->right = node;
        }

        // Step 2: Color the newly inserted node as RED
        node->color = RBNode<T>::Color::RED;

        // Step 3: Fix any violations of the Red-Black Tree properties
        fixInsertionViolations(node);
    }

    void fixInsertionViolations(std::shared_ptr<RBNode<T>>& node) {
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

    void rotateLeft(std::shared_ptr<RBNode<T>>& node) {
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

    void rotateRight(std::shared_ptr<RBNode<T>>& node) {
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

    void inorderTraversal() {
        inorderTraversal(root);
    }

private:
    std::shared_ptr<RBNode<T>> root;
    void inorderTraversal(std::shared_ptr<RBNode<T>> node) {
        if (node == nullptr) {
            return;
        }

        inorderTraversal(node->left);
        std::cout << "Value: " << node->value << ", Color: ";
        if (node->color == RBNode<T>::Color::RED) {
            std::cout << "RED";
        } else {
            std::cout << "BLACK";
        }
        std::cout << std::endl;
        inorderTraversal(node->right);
    }

    
};