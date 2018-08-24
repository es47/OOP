/*No.25, 林佳萱, 404410062, 資工二*/
#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "BigInt.h"

using namespace std;
using namespace BigIntA;

namespace LCS_Rational
{

class Rational : public BigInt
{
public:
    Rational(BigInt numeratorValue, BigInt denominatorValue);
    //Postcondition : default constructor with two BigInt

    Rational(BigInt numeratorValue);
    //Postcondition : default constructor with one BigInt

    Rational();
    //Postcondition : default constructor with no number

    void normalize();
    //Postcondition : normalize the rational

    BigInt getNumerator() const;
    //Postcondition : get the numerator number

    BigInt getDenominator() const;
    //Postcondition : get the denominator number

    bool operator < (const Rational& number2) const;
    bool operator <= (const Rational& number2) const;
    bool operator > (const Rational& number2) const;
    bool operator >= (const Rational& number2) const;
    friend const Rational operator + (const Rational& number1, const Rational& number2);
    friend const Rational operator - (const Rational& number1, const Rational& number2);
    friend const Rational operator - (const Rational& number);
    friend const Rational operator * (const Rational& number1, const Rational& number2);
    friend const Rational operator / (const Rational& number1, const Rational& number2);
    friend bool operator == (const Rational& number1, const Rational& number2);
    friend ostream& operator << (ostream& outputStream, const Rational& number);
    friend istream& operator >> (istream& inputStream, Rational& number);
private:
    BigInt numerator;
    BigInt denominator;
    BigInt numeratorPart (const char number[]) const;
    //Postcondition : get the numerator part

    BigInt denominatorPart (const char number[]) const;
    //Postcondition : get the denominator part
};

}

#endif
