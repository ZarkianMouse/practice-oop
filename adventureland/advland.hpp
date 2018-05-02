#include "advland.h"

/* Initial header file for the Adventureland revisions by Naomi Burhoe
   Simply to hold basic functions right now                           */
void Sleep(int);
void empty_keyboardbuffer();
Location convertInt(int);
int yes_no();
void welcome();
int get_input();
//void observeArea();
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


