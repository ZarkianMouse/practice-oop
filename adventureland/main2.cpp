// This file is used to test new classes added
// to ensure each class works with required components

#include <iostream>
#include "advland.h"
#include "item.hpp"

int main()
{
   std::cout << "Begin Item Process\n";

   Item IA[IL];
   for (int i=0; i < IL; i++)
   { 
      IA[i] = I2[i];      // reset object locations
      
   }
   
   std::cout << "End Item Process\n";
   return 0;
}


