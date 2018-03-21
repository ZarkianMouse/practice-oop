// This file holds the Item class
// Copyright of Naomi Burhoe c. 2018

class Item {
public :
   Item();
   Item(signed char l);

   signed char getLocate() {return location; }

   void operator=(int);
   bool operator==(int);
   bool operator!=(int);

private :
   signed char location;
};
