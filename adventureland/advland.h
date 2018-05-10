// advland.h
// Holds global variable declarations and Location enum
// also holds declaration for printing locations
#pragma once

#include <iosfwd>


// holds enumerated values for Map Locations
enum Location {
  Inventory = -1,
  Unassigned = 0,
  Swamp = 1,
  Tree = 2,
  Stump = 3,
  Root = 4,
  Hole = 5,
  Hall = 6,
  Cavern = 7,
  EightRoom = 8,
  Anteroom = 9,
  Shore = 10,
  Forest = 11,
  Maze = 12,
  Maze2 = 13,
  Maze3 = 14,
  Maze4 = 15,
  Maze5 = 16,
  Maze6 = 17,
  Chasm = 18,
  Ledge = 19,
  RoyalChamber = 20,
  LedgeThrone = 21,
  ThroneRoom = 22,
  Meadow = 23,
  Trouble = 24,
  Grove = 25,
  Bog = 26,
  PC = 27,
  Branch = 28,
  Empty1 = 29,
  Empty2 = 30,
  Empty3 = 31,
  Empty4 = 32,
  MistRoom = 33
};

#define CL      151+1
#define NL      59+1
#define RL      33+1
#define DL      6+1
#define ML      71+1
#define AR      Forest      // start location
#define IL      60+1    // number of items (item limit)
#define MX      5       // max number of items allowed to carry
#define TT      13      // number of treasures
#define LN      3       // number of characters in commands in item strings
#define LT      125     // number of steps before light goes out
#define TR      Stump       // treasure depository location
#define MAXLINE 79      // max number of characters on one line


#include "item.hpp"
#include "room.hpp"

/* C0%(151), C1%(151), C2%(151), C3%(151),
   C4%(151), C5%(151), C6%(151), C7%(151) action */
extern const unsigned int C[CL][8];

// NV$(59,1) commands
extern const char *NVS[2][NL];

// RM(33) rooms with description and travel
extern Room RM[RL];

#if 0
// RM(33,6) room travel
extern const Location RM[RL][6];

// RS$(33) room description
extern const char *RSS[RL];

#endif

extern Item items[IL];


// MS$(71) messages
extern const char *MSS[ML];

// print locations
std::string print(Location);





