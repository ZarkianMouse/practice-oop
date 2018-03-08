/* Rational Numbers by Naomi Burhoe */

#include <iostream>
#include "rational.hpp"

int main()
{
   std::cout << "Hello there\n";
 
   // default construction
   Rational num;
   // testing >>
   std::cin >> num;
   // testing <<
   //std::cout << "num = " << num << '\n';

   std::cout << "\nTesting Comparison Operators\n";
   Rational num2;
   std::cin >> num2;
   
   // testing ==
   std::cout << num << " == " << num2 << ": ";
   if (num == num2)
      std::cout << "true\n";
   else
      std::cout << "false\n";
   
   // testing !=
   std::cout << num << " != " << num2 << ": ";
   if (num != num2)
      std::cout << "true\n";
   else
      std::cout << "false\n";

   // testing <=
   std::cout << num << " <= " << num2 << ": ";
   if (num <= num2)
      std::cout << "true\n";
   else
      std::cout << "false\n";

   // testing assignments, and for use in next comparison
   Rational num3 = num2;
   num2 = num;
   num = num3;

   // testing >=
   std::cout << num << " >= " << num2 << ": ";
   if (num >= num2)
      std::cout << "true\n";
   else
       std::cout << "false\n";

   std::cout << "\nTesting Arithmetic Operators\n";
   // testing +
   std::cout << num << " + " << num2 << " = ";
   num3 = num + num2;
   std::cout << num3 << '\n';
   
   // testing -
   std::cout << num << " - " << num2 << " = ";
   num3 = num - num2;
   std::cout << num3 << '\n';

   // testing *
   std::cout << num << " * " << num2 << " = ";
   num3 = num * num2;
   std::cout << num3 << '\n';

   // testin /
   std::cout << '(' << num << ") / (" << num2 << ") = ";
   if (num2.getNum() != 0)
   {
      num3 = num / num2;
      std::cout << num3 << '\n';
   }
   else
      std::cout << "Division by Zero is not allowed\n";
}


