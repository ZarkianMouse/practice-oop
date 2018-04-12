
#include <iostream>
#include <iomanip>
#include <map>
#include <vector>

// TODO: Write your JSON class hierarchy here.

struct Value {

   Value();
   Value(char* c) : val(c);

   char* val;

};


struct Bool : Value {
   Bool();
   Bool(bool b) : TF(b);

   bool TF;

};


struct Null : Value {
   Null();
   Null(char* c) : val(c);

};


struct String : Value {
   String();
   String(char* c) : val(c);

};


struct Number : Value {
   Number();
   Number(int n) : num(n);

   int num;

};


struct Array : Value {
   Array();
   Array(char* c): val(c);

};


struct Object : String : Value {
   Object();
   Object(char* c) : val(c);

};


