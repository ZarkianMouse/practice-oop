
#include <cstring>

class String
{
public:
  String(const char* s)
    : len(std::strlen(s)), str(new char[len])
  {
    std::strncpy(str, s, len);
  }

  String(const String& s)
    : str(s.str), len(s.len)
  { }

  ~String()
  {
    delete[] str;
  }

private:
  int len;
  char* str;
};


int main() {
  String s1 = "foo";
  String s2 = s1;
} // CRASH