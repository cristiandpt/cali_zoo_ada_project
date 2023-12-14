#pragma once
#include "../estrucurasDeDatos/cpp-rojinegroTrie/red_black_tree.h"
#include "../estrucurasDeDatos/base_container/base_container.h"
#include "../estrucurasDeDatos/cpp-mapDic/hash_map.h"
#include "../estrucurasDeDatos/cpp-linkedList/linkedList.h"
#include "./zoo_data_structure_type_enum.h"
#include <stdexcept>
#include <memory>

// Factory class to instance the zoo data structures
template <typename T>
class DataStructureFactory {

    public:
        static std::shared_ptr<BaseContainer<T>> createDataStructure(DataStructureType type) {
            switch (type) {
                case DataStructureType::LinkedList:
                    return std::shared_ptr<LinkedList<T>>();
                case DataStructureType::RedBlackTree:
                    return std::shared_ptr<RedBlackTree<T>>();
                case DataStructureType::HashMap:
                    return std::shared_ptr<HashMap<T>>();
                default:
                    // Handle unknown type (optional)
                    throw std::invalid_argument("Unknown data structure type");
            }
        }
};