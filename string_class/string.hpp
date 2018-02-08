#ifndef STRING_HPP
#define STRING_HPP



/* String class, by Naomi Burhoe
   Copyright Spring 2018        */

class mstring {
  public :

     mstring() {}

     mstring(const char* s);

     mstring(const mstring& s);

     ~mstring();

     void printStr();

  private :
     int len;
     char* str;
};

#endif // STRING_HPP
