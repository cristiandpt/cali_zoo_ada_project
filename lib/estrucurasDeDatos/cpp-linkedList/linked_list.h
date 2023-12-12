#include "../node/node.h"
#include <array>
#include <cstddef>
#include <iostream>
#include <memory>

template <typename T>
class LinkedList : public BaseContainer<T> {

    private: 

        using node_ptr = std::unique_ptr<Node>;
        
        node_ptr head = nullptr;
        std::size_t  size = 0;

    public:
    
        ~LinkedList() {
            while (head) {
                node_ptr temp = std::move(head->next);
                head = nullptr;
                head = std::move(temp);
            }
        }
};