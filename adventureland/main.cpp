/* Adventureland
   Adapted from the original Scott Adams game
   Revisions made by Naomi Burhoe
   Spring 2018 (Jan-May)

   Purpose: to translate Adventureland from C to C++

*/


#include "advland.hpp"
#include <iostream>


int main()
{
    std::cout << "Hello world!" << std::endl;
    welcome();

    return 0;
}



/*
   Variables for use:
   bool            loadflag, endflag;    should we load or end?
   signed char     IA[IL];               object locations 
   signed int      NV[2];                word numbers, NV[0] = first, NV[1] = second
   
   signed int      f,f3,f2;
   signed int      r, lx, df, sf;
   unsigned char   tps[80];              input string
   signed int      x,y;


   Most important variables:
   IA[], I2[], loadflag, endflag, lx, df, sf, r, NV[]


   Necessary Functions (need renamed) with descriptions for use

   signed int yes_no();
   Empty keyboard, get Y(es) or N(o), printf character with carriage return
   
   void empty_keyboardbuffer();
   Empty keyboard buffer
   
   void welcome();
   Welcome to Adventureland
   
   int get_input();
   Evaluate user input
   Variables used: tps, NV[], NVS[][]
   
   void observeArea(); (void look(void))
   Print location description, exits and visible items
   Variables used: df, IA[], RSS[][], tps, r, RM[][], NVS[][]
   
   int get_item_string(int);
   Discard unwanted string at end of item description
   Returns number of printable characters in item description
   Variables used: IAS[]

   void turn();
   Purpose unclear

   void action(int ac, int *ip);
   Takes actions based on input
   Variables used: MSS[], IA[], NV[], x, y, r, df, sf ...

   int get_action_variable(int *ip, int x);
   Purpose unclear
   Variables used: C[][]

   void carry_drop(void);
   Can I carry or drop it? If so, do it. 

   int length(const char *s);
   Purpose unclear

   void copystring(unsigned char *dest, unsigned const char *source);
   copies strings and such (string class usage?)

   int comparestring(const char *s1, const char *s2);
   compares strings (string class usage?)

   int check_logics(void);
   checks if logic is correct in various situations
   Variables used: C[][], x, r, IA[], sf, f2


   
*/
