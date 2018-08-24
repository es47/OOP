/*NO.25  Cai Ming-Xian  404410054 6/12*/
#include "Rational.h"
#include "BigInt.h"
#include <stdlib.h>
#include <iostream>
#ifndef COMPLEX
#define COMPLEX

using namespace std;
using namespace LCS_Rational;

namespace ComplexNum
{
    class Complex
    {
    public:
        Complex(const Rational& rNum,const Rational& iNum);
        //Precondiction:rNum and iNum are Rational number
        //Postcondiction:Default a Complex variable with 2 Rational variable
        Complex(const Rational& rNum);
        //Precondiction:Only one Rational variable rNum
        //Postcondiction:Default the real of Complex variable with rNum,and default imaginary with 0
        Complex();
        //Precondiction:No Rational variable is used
        //Postcondiction:Defualt with 0 and 0
        friend istream& operator >>(istream &inputStream,Complex &theObject);
        //Precondiction:Input a string
        //Postcondiction: Return inputStream
        //Postcondiction:Seperate string into a Complex variable
        friend ostream& operator <<(ostream &outputStream,Complex &theObject);
        //Precondiction:outputStream should be the left of theObject
        //Postcondiction:Output the Complex variable
        friend const Complex operator +(const Complex &augend,const Complex &addend);
        //Precondiction:2 Complex variable should be used
        //Postcondiction:Return the sum of 2 Complex variable
        friend const Complex operator -(const Complex &minuend,const Complex &subtrahend);
        //Precondiction:2 Complex variable should be used
        //Postcondiction:Return the difference of 2 Complex variable
        friend const Complex operator *(const Complex &multiplicand,const Complex &multiplier);
        //Precondiction:2 Complex variable should be used
        //Postcondiction:Return the product of 2 Complex variable
        friend const Complex operator /(const Complex &divisor,const Complex &dividend);
        //Precondiction:2 Complex variable should be used
        //Postcondiction:Return the quotient of 2 Complex variable
    private:
        Rational real;
        Rational imaginary;
        Rational realPart(char *complexStr) const;
        //Precondiction:The sting is in complex form
        //Precondiction:Return the Rational varable which is the part of real
        Rational imaginaryPart(char *complexStr) const;
        //Precondiction:The sting is in complex form
        //Precondiction:Return the Rational varable which is the part of imaginary
    };
}


#endif // Complex
