// This file is used to test new classes added
// to ensure each class works with required components
// TODO: Test Room class with updated variables

#include "advland.h"
#include "advland.hpp"
#include "room.hpp"
#include "item.hpp"

#include <iostream>
#include <vector>

std::string convertLocat(Location);

int main()
{
   std::cout << "Begin Process\n";
   
   Room myRoom;
   
   std::vector<Location> direct =
   	{Unassigned,Unassigned,Unassigned,Unassigned,Unassigned,Swamp};
   Room myRoom2("*I'm in the top of a tall cypress tree.", direct);
   
   direct = myRoom.getDirect();
   
   for (auto i : direct)
   {
      std::cout << convertLocat(i) << " ";
   }
   
   std::cout << "\n\nTree:" << myRoom2.getDescrip() << "\n";
   for (auto i : myRoom2.getDirect())
   {
      std::cout << convertLocat(i) << " ";
   }
   std::cout << "\n\n";
   
   std::cout << "End Process\n";
   return 0;
}

std::string convertLocat(Location l)
{
   switch(l) {
   case Inventory:
      return "Inventory";

   case Unassigned:
      return "Unassigned";
   case Swamp:
      return "Swamp";
   case Tree:
      return "Tree";
   case Stump:
      return "Stump";
   case Root:
      return "Root";
   case Hole:
      return "Hole";
   case Hall:
      return "Hall";
   case Cavern:
      return "Cavern";
   case EightRoom:
      return "EightRoom";
   case Anteroom:
      return "Anteroom";

   case Shore:
      return "Shore";
   case Forest:
      return "Forest";
   case Maze:
      return "Maze";
   case Maze2:
      return "Maze2";
   case Maze3:
      return "Maze3";
   case Maze4:
      return "Maze4";
   case Maze5:
      return "Maze5";
   case Maze6:
      return "Maze6";
   case Chasm:
      return "Chasm";
   case Ledge:
      return "Ledge";

   case RoyalChamber:
      return "RoyalChamber";
   case LedgeThrone:
      return "LedgeThrone";
   case ThroneRoom:
      return "ThroneRoom";
   case Meadow:
      return "Meadow";
   case Trouble:
      return "Trouble";
   case Grove:
      return "Grove";
   case Bog:
      return "Bog";
   case PC:
      return "PC";
   case Branch:
      return "Branch";
   case Empty1:
      return "Empty1";

   case Empty2:
      return "Empty2";
   case Empty3:
      return "Empty3";
   case Empty4:
      return "Empty4";
   case MistRoom:
      return "MistRoom";
   }
}


std::string direct(int d)
{
  switch(d) {
    case 0:
       return "NORTH";
    case 1:
       return "EAST";
    case 2:
       return "SOUTH";
    case 3:
       return "WEST";
    case 4:
       return "UP";
    case 5:
       return "DOWN";
  }
}

std::string convertIn(int n)
{
   switch(n) {
   case -1:
      return "Inventory";

   case 0:
      return "Unassigned";
   case 1:
      return "Swamp";
   case 2:
      return "Tree";
   case 3:
      return "Stump";
   case 4:
      return "Root";
   case 5:
      return "Hole";
   case 6:
      return "Hall";
   case 7:
      return "Cavern";
   case 8:
      return "EightRoom";
   case 9:
      return "Anteroom";

   case 10:
      return "Shore";
   case 11:
      return "Forest";
   case 12:
      return "Maze";
   case 13:
      return "Maze2";
   case 14:
      return "Maze3";
   case 15:
      return "Maze4";
   case 16:
      return "Maze5";
   case 17:
      return "Maze6";
   case 18:
      return "Chasm";
   case 19:
      return "Ledge";

   case 20:
      return "RoyalChamber";
   case 21:
      return "LedgeThrone";
   case 22:
      return "ThroneRoom";
   case 23:
      return "Meadow";
   case 24:
      return "Trouble";
   case 25:
      return "Grove";
   case 26:
      return "Bog";
   case 27:
      return "PC";
   case 28:
      return "Branch";
   case 29:
      return "Empty1";

   case 30:
      return "Empty2";
   case 31:
      return "Empty3";
   case 32:
      return "Empty4";
   case 33:
      return "MistRoom";
   }
}

