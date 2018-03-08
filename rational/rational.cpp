#include <iostream>
#include "rational.hpp"

void Rational::setNumber()
{
   int num, denom;
   std::cout << "Enter numerator\n";
   std::cin >> num;

   bool flag;
   std::cout << "Enter denominator\n";
   while(std::cin >> denom)
   {
      if (std::cin.fail())
         std::cout << "Invalid Input\n";
      else if (denom == 0)
         std::cout << "Denominator cannot be zero\n";
      else
         break;
   }
   
   p = num;
   q = denom;
   return;
}

void Rational::printNumber()
{
   std::cout << p << " / " << q << std::endl;
   return;
}

void Rational::operator=(Rational b)
{
  p = b.getNum();
  q = b.getDenom();
}

bool operator==(Rational a, Rational b)
{
   return (a.p * b.q) == (a.q * b.p);
}

bool operator!=(Rational a, Rational b)
{
  return !(a == b);
}

bool operator>(Rational a, Rational b)
{
 
  return (static_cast<double>(a.p)/a.q) > (static_cast<double>(b.p) / b.q);
}


bool operator<(Rational a, Rational b)
{
  return (static_cast<double>(a.p)/a.q) < (static_cast<double>(b.p) / b.q);
}

/*
bool operator<=(Rational a, Rational b)
{
   return (a < b) || (a == b);
}

bool operator>=(Rational a, Rational b)
{
   return (a > b) || (a == b);
}
*/

Rational operator+(Rational a, Rational b)
{
   int num, denom;
   
   std::cout << a.getNum() << " * " << b.getDenom() << " = "
 	     << a.getNum() * b.getDenom() << '\n'
             << b.getNum() << " * " << a.getDenom() << " = "
             << b.getNum() * a.getDenom() << '\n'
             << a.getDenom() << " * " << b.getDenom() << " = "
             << a.getDenom() * b.getDenom() << '\n';

   num = a.getNum() * b.getDenom() + a.getDenom() * b.getNum();
   denom = a.getDenom() * b.getDenom();

   Rational n(num, denom);
   return n;
}
