/* String class, by Naomi Burhoe
   Copyright Spring 2018        */

class String {
  public :
     String(const char* s)
       : len(std::strlen(s)), str(new char[len])
     {
        std::strcpy(str, s, len);
     }
     
     String(const string& s)
       : str(s.str), len(s.len)
     {}
  
     ~String()
     {
        delete [] str;
     }
  private :
     int len;
     char* str;
};
