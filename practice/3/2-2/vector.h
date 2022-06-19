#ifndef vector_h
#define vector_h

#include <vector>
#include "container.h"

template <typename T>
class Vector : public Container<T>
{
  std::vector<T> v;
  public:
    Vector(int size);
    T& operator[](int i);
    int size() const;
    ~Vector();
};

#endif

