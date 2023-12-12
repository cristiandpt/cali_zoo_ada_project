#ifndef TABLAHASH_H
#define TABLAHASH_H

#include "../cpp-linkedList/linkedList.h"
#include <vector>

template <typename T>
class HashTable {
public:
    HashTable(int size): size(size), table(size){}
    int getSize() const { return size; }
    
private:
    int size;
    std::vector<LinkedList<T>> table;
};
#endif