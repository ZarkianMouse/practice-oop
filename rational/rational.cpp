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
