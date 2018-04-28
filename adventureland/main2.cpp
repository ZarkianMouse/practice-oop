// This file is used to test new classes added
// to ensure each class works with required components

#include <iostream>
#include "advland.h"
#include "item.hpp"

int main()
{
   std::cout << "Begin Process\n";
   
   std::cout << "AR = " << print(AR) << '\n';

   std::cout << "Room 33/5: " << print(RM[RL - 1][5]) << '\n';
   
   std::cout << "End Process\n";
   return 0;
}


