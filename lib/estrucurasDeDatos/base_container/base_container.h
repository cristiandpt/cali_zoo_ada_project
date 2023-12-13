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
  protected:
   int length{};
};//
