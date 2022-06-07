#include <iostream>

// a simple vector class with no dynamic resizing
template<typename T>
class Vector
{
  T* buffer;
  // this variable should not change in this version of vector
  const int size;
public:
  Vector(int x): buffer(new T[x]), size(x)
  {
    // I don't assume that user wants vector zero initialized.
  }
  ~Vector() { delete[] buffer; }

  T& operator[](int i)
  {
    return buffer[i];
  }
  int Size() const { return size; }
};

int main()
{
  
  Vector<int> v {10};

  return 0;

}
  
