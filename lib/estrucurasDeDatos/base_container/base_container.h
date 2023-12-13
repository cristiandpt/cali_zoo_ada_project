#pragma once
template <typename T>
class BaseContainer {
public:
    virtual ~BaseContainer() {}

    virtual std::size_t max() = 0;
    virtual std::size_t min() = 0;
    virtual T& operator[](std::size_t index) = 0;
    virtual std::size_t sizeC() = 0;
    virtual void insert(T& value) = 0;
    //virtual T& find(const T& value) = 0;
    //virtual bool findBool(const T& value) = 0;

protected:
    int size;
};
