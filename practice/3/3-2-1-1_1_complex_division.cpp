#include <iostream>

// let's just talk a bit about what happens in this code
// using only the relevant parts of it
// I am not putting much thought into making this efficient, there are countless ways to design a class like this. This is probably not the best one, but I don't want to spend much time on this exercise.

class Complex;

class Complex{
  
  double re, im;
public:
  Complex() : re{0}, im{0} {}
  Complex(double r) : re{r}, im{0} {}
  Complex(double r, double i) : re{r}, im{i} {}

  double r() const{ return re;}
  double i() const{ return im;}

  Complex Conjugate() const
  {
    return {re, -im};
  }

  Complex& operator*=(Complex z) {re=re*z.re-im*z.im, im=im*z.re+re*z.im; return *this;}

  Complex& operator/=(Complex operand);
};
     
    
Complex operator*(Complex a, Complex b) { return a*=b; }
Complex operator/(Complex a, Complex b) { return a/=b; }

Complex& Complex::operator/=(Complex operand){
  double denominator = ( operand * operand.Conjugate() ).r();
  Complex nominator = *this * operand.Conjugate();
  re = nominator.re/denominator;
  im = nominator.im/denominator;
  return *this;
}

// prints complex to stream in a form like 2+3i, 0+0i etc.
std::ostream& operator<<(std::ostream& os, const Complex& c)
{
  os << c.r() << (c.i()>=0 ? "+" : "-") << (c.i()>=0 ? c.i() : -c.i()) << "i";
  return os;
}

int main(int argc, char** argv)
{
// TODO - validate input
  if(argc != 1 && argc!= 3)
  {
    std::wcout << "Usage: " << argv[0] << " %real %imaginary" << std::endl;
    return 0;
  }
  double re, im;
  if(argc == 3)
  {
    re = strtod(argv[1], nullptr);
    im = strtod(argv[2], nullptr);
  }
  else
  {
    std::cin >> re >> im; 
  }

  Complex a {re, im};
  // following line doesn't work because double implicit conversion is not allowed
  // it could be solved in several ways though, creating a Complex(int) constructor one of them
  //std::cout << (1/a) << std::endl;
  std::cout << (1.0/a) << std::endl;
  return 0;
}
