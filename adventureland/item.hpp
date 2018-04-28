// This file holds the initial Item locations and the Item class
// Temp: This file also has Room locations
// Copyright of Naomi Burhoe c. 2018

#include "advland.h"

class Item {
public :
   Item();
   Item(Location l);

   Location getLocate() {return il; }

   void operator=(Location);
   bool operator==(Location);
   bool operator!=(Location);

private :
   Location il;
};
