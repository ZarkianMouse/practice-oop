/* Adventureland
   Adapted from the original Scott Adams game
   Revisions made by Naomi Burhoe
   Spring 2018 (Jan-May)

   Purpose: to translate Adventureland from C to C++

   Notes:
      Location enum - lists out possible locations for
                      rooms and objects
      Item class - holds location element and description element
                   description element is listed as a std::string
*/

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits>
#include <cstring>
#include <string>
#include <curses.h>
#include "conio.h"
#include "advland.hpp"
#include "advland.h"
#include "item.hpp"
#include "room.hpp"

/* dynamic global variables */
Item     IA[IL];       /* object locations */
signed int      NV[2]; /* word numbers, NV[0] = first, NV[1] = second */
signed int      loadflag, endflag; /* should we load or end? */
signed int      f,f3,f2;
signed int      r, lx, df, sf;
char   tps[80]; /* input string */
signed int      x,y;


/* externals:
   IA[], items[], loadflag, endflag, lx, df, sf, r, NV[] */
int main()
{
  int i;        //counting variable
  FILE *fd;     // load file handle

  for (i=0;i<IL;i++) IA[i] = items[i];       // reset object locations
  loadflag = 1;
  endflag = 0;
  srand((unsigned)time(NULL));  // randomize
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

      std::cin.ignore();
      printw("\nUse saved game (Y or N)? ");

      // I removed the Load/Save File sequence because I did not find
      // it a necessary component of the program
      // I had more important things to focus on with the restructuring
      // of the program than fixing how this worked
      // Plus I don't have the right kind of FILE to make it work
      /*
      if (yes_no()) // yes
      {
	printw("Is previously saved game now on the current disk? ");
	if (yes_no()) // yes
	{
	  fd = fopen("ADVEN-1.DAT","rb");
	  sf = getw(fd);
	  lx = getw(fd);
	  df = getw(fd);
	  r = getw(fd);
	  for (i=0;i<IL;i++) IA[i] = getw(fd);
	  fclose(fd);
	}
	else loadflag = 1;      // HERE WE GO AGAIN...
      } */
      
      if (!loadflag)
      {
	clrscr();
	look();
	NV[0] = 0;
	turn();
      } 
    }
    if (!get_input())
    {
      turn();
      if (!loadflag && !endflag)
      {
	if (IA[9].getLocate() == Inventory)
	{
	  lx--;
	  if (lx < 0)
	  {
	    printw("light has run out!\n");
	    IA[9].setLocate(Unassigned);
	  }
	  else if (lx < 25) printw("light runs out in %u turns!",lx);
	}
	NV[0] = 0;
	turn();
      }
    }
  }

    printw("Thanks for playing\n");
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

// conversion for integers
// (primarily to make combination with Locations easier)
// pre: receives signed int
// post: returns Location value corresponding to int value
//   ex. 0 -> Unassigned
Location convertInt(signed int a)
{
   switch(a) {
   case -1:
      return Inventory;

   case 0:
      return Unassigned;
   case 1:
      return Swamp;
   case 2:
      return Tree;
   case 3:
      return Stump;
   case 4:
      return Root;
   case 5:
      return Hole;
   case 6:
      return Hall;
   case 7:
      return Cavern;
   case 8:
      return EightRoom;
   case 9:
      return Anteroom;

   case 10:
      return Shore;
   case 11:
      return Forest;
   case 12:
      return Maze;
   case 13:
      return Maze2;
   case 14:
      return Maze3;
   case 15:
      return Maze4;
   case 16:
      return Maze5;
   case 17:
      return Maze6;
   case 18:
      return Chasm;
   case 19:
      return Ledge;

   case 20:
      return RoyalChamber;
   case 21:
      return LedgeThrone;
   case 22:
      return ThroneRoom;
   case 23:
      return Meadow;
   case 24:
      return Trouble;
   case 25:
      return Grove;
   case 26:
      return Bog;
   case 27:
      return PC;
   case 28:
      return Branch;
   case 29:
      return Empty1;

   case 30:
      return Empty2;
   case 31:
      return Empty3;
   case 32:
      return Empty4;
   case 33:
      return MistRoom;
   }
}

/* Empty keyboard, get Y(es) or N(o), 
     printw character with carriage return */
