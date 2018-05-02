// This file holds the Room class
// Copyright of Naomi Burhoe c. 2018


#pragma once
#include "advland.h"

#include <iosfwd>
#include <string>

class Room {
public :
   Room();
   Room(std::string, Location []);

   std::string getDescrip() {return rd; }
   
   void operator=(const Room&);
   
   
   friend bool operator==(Room, Room);
   friend bool operator!=(Room, Room);
   
private :
   std::string rd; // room description
   Location direct[DL]; // directions available
};
