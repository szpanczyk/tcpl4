#include <cmath>
#include <iostream>
#include "container.h"
#include "vector.h"

template <typename T>
void print_container(Container<T>& c)
{
  int size = c.size();
  for(int i=0; i<size; ++i)
  {
    std::cout << c[i] << std::endl;
  }
}

int main()
{
  const int n = 10;
  Vector<double> v(n);
  for(int i=0; i<n; ++i){
    v[i] = sqrt(i);
  }

  print_container(v);

  return 0;

}