int yes_no()
{
  int ch;

  do
  {
    ch = getch();
    if (ch > 96) ch = ch - 32;
  } while (ch!=89 && ch!=78);
   printw("%c\n",ch);
  return(ch==89);  // 1 if Y, 0 if N
}

/* Welcomes user to game */
void welcome()
{
  clrscr();
  
  printw("\nWELCOME TO ADVENTURE - 1\n\n\n");
  printw("The object of your adventure is to find treasures and return ");
  printw("them to the proper place for you to accumulate points. ");
  printw("I'm your clone.  Give me commands that consist of a verb ");
  printw("and a noun, i.e. GO EAST, TAKE KEY, CLIMB TREE, SAVE ");
  printw("GAME, TAKE INVENTORY, FIND AXE, etc.  You'll need some ");
  printw("special items to do some things, but I'm sure that you'll ");
  printw("be a good adventurer and figure these things out (which ");
  printw("is most of the fun of this game)\n\nNote that going in");
  printw(" the opposite direction won't always get you back to where");
  printw(" you were.\n\n\nHAPPY ADVENTURING\n\n\n\n\n\n");
  
empty_keyboardbuffer();
  printw("********************PRESS ANY KEY TO CONTINUE*******************\n");
  while (getch()==0);
  clrscr();
}


/* Evaluate user input */
/* Externals:
   tps, NV[], NVS[][] */
// pre: nothing
// post: receives input from user by way of two strings
//       returns 0 if user inputted a correct value
//               1 otherwise
int get_input()
{
  int i,j;              // counting variables
  char *word[2];       // first and second string
  const char  *s;

  std::string tps1, tps2;

  // reads in commands for clone
  printw("\nTell me what to do? \n ");
  refresh();

  std::cin >> tps1 >> tps2;
  tps1 = tps1 + " " + tps2;
  // changes input string to c_string for use in other parts of program
  strcpy(tps, tps1.c_str());

  // changes values in input string to uppercase for use in other comparisons
  for (i=0;i<length(tps);i++) tps[i]=toupper(tps[i]);
  printw("You entered: %s\n", tps);
  refresh();

  // checks individually entered words
  i = 0;
  while (tps[i]==' ' && tps[i]!='\0') i++;  // go to first word
  word[0] = tps+i;
  while (tps[i]!=' ' && tps[i]!='\0') i++;  // go to next space
  while (tps[i]==' ' && tps[i]!='\0') i++;  // go to next word
  word[1] = tps+i;

  
  // still trying to figure out how this section works
  for (j=0;j<2;j++) // no more than LN chars 
  {
    i = 0;
    while(word[j][i]!=' ' && word[j][i]!='\0' && i<LN) i++;
    word[j][i]='\0';
  }
  for (i=0;i<2;i++)
  {
    NV[i] = 0;
    if (word[i][0]!='\0')
    {
      for (j=0;j<NL;j++)
      {
	s = NVS[i][j];
	if (s[0] == '*') s++;  // skip special char
	if (comparestring(word[i],s)==0)
	{
	  NV[i] = j;
	  j = NL;
	  while (NVS[i][NV[i]][0] == '*') NV[i]--;
	}
      }
    }
  }
  if ((NV[0] < 1) || (word[1][0]!='\0' && NV[1] < 1))
  {
    printw("You use word(s) I don't know.!\n");
    refresh();
    return(1);
  }
  else return(0);
}

/* Print location description, exits and visible items */
/* Externals:
   df, IA[], RSS[][], tps, r, RM[][], NVS[][] */
// pre: nothing
// post: returns nothing
//       examines values from IA Item array
//       prints them to screen as required
void look()
{
  int k;        /* Flag */
  int i,j;

  if (df && (IA[9].getLocate() !=Inventory && IA[9].getLocate()!=convertInt(r))) printw("I can't see.  It's too dark!\n");
  else
  {
    if (RSS[r][0] == '*') printf(RSS[r]+1);
    else
    {
      printw("I'm in a %s",RSS[r]);
    }
    k = -1;
    for (i=0;i<IL;i++)
    {
      if (k && (IA[i].getLocate() ==convertInt(r)))
      {
	printw("\n\nVISIBLE ITEMS HERE:\n");
	k = 0;
      }
      if (IA[i].getLocate() == convertInt(r))
      {
	j = get_item_string(i);
	if ((wherex() + j + 3) > MAXLINE) printw("\n");
	printw("%.*s.  ",j,IA[i].getDescrip().c_str());
      }
    }
    printw("\n");
    k = -1;
    for (i=0;i<6;i++)
    {
      if (k && (RM[r][i]!=Unassigned))
      {
	printw("\nObvious exits: \n");
	k = 0;
      }
      if (RM[r][i]!=Unassigned)
      {
	printw("%s ",NVS[1][i + 1]);
      }
    }
    printw("\n\n");
  }
}

