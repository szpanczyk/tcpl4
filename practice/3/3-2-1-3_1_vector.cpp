#include <iostream>

// a simple vector class with no dynamic resizing

// this program illustrates some problems between concepts of conversion and std::initializer_list initialization
// i will need to study initialization and conversions to get a clearer picture

template<typename T>
class Vector
{
  T* buffer;
  // this variable should not change in this version of vector
  unsigned long int size;
public:
  Vector(unsigned long int x): buffer{new T[x]}, size{x}
  {
    // I don't assume that user wants vector zero initialized.
  }

  Vector(std::initializer_list<T> list) :
    buffer{new T[ list.size() ]},
    size{ list.size() }
  {
    int i = 0;
    for(const T& element : list)
    {
      buffer[i++] = element;
    }
  }
  ~Vector() { delete[] buffer; }


  T& operator[](int i)
  {
    return buffer[i];
  }
  int Size() const { return size; }
};

class Bonk
{
  int x;
  public:
    Bonk() : x(0) {};
    Bonk(int i) : x(i) {};
};

class NotBonk
{
  int x;
  public:
    NotBonk() : x(0) {};
    explicit NotBonk(int i) : x(i) {};
};

// this function shows that you can't actually conver initializer_list<int> to initializer_list<double> as a whole
void print_adjusted_doubles(std::initializer_list<double> list)
{
   for( double d : list)
   {
      std::cout << d + 0.1 << std::endl; 
   } 
}
int main()
{
  
  Vector<int> v {100};

  std::cout << v.Size() << std::endl;

  // there is more than one syntax for initialization, and recently it's become important
  // to understand pecularities and differences
  // first example (above) picks the std::initializer_list constructor instead of the unsigned long int one

  Vector<int> v2 {1, 2, 3, 4};

  Vector<double> v3 {300};
  // v3 still picks the same constructor - even though the std::initializer_list holds integral type. it manages to convert implicitly somewhere under the hood

  std::cout << v3.Size() << std::endl;
  
  Vector<Bonk> v4 {400};
  Vector<NotBonk> v5 {500};

  std::cout << v4.Size() << std::endl;
  // same goes for Vector of Bonks, because Bonk can be converted to from an integral
  std::cout << v5.Size() << std::endl;
  // but when NotBonk cannot be converted implicitly (keyword explicit), finally the other constructor is used

  print_adjusted_doubles( {1, 2, 3, 4} );

  // the above function call works, because implicit conversion from int to double are done separately
  // but the following will not work, as we have forced the list's type parameter to int
  std::initializer_list<int> list {5, 6, 7, 8};

  print_adjusted_doubles(list);

  return 0;


}
  
