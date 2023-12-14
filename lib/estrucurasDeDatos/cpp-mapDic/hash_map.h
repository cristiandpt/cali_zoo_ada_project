#pragma once
#include "../cpp-linkedList/node.h"
#include <memory>

template <typename T>
class HashMap : public BaseContainer<T> {

    private:    

        using node_ptr = std::shared_ptr<T>;
        
        std::size_t size = 0;
        std::vector<std::vector<node_ptr>> buckets;

    public:
    
        ~HashMap() {

        }
};