#pragma once
template <typename T>
class BaseContainer{
   public:
      // pure virtual function providing interface framework.
      virtual std::size_t  max() = 0;
      virtual std::size_t  min() = 0;
      virtual std::size_t  aggregate() = 0;
      virtual T& operator[](std::size_t  index) = 0;
      virtual std::size_t  sizeC() = 0;
      virtual std::size_t  mean() = 0;
      virtual ~BaseContainer() {}

    virtual std::size_t max() = 0;
    virtual std::size_t min() = 0;
    virtual T& operator[](std::size_t index) = 0;
    virtual std::size_t sizeC() = 0;
    virtual void insert(T& value) = 0;
    /*virtual std::pair<BaseContainer<T>*,BaseContainer<T>*> divide() = 0;
    virtual BaseContainer<T>* merge(BaseContainer<T>* other) = 0;*/

    //virtual T& find(const T& value) = 0;
    //virtual bool findBool(const T& value) = 0;

protected:
    int size;
};
