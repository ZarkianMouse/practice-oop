#pragma once


/* String class, by Naomi Burhoe
   Copyright Spring 2018        */

class string {
  public :

     string() {}

     string(const char* s);
     
     string(const string& s);

     ~string();

     void printStr();

  private :
     int len;
     char* str;
};
