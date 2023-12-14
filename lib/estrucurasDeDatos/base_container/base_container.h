#pragma once
template <typename T>
class BaseContainer {

   public:
      virtual std::size_t  max() = 0;
      virtual std::size_t  min() = 0;
      virtual std::size_t  aggregate() = 0;
      virtual T& operator[](std::size_t  index) = 0;
      virtual std::size_t  sizeC() = 0;
      virtual double  mean() = 0;
      virtual ~BaseContainer() = default;
      virtual void insert(T& value) = 0;
   
      class Iterator {
         public:
            using iterator_category = std::forward_iterator_tag;
            using value_type = T;
            using difference_type = std::ptrdiff_t;
            using pointer = T*;
            using reference = T&;

            virtual reference operator*() const = 0;
            virtual Iterator& operator++() = 0;
            virtual bool operator==(const Iterator& other) const = 0;
            virtual bool operator!=(const Iterator& other) const = 0;
            virtual ~Iterator() = default;
       };
   

  protected:
      int length{};

    /*virtual std::pair<BaseContainer<T>*,BaseContainer<T>*> divide() = 0;
    virtual BaseContainer<T>* merge(BaseContainer<T>* other) = 0;*/

    //virtual T& find(const T& value) = 0;
    //virtual bool findBool(const T& value) = 0;

};
