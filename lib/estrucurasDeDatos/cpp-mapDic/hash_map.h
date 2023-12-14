#include "../node/node.h"

template <typename T>
class HashMap : public BaseContainer<T> {

    private:    

        using node_ptr = std::unique_ptr<Node>;
        
        std::size_t size = 0;
        std::vector<std::vector<node_ptr>> buckets;

    public:
    
        ~HashMap() {

        }
};