// function for motion in game
// pre: receives nothing, but does use values from IA[], df
//      RM[], NV[], r, C[]
// post: updates IA[] and outputs messages based on actions received
//       from user
void turn()
{
  int i,j,ac;

  if (NV[0] == 1 && NV[1] < 7)
  {
    i = (df) && (IA[9].getLocate() != convertInt(r)) && (IA[9].getLocate() != Inventory);
    if (i) printw("Dangerous to move in the dark!\n");
    if (NV[1] < 1) printw("Give me a direction too.\n");
    else
    {
      j = RM[r][NV[1] - 1];
      if (j == Unassigned && !i) printw("I can't go in that direction.\n");
      else
      {
	if (j == Unassigned && i)
	{
	  printw("I fell down and broke my neck.\n");
	  j = RL;
	  df = 0;
	}
	if (!i) clrscr();

	r = j;
	look();
      }
    }
  }
  else
  {
    f = -1;
    f2 = -1;
    f3 = 0;
    x = 0;
    do
    {
      i = C[x][0] / 150;
      if ((NV[0] == 0) && (i != 0)) x = CL;
      else
      {
	if (NV[0] == i)
	{
	  i = C[x][0] % 150;
	  if ((i == NV[1] || i == 0) || (NV[0] == 0 && (rand()%100+1) <= i))
	  {
	    f = 0;
	    f3 = -1;
	    f2 = check_logics();
	    if (f2)
	    {
	      i = Unassigned;
	      y = 1;
	      do
	      {
		j = (y - 1) / 2 + 6;
		ac = C[x][j] / 150;
		if (y == 2 || y == 4) ac = C[x][j] % 150;
		action(ac,&i);
		if (loadflag == 1 || endflag == 1)
		{
		  y = 10;
		  x = CL;
		}
		y++;
	      } while (y <= 4);
	      if (y < 10) if (NV[0]!= 0) x = CL;
	    }
	  }
	}
      }
      x++;
    } while (x < CL);
    if (NV[0] != 0) carry_drop();
  }
}

/* externals:
   MSS[], IA[], NV[], x, y, r, df, sf ... */
