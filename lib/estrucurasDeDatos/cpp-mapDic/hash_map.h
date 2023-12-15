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

    std::size_t max() override {
        // Implementation for finding the maximum value
        // You need to implement this based on your HashMap structure
        // Example: Traverse through buckets and find the maximum value
        return 0; // Placeholder, replace with actual implementation
    }

    std::size_t min() override {
        // Implementation for finding the minimum value
        // You need to implement this based on your HashMap structure
        // Example: Traverse through buckets and find the minimum value
        return 0; // Placeholder, replace with actual implementation
    }

    std::size_t aggregate() override {
        // Implementation for aggregation
        // You need to implement this based on your HashMap structure
        // Example: Traverse through buckets and calculate the aggregate
        return 0; // Placeholder, replace with actual implementation
    }

    T& operator[](std::size_t index) override {
        // Implementation for accessing an element by index
        // You need to implement this based on your HashMap structure
        // Example: Traverse through buckets and access the element at the specified index
        // Note: This assumes a linear traversal; modify as per your HashMap structure
        return *buckets[index / buckets.size()][index % buckets.size()];
    }

    std::size_t sizeC() override {
        return size;
    }

    double mean() override {
        // Implementation for calculating the mean
        // You need to implement this based on your HashMap structure
        // Example: Traverse through buckets and calculate the mean
        return 0.0; // Placeholder, replace with actual implementation
    }

    void insert(T& value) override {
        // Implementation for inserting a value into the HashMap
        // You need to implement this based on your HashMap structure
        // Example: Insert the value into the appropriate bucket
        // Note: Modify as per your HashMap structure
        std::size_t bucketIndex = 2;/* Calculate bucket index based on the value */;
        buckets[bucketIndex].push_back(std::make_shared<T>(value));
        size++;
    }

    BaseContainer<T>* mergeSort() override {
        // Implementation for merge sort
        // You need to implement this based on your HashMap structure
        // Example: Sort the values in each bucket and merge them
        // Note: Modify as per your HashMap structure
        return nullptr; // Placeholder, replace with actual implementation
    }

    class HashMapIterator : public BaseContainer<T>::Iterator {
    private:
        // Iterator-specific data and methods

    public:
        typename BaseContainer<T>::Iterator::reference operator*() const override {
            // Implementation for dereferencing the iterator
            return this;/* Placeholder, replace with actual implementation */;
        }

        typename BaseContainer<T>::Iterator& operator++() override {
            // Implementation for advancing the iterator
            return *this;
        }

        bool operator==(const typename BaseContainer<T>::Iterator& other) const override {
            // Implementation for comparing iterators for equality
            return false; // Placeholder, replace with actual implementation
        }

        bool operator!=(const typename BaseContainer<T>::Iterator& other) const override {
            // Implementation for comparing iterators for inequality
            return false; // Placeholder, replace with actual implementation
        }
    };
};