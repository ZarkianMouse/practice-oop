
#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <string>

// TODO: Write your JSON class hierarchy here.

struct Value {

   Value();
   Value(char* c) : val(c) {}
   Value(std::string str)
   {
       for (int i = 0; i < str.length(); ++i)
       {
           val[i] = str[i];
       }

   }
   virtual void print();

   char* val;

   
};


struct Bool : Value {
   Bool();
   Bool(bool b) : TF(b) {}

   void print() override
   {
       std::cout << TF << '\n';

   }

   bool TF;

};


struct Null : Value {
   Null();
   Null(char* c) : val(c) {}

   void print() override
   {
       std::cout << *val << '\n';

   }

   void operator=(const Value* v)
   {
       val = v->val;
   }
   char* val;
};


struct String : Value {
   String();
   String(char* c) : val(c) {}

   void print() override
   {
       std::cout << *val << '\n';

   }

   char* val;
};


struct Number : Value {
   Number();
   Number(double n) : num(n) {}

   void print() override
   {
       std::cout << num << '\n';

   }

   double num;

};


struct Array : Value {
   Array();
   Array(char* c): val(c) {}

   void print() override
   {
       std::cout << *val << '\n';

   }

  char* val;
};


struct Object : Value {
   Object();
   Object(char* c) : val(c) {}

   void print() override
   {
       std::cout << *val << '\n';

   }
   char* val;
};


