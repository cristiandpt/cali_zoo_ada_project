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

   protected:
      int size = 0;
};