#include "string.hpp"
#include <iostream>
#include <cstring>

inline
mstring::mstring(const char* s)
   : len(std::strlen(s)), str(new char[len])
{
   std::strcpy(str, s);
}

inline
mstring::mstring(const mstring& s)
   : str(s.str), len(s.len)
{}

inline
mstring::~mstring()
{
    delete [] str;
}

inline
void mstring::printStr()
{
  std::cout << *str << '\n';
}

void f()
{
    std::cout << "This file works\n";
}
