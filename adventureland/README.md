An attempt to translate Adventureland from C to C++
Project for OOP

Necessary Components:
1. Separate implementation from declaration
2. Remove function definitions from main
3. Add commentary to program (the lack of such is confusing...)
4. Better selection menu
5. Add abstractions
   a. User
   b. Locations, items
   c. Enemy class?
6. General reorganization of code for better readability


Current Classes:
1. Item
   The Item class contains a location element which corresponds
   to locations of objects listed in advland.h
   There are 60 possible locations, which initially
   are represented by I2[IL] in advland.h and later
   are updated by the player as the game progresses
   The class header file is item.hpp
   
   Future Updates:
   I plan to add a description element to the Item class
   that will hold strings of data related to the corresponding
   Item location as designated in IAS[] (see advland.h)
   This feature will allow clarification of relationships
   between IA[] (the game item access array) and 
   IAS (item descriptions)


Future Classes:
1. Room
   The Room class will contain a travel array element and a
   description element that will be designated by RM[]
   and RSS[] (see advland.h)
   This will require a declaration in main or as a global
   variable to simplify and clarify relationships
   between the current room and its associated
   travel capacities (where the player can go)

2. To Be Determined
 
