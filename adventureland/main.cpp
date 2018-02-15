/* Adventureland
   Adapted from the original Scott Adams game
   Revisions made by Naomi Burhoe
   Spring 2018 (Jan-May)

   Purpose: to translate Adventureland from C to C++

*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "conio.h"
#include "advland.hpp"
#include "advland.h"


/* dynamic global variables */
signed char     IA[IL];                 /* object locations */
signed int      NV[2];                  /* word numbers, NV[0] = first, NV[1] = second */
signed int      loadflag, endflag;      /* should we load or end? */
signed int      f,f3,f2;
signed int      r, lx, df, sf;
unsigned char   tps[80];                /* input string */
signed int      x,y;

/* externals:
   IA[], I2[], loadflag, endflag, lx, df, sf, r, NV[] */


int main()
{

    int i; // counting variable

    //FILE *fd, file for saving game

    for (i = 0; i < IL; ++i)
	IA[i] = I2[i];       // resets object location

    loadflag = 1;
    endflag = 0;
    srand((unsigned)time(NULL)); // randomize

    std::cout << "Hello everyone! Prepare for a wonderful version of "
              << "Scott Adam's game \"Adventure\nland\". Have fun\n";

    Sleep(5);

    welcome();


    while (!endflag)
    {

    	while (loadflag)
  	{
	    loadflag = 0;
	    r = AR;
	    lx = LT;
	    df = 0;
	    sf = 0;

	    /* Saved Game?
	    std::cout << "\nUse saved game (Y or N)? ");
	    if (yes_no()) // yes
	    {
		std::cout << "Is previously saved game now on the current disk? "
		if (yes_no()) // yes
		{
		    fd.open("adven-1.dat", "rb"); //???
                    sf = getw(fd);
                    lx = getw(fd);
                    df = getw(fd);
		    r = getw(fd);
		    for (i = 0; i < IL; ++i)
		    	IA[i] = getw(fd);   // receives locations from file
			fclose(fd);
		}
		else
		    loadflag = 1; // HERE WE GO AGAIN....
	    } */
	    if (!loadflag)
	    {
		clrscr();
		observeArea();
                //NV[0] = 0;
                //turn();
	    }
	}

	endflag = 1;

    }


    std::cout << "Thanks for playing\n";
    return 0;
}

//borrowed from Ubuntu forums
// for time delay sequence
void Sleep ( int seconds ) 
{ 
  clock_t endwait; 
  endwait = clock () + seconds * CLOCKS_PER_SEC ; 
  while (clock() < endwait) {} 
} 

/* Empty keyboard buffer */
void empty_keyboardbuffer()
{
  while (kbhit()!=0) getch();
}

/* Welcomes user to game */
void welcome()
{
  clrscr();
  std::cout << "WELCOME TO ADVENTURE - 1" << std::endl;
  Sleep(1);
  std::cout << "The object of your adventure is to find" << std::endl;
  Sleep(1);
  std::cout << "treasures and return them" << std::endl;
  Sleep(1);
  std::cout << "to the proper place for you to accumulate " << std::endl;
  Sleep(1);
  std::cout << "points.  I'm your clone.  Give me         " << std::endl;
  Sleep(1);
  std::cout << "commands that consist of a verb & noun,   " << std::endl;
  Sleep(1);
  std::cout << "i.e. GO EAST, TAKE KEY, CLIMB TREE,       " << std::endl;
  Sleep(1);
  std::cout << "SAVE GAME, TAKE INVENTORY, FIND AXE, etc. " << std::endl;
  Sleep(1);
  std::cout << "You'll need some special items to do some " << std::endl;
  Sleep(1);
  std::cout << "things, but I'm sure that you'll be a     " << std::endl;
  Sleep(1);
  std::cout << "good adventurer and figure these things   " << std::endl;
  Sleep(1);
  std::cout << "out (which is most of the fun of this     " << std::endl;
  Sleep(1);
  std::cout << "game)\n\nNote that going in the opposite  " << std::endl;
  Sleep(1);
  std::cout << "direction won't always get you back to    " << std::endl;
  Sleep(1);
  std::cout << "where you were.\n\n\nHAPPY ADVENTURING\n\n\n\n\n";
  Sleep(10);
  empty_keyboardbuffer();
  std::cout << "********************PRESS ANY KEY TO CONTINUE*******************\n\n\n\n\n\n\n                 ";
  while (getch()==0);
  clrscr();
}

void observeArea()
{
    std::cout << "Observing init area\n";


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
