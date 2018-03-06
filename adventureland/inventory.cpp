#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "item.hpp"
#include "inventory.hpp"

void Inventory::addItem(Item i)
{
   inven.push_back(i);
   i.printItem();
   std::cout << " added to inventory\n";
}

void Inventory::removeItem(Item i)
{   
   
   if (std::find(inven.begin(), inven.end(), i) != inven.end())
      
  

}
