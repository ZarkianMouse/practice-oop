#pragma once
/*
  In mathematics, a rational number is any number that can be expressed
  as the quotient or fraction p/q of two integers, a numerator p and a 
  non-zero denominator q.

  Implement a rational number class. The class must:

    Only allow the creation of valid rational numbers
    Support equality (==, !=)
    Support ordering (<, >, <=, >=)
    Support basic arithmetic operators (+, - , * /)
    Support input and output using istream (>>) and ostream (<<)

  The input and output format for rational numbers should be of the form "n / d".
 
*/

class Rational {
public :
   // Constructors
   Rational() {}
   Rational(int n, int d) : p(n), q(d) {}

   // for accessing values in main program
   int getNum() const { return p;}
   int getDenom() const { return q;}

   // assignment
   void operator=(Rational b);
 
   
   // basic comparisons
   friend bool operator==(Rational, Rational);
   friend bool operator>(Rational, Rational);
   friend bool operator<(Rational, Rational);

   
   // input/output
   friend std::istream& operator>>(std::istream&, Rational &);
   friend std::ostream& operator<<(std::ostream&, const Rational &);

private :
   int p; // numerator
   int q; // denominator
};

// other comparisons
bool operator!=(Rational, Rational);
bool operator>=(Rational, Rational);
bool operator<=(Rational, Rational);

// arithmetic operations
Rational operator+(Rational, Rational);
Rational operator-(Rational, Rational);
Rational operator*(Rational, Rational);
Rational operator/(Rational, Rational);

