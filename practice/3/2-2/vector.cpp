#include "vector.h"

template class Vector<double>;

template <typename T>
Vector<T>::Vector(int size) : v(size)
{
}

template <typename T>
T& Vector<T>::operator[](int i)
{
  return v[i];
}

template <typename T>
int Vector<T>::size() const
{
  return v.size();
}

template <typename T>
Vector<T>::~Vector()
{
  
}
