#include "string.hpp"
#include <iostream>
#include <stdio.h>
#include <string.h>

inline
string::string(const char* s)
   : len(strlen(s)), str(new char[len])
{
   strcpy(str, s);
}

inline
string::string(const string& s)
   : str(s.str), len(s.len)
{}
  
inline
string::~string()
{
    delete [] str;
}
  
inline
void string::printStr()
{
  std::cout << *str << '\n';
}
