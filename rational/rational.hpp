#pragma once
/*
  In mathematics, a rational number is any number that can be expressed as the quotient 
  or fraction p/q of two integers, a numerator p and a non-zero denominator q. Since q may
  be equal to 1, every integer is a rational number. ... A real number that is not rational
  is called irrational.




  Implement a rational number class. The class must:

    Only allow the creation of valid rational numbers
    Support equality (==, !=)
    Support ordering (<, >, <=, >=)
    Support basic arithmetic operators (+, - , * /)
    Support input and output using istream (>>) and ostream (<<)

  The input and output format form rational numbers should be of the form "n / d".
 
*/

class Rational {
public :
   Rational() {}
   void setNumber();
   void printNumber();


private :
   int p;
   int q;
};
