// This file holds the Item class
// Copyright of Naomi Burhoe c. 2018

class Item {
public :
   Item()
     : location(0) {}
   Item(signed char l)
     : location(l) {}

   signed char getLocate() {return location; }

   void operator=(int a) { location = a;}
   bool operator==(int a) { return location == a; }
   bool operator!=(int a) { return location != a; }

private :
   signed char location;
};
