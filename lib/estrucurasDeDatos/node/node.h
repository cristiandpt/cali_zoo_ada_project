#include <memory>
template <typename T>
struct Node {

    using node_ptr = std::unique_ptr<Node>;
    T data{};
    node_ptr next = nullptr;
};