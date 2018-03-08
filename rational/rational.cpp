#include <iostream>
#include "rational.hpp"

// assignment
void Rational::operator=(Rational b)
{
  p = b.getNum();
  q = b.getDenom();
}


// basic comparison operations
bool operator==(Rational a, Rational b)
{
   return (a.p * b.q) == (a.q * b.p);
}

bool operator>(Rational a, Rational b)
{
 
  return (static_cast<double>(a.p)/a.q) > (static_cast<double>(b.p) / b.q);
}

bool operator<(Rational a, Rational b)
{
  return (static_cast<double>(a.p)/a.q) < (static_cast<double>(b.p) / b.q);
}


// input/output operations
std::istream& operator>>(std::istream& in, Rational &n)
{
   int num, denom;
   std::cout << "num: ";
   std::cin >> num;

   std::cout << "denom: ";
   while(std::cin >> denom)
   {
      if (std::cin.fail())
         std::cout << "Invalid Input\n";
      else if (denom == 0)
         std::cout << "Denominator cannot be zero\n";
      else
         break;
   }
   
   n.p = num;
   n.q = denom;
   return in;
}

std::ostream& operator<<(std::ostream& out, const Rational &n)
{
  std::cout << n.p << " / " << n.q;
  return out;
}


// other comparison operations
bool operator!=(Rational a, Rational b)
{
  return !(a == b);
}

bool operator>=(Rational a, Rational b)
{
   return (a > b) || (a == b);
}

bool operator<=(Rational a, Rational b)
{
   return (a < b) || (a == b);
}


// arithmetic operations
Rational operator+(Rational a, Rational b)
{
   int num, denom;

   num = a.getNum() * b.getDenom() + a.getDenom() * b.getNum();
   denom = a.getDenom() * b.getDenom();

   Rational n(num, denom);
   return n;
}

Rational operator-(Rational a, Rational b)
{
   int num, denom;

   num = a.getNum() * b.getDenom() - a.getDenom() * b.getNum();
   denom = a.getDenom() * b.getDenom();

   Rational n(num, denom);
   return n;
}

Rational operator*(Rational a, Rational b)
{
   int num, denom;

   num = a.getNum() * b.getNum();
   denom = a.getDenom() * b.getDenom();

   Rational n(num, denom);
   return n;
}

Rational operator/(Rational a, Rational b)
{
   int num, denom;

   num = a.getNum() * b.getDenom();
   denom = a.getDenom() * b.getNum();

   Rational n(num, denom);
   return n;

}
