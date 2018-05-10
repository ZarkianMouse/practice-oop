An attempt to translate Adventureland from C to C++
Project for OOP

Base Abstraction:
1. Location

Current Classes:
1. Item

   The Item class contains:
      a location element which corresponds to locations 
       of objects listed in advland.h
      a description element (std::string)
      
   Items in the game can be found in the items array
   in advland.h

2. Room

   The Room class contains:
     a location element
     a description element (std::string)
     a direction element (vector of locations)
     
   Rooms in the game can be found in the RM array
