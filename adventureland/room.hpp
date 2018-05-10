// This file holds the Room class
// Copyright of Naomi Burhoe c. 2018

// TODO : add Location rl to class

#pragma once
#include "advland.h"

#include <iosfwd>
#include <string>
#include <vector>

class Room {
public :
   Room();
   Room(Location, std::string, std::vector<Location>);

   Location getRL() { return rl; }
   std::string getRD() { return rd; }
   std::vector<Location> getDirect() { return direct; }
   void operator=(const Room&);
   
   friend bool operator==(Room, Room);
   friend bool operator!=(Room, Room);
   
   ~Room();
   
private :
   Location rl;
   std::string rd; // room description
   std::vector<Location> direct; // directions available
};
