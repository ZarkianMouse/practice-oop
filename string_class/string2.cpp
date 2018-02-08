#include "string.hpp"
#include <iostream>
#include <cstring>


mstring::mstring(const char* s)
   : len(std::strlen(s)), str(new char[len])
{
   std::strcpy(str, s);
}


mstring::mstring(const mstring& s)
   : len(s.len), str(new char[len])
{
   std::strcpy(str, s.str);
}


mstring& mstring::operator=(mstring& b)
{
    len = b.getLen();
    int k = 0;


    while (k < len)
    {
        str[k] = b.str[k];
        ++k;
    }

    return *this;
}

mstring& mstring::operator=(char *s)
{
    len = std::strlen(s);
    std::strcpy(str, s);
    return *this;
}

int mstring::getLen()
{
    return len;
}

char* mstring::getStr()
{
    return str;
}



bool operator==(const mstring &s1, const mstring &s2)
{
	if(s1.len == s2.len)
	{
		int i = s1.len;
		int j = 0;
		int k = 0;

		while(k != i)
		{
			if(s1.str[k] != s2.str[k])
                j++;
			k++;
		}

		std::cout << k << " " << i << std::endl;

		if(j != 0)
            return false;
		else
            return true;
	}
	else
      return false;

}

std::ostream& operator <<(std::ostream &out, const mstring& s)
{
    out << s.str;
    return out;
}


bool operator<(const mstring& s1, const mstring &s2)
{
    if (s1 == s2)
       return false;
    else
    {
        int i = s1.len;
        int j = 0;
        int k = 0;

        while (k != i)
        {
            if (s1.str[k] == s2.str[k])
               k++;
            else if (s1.str[k] < s2.str[k])
               return false;
            else if (k > i)
            {
                std::cout << s1.str << " = " << s2.str << '\n';
                return true;
            }

        }
    }
    return true;
}


mstring::~mstring()
{
    delete [] str;
    std::cout << "str deleted\n";
}
