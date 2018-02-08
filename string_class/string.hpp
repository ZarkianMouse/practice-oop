#ifndef STRING_HPP
#define STRING_HPP


#include <ostream>
/* String class, by Naomi Burhoe
   Copyright Spring 2018        */

class mstring {
  public :

     mstring() {}

     mstring(const char* s);

     mstring(const mstring& s);



     int getLen();
     char* getStr();
     mstring& operator=(mstring& b);
     mstring& operator=(char *s);

     friend std::ostream& operator<<(std::ostream &out,const mstring &s);// out stream displays the string
     friend bool operator==(const mstring& s1, const mstring & s2);// checks if both strings are equal
     friend bool operator<(const mstring& s1, const mstring &s2);

      ~mstring();

  private :
     int len;
     char* str;
};

#endif // STRING_HPP
