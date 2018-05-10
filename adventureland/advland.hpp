// Part of Adventureland translation 
// by: Naomi Burhoe
// Modifications Copyright 2018
// Purpose: holds global variables and function
//	    declarations for program

#pragma once
#include "advland.h"

// global variables
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

// RM(33) rooms with location, description and travel
extern Room RM[RL];

// items(60) items with location and description
extern Item items[IL];

// MS$(71) messages
extern const char *MSS[ML];


// game-play functions
void Sleep(int);
void empty_keyboardbuffer();
Location convertInt(int);
int yes_no();
void welcome();
int get_input();
void look();
void turn();
void action(int, int *);
int get_item_string(int);
int get_action_variable(int *, int);
void carry_drop();
int length(const char *);
void copystring(char *, std::string);
void copystring(char *, const char *);
int comparestring(const char *, std::string);
int comparestring(const char *, const char *);
int check_logics();


