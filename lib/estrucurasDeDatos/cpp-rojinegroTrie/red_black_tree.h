#include "../node/node.h"
#include <memory>
#include "../../escena/escena.h"

template <typename T>
class RBNode {

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

        bool operator<=(const RBNode& other) const {
            return value <= other.value;
        }

        bool operator>=(const RBNode& other) const {
            return value >= other.value;
        }

};

template <typename T>
class RedBlackTree: public BaseContainer<T> {

    public:
        RedBlackTree() : root(nullptr) {}

        void insert(const T& data) {
            auto newNode = std::make_shared<RBNode<T>>(std::move(data));
            insertNode(newNode);
        }

        std::size_t  max() override {

            std::shared_ptr<RBNode<T>> current = root;

            if (current == nullptr) {
                throw std::logic_error("Tree is empty");
            }

            while (current->right != nullptr) {
                current = current->right;
            }

            return current->value;
        }
    
        std::size_t  min() override {

            const std::shared_ptr<RBNode<T>>& firstElement = begin().value;

            if (firstElement == nullptr) {
                throw
                 std::logic_error("Tree is empty");
            }     
            return firstElement;
        }

        std::size_t  aggregate() override {
            int sum = 0;
            for (const std::shared_ptr<RBNode<T>>& node : *this) {
                std::cout << node->value << std::endl;
            }
            return sum;
        }

        std::size_t  sizeC() override {
            return size;
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

            length++;
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


    class Iterator {
        public:
            using iterator_category = std::forward_iterator_tag;
            using value_type = T;
            using difference_type = std::ptrdiff_t;
            using pointer = T*;
            using reference = T&;

            explicit Iterator(std::shared_ptr<RBNode<T>> node) : current(node) {
                // Find the leftmost node in the tree
                while (current != nullptr && current->left != nullptr) {
                    current = current->left;
                }
            }

            reference operator*() const {
                return current->value;
            }

            Iterator& operator++() {
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

            bool operator==(const Iterator& other) const {
                return current == other.current;
            }

            bool operator!=(const Iterator& other) const {
                return !(*this == other);
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


template <>
class RedBlackTree<Escena> : public BaseContainer<Escena> {
 
    public:
        std::size_t  aggregate() override {
                int sum = 0;
                for (const std::shared_ptr<RBNode<T>>& node : *this) {
                    sum += node->value.getAnimalGreatness();
                }
                return sum;
            }
};