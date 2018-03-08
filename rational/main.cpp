/* Rational Numbers by Naomi Burhoe */

#include <iostream>
#include "rational.hpp"

int main()
{
   std::cout << "Hello there\n";
   Rational num;
   num.setNumber();
   num.printNumber();

   /*
   Rational num2;
   num2.setNumber();
   num2.printNumber();
   std::cout << "num == num2\n";
   if (num == num2)
      std::cout << "true\n";
   
   Rational num3;
   num3.setNumber();
   num3.printNumber();
   std::cout << "num != num3\n";
   if (num != num3)
      std::cout << "true\n";

   std::cout << "num + num2\n";
   num.printNumber();
   std::cout << " + ";
   num2.printNumber();
   std::cout << " = ";
   num3 = (num + num2);
   num3.printNumber();
   std::cout << '\n';

*/
   Rational num2;
   num2.setNumber();
   num2.printNumber();
   
   std::cout << "num < num2\n";
   if (num < num2)
      std::cout << "true\n";
}


