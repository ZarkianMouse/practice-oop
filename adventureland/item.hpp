// This file holds the Item class
// Copyright of Naomi Burhoe c. 2018


#pragma once
#include "advland.h"

#include <iosfwd>
#include <string>

class Item {
public :
   Item();
   Item(Location l, std::string d);

   Location getLocate() {return il; }
   void setLocate(Location);
   std::string getDescrip() {return id; }
   
   void operator=(const Item&);
   
   friend bool operator==(Item, Item);
   friend bool operator!=(Item, Item);
   
   ~Item();
   
private :
   Location il; // item location
   std::string id; // item description
};


