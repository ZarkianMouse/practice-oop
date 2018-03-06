#include <iostream>
#include <string>
#include "item.hpp"

Item::Item(std::string i) : item(i)
{}

void Item::printItem()
{
   std::cout << item;
} 