// pre: receives action input and i (based on C[][])
// post: returns nothing
//       performs action based on received input
void action(int ac, int *ip)
{
  FILE *fd;
  int i,j,p;

  // print messages 52+
  if (ac > 101) printf("%s\n",MSS[ac - 50]);
  // print messages 1-51
  if (ac > 0 && ac < 52) printf("%s\n",MSS[ac]);
  // get/take object
  if (ac == 52)
  {
    j = 0;
    for (i=1;i<IL;i++) if (IA[i].getLocate() == Inventory) j++;
    if (j >= MX)
    {
      printw("I've too much to carry!\n");
      if (NV[0] != 0) x = CL;
      y = 10;
    }
    else IA[get_action_variable(ip,x)].setLocate(Inventory);
  }
  // drop object
  if (ac == 53) 
     IA[get_action_variable(ip,x)].setLocate(convertInt(r));
  // go to room
  if (ac == 54) 
     r = get_action_variable(ip,x);
  // delete object
  if (ac == 55 || ac == 59) 
     IA[get_action_variable(ip,x)].setLocate(Unassigned);
  // dark on
  if (ac == 56) df = -1;
  // dark off
  if (ac == 57) df = 0;
  // set flag
  if (ac == 58) sf = 1 << get_action_variable(ip,x) | sf;
  // clear flag
  if (ac == 60) sf = sf ^ 1 << get_action_variable(ip,x);
  // kill player
  if (ac == 61)
  {
    printw("I'm dead...\n");
    r = RL-1;
    df = 0;
    look();
  }
  // move object to location
  if (ac == 62)
  {
    i = get_action_variable(ip,x);
    IA[i].setLocate(convertInt(get_action_variable(ip,x)));
  }
  // game over
  if (ac == 63)
  {
    printw("The game is now over.\nAnother game? ");
    if (!yes_no())  /* No */ endflag = 1;
    else /* Yes */
    {
      for (i=0;i<IL;i++) IA[i] = items[i];
      loadflag = 1;
    }
  }
  // look around
  if (ac == 64) look();
  // score
  if (ac == 65)
  {
    j = 0;
    for (i=1;i<IL;i++) if (IA[i].getLocate() == TR) if (IA[i].getDescrip()[0] == '*') j++;
    printw("I've stored %u treasures.  On a scale\nof 0 to 100, that rates a %u.\n",j,j*100/TT);
    if (j == TT)
    {
      printw("Well done.\nThe game is now over.\nAnother game? ");
      if (!yes_no())  /* No */ endflag = 1;
      else
      {
	for (i=0;i<IL;i++) IA[i].setLocate(items[i].getLocate());
	loadflag = 1;
      }
    }
  }
  // check inventory
  if (ac == 66)
  {
    printw("I'm carrying:\n");
    j = -1;
    for (i=0;i<IL;i++)
    {
      if (IA[i].getLocate() == Inventory)
      {
	p = get_item_string(i);
	if ((p + wherex() + 2) > MAXLINE) printw("\n");
	printw("%.*s. ",p,IA[i].getDescrip().c_str());
	j = 0;
      }
    }
    if (j) printw("Nothing!\n");
  }
  // set flag 0
  if (ac == 67) sf = 1 | sf;
  // clear flag 0
  if (ac == 68) sf = sf ^ 1;
  // refill lamp
  if (ac == 69)
  {
    lx = LT;
    IA[9].setLocate(Inventory);
  }
  // clear screen
  if (ac == 70) clrscr();
  // save game
  if (ac == 71)
  {
    printw("Is the current drive ready to receive the saved game? ");
    if (yes_no())
    {
      fd = fopen("ADVEN-1.DAT","wb");
      putw(sf,fd);
      putw(lx,fd);
      putw(df,fd);
      putw(r,fd);
      for (i=0;i<IL;i++) putw(IA[i].getLocate(),fd);
      fclose(fd);
    }
    printw("\n");
  }
  // swap object x with object y
  if (ac == 72)
  {
    j = get_action_variable(ip,x);
    p = get_action_variable(ip,x);
    Location il = IA[j].getLocate();
    IA[j].setLocate(IA[p].getLocate());
    IA[p].setLocate(il);
  }
}

/* Discard unwanted string at end of item description */
/* Externals:
   IAS[] */
/* Returns number of printable characters in item description */
int get_item_string(int i)
{
  int p;

  p = IA[i].getDescrip().length(); /* points to back of string */
  if (IA[i].getDescrip()[p-1] == '/')
  {
    do
      p--;
    while (p>0 && IA[i].getDescrip()[p-1]!='/');
    if (IA[i].getDescrip()[p-1]!='/')
       p = IA[i].getDescrip().length(); else p--;
  }
  return(p);
}

/* Externals: C[][] */
int get_action_variable(int *p, int x)
{
  do
  {
    (*p)++;
    if (*p < 1 || *p > 5) *p = 1;
  } while (C[x][*p] % 20!=0);
  return(C[x][*p] / 20);
}


/* NV[2]: word numbers, NV[0] = first, NV[1] = second */
/* Can I carry or drop it? If so, do it. */
void carry_drop()
{
  int ll,i,j,l,k;

  // 10 = TAK(E), 18 = DRO(P)
  if ((NV[0] == 10 || NV[0] == 18) && (!f3))
  {
    if (NV[1] == 0)
    {
      printw("What?\n");
      f = 0;
    }
    else
    {
      if (NV[0] == 10)
      {
	l = 0;
	for (i=0;i<IL;i++) if (IA[i].getLocate() == Inventory) l++;
      }
      if (NV[0] == 10 && l >= MX)
      {
	printw("I've too much to carry!\n");
	f = 0;
      }
      else
      {
	k = 0;
	for (j=0;j<IL;j++)
	{
	  ll = IA[j].getDescrip().length() - 1;
	  if (IA[j].getDescrip()[ll] == '/')
	  {
	    copystring(tps,IA[j].getDescrip());
	    tps[ll] = '\0';     /* get one shorter */
	    while (ll>1)
	    {
	      ll--;
	      if (tps[ll] == '/')
	      {
		ll++;   /* first char in item name */
		tps[ll+LN] = '\0';      /* make sure string is no longer than 3 chars */
		if (comparestring(tps+ll,NVS[1][NV[1]])==0)
		{
		  if (NV[0] == 10)
		  {
		    if (IA[j].getLocate() != convertInt(r)) k = 2;
		    else
		    {
		      IA[j].setLocate(Inventory);
		      k = 3;
		      printw("OK, \n");
		      j = IL;
		    }
		  }
		  else
		  {
		    if (IA[j].getLocate() != Inventory) k=1;
		    else
		    {
		      IA[j].setLocate(convertInt(r));
		      k = 3;
		      printw("OK, \n");
		      j = IL;
		    }
		  }
		}
		ll = 1;
	      }
	    }
	  }
	}
	if (k == 1) printw("I'm not carrying it!\n");
	if (k == 2) printw("I don't see it here.\n");
	if (k == 0)
	{
	  if (!f3)
	  {
	    printw("It's beyond my power to do that.\n");
	    f = 0;
	  }
	}
	else f = 0;
      }
    }
  }
  if (f) printw("I don't understand your command.\n");
  else if (!f2) printw("I can't do that yet.\n");
}

