template <typename T>
class BaseContainer{
   public:
      // pure virtual function providing interface framework.
      std::size_t  max() = 0;
      std::size_t  min() = 0;
      virtual ~BaseContainer() {}
      virtual T& operator[](std::size_t  index) = 0;
      virtual std::size_t  size() = 0;
   
   protected:
      int size;
};