// receives c_str
// returns length of c_str
int length(const char *s)
{
  int i;

  i = 0;
  while (s[i] != '\0') i++;
  return(i);
}

// receives source str and destination str
// copies contents of source str to destination str
void copystring(char *dest, std::string source)
{
  int i;

  i = 0;
  while (source[i]!='\0')
  {
    dest[i] = source[i];
    i++;
  }
  dest[i] = '\0';
}

// receives source str and destination str
// copies contents of source str to destination str
void copystring(char *dest, const char *source)
{
  int i;

  i = 0;
  while (source[i]!='\0')
  {
    dest[i] = source[i];
    i++;
  }
  dest[i] = '\0';
}

// receives two str
// returns 0 if strs are inequal
//         1 otherwise
int comparestring(const char *s1, std::string s2)
{
  int i;

  i = 0;
  while (s1[i]==s2[i] && s1[i]!='\0') i++;
  if (s1[i]=='\0' || s2[i]=='\0') return(0); else return(1);
}

// receives two str
// returns 0 if strs are inequal
//         1 otherwise
int comparestring(const char *s1, const char *s2)
{
  int i;

  i = 0;
  while (s1[i]==s2[i] && s1[i]!='\0') i++;
  if (s1[i]=='\0' || s2[i]=='\0') return(0); else return(1);
}

/* externals:
   C[][], x, r, IA[], sf, f2 */
int check_logics()
{
  int y,ll,k,i,f1;
  Location rl = convertInt(r);
  f2 = -1;
  y = 1;
  do
  {
    ll = C[x][y] / 20;
    k = C[x][y] % 20;
    f1 = -1;
    if (k == 1) f1 = -(IA[ll].getLocate() == Inventory);
    if (k == 2) f1 = -(IA[ll].getLocate() == rl);
    if (k == 3) f1 = -(IA[ll].getLocate() == rl || IA[ll].getLocate() == Inventory);
    if (k == 4) f1 = -(r == ll);
    if (k == 5) f1 = -(IA[ll].getLocate() != rl);
    if (k == 6) f1 = -(IA[ll].getLocate() != Inventory);
    if (k == 7) f1 = -(ll != r);
    if (k == 8)
    {
      f1 = sf & 1<<ll;
      f1 = -(f1 != 0);
    }
    if (k == 9)
    {
      f1 = sf & 1<<ll;
      f1 = -(f1 == 0);
    }
    if (k == 10)
    {
      f1 = 0;
      for (i=0;i<IL;i++)
      {
	if (IA[i].getLocate() == Inventory)
	{
	  f1 = -1;
	  i = IL;
	}
      }
    }
    if (k == 11)
    {
      f1 = -1;
      for (i=0;i<IL;i++)
      {
	if (IA[i].getLocate() == Inventory)
	{
	  f1 = 0;
	  i = IL;
	}
      }
    }
    if (k == 12) f1 = -(IA[ll].getLocate() != Inventory && IA[ll].getLocate() != rl);
    if (k == 13) f1 = -(IA[ll].getLocate() != Unassigned);
    if (k == 14) f1 = -(IA[ll].getLocate() == Unassigned);
    f2 = -(f2 && f1);
    y++;
  } while ((y <= 5) && f2);
  return(f2);
}



