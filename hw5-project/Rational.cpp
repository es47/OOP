/*No.25, 林佳萱, 404410062, 資工二*/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Rational.h"

using namespace std;

namespace LCS_Rational
{

ostream& operator << (ostream& outputStream, const Rational& number)
{
    BigInt numeration = number.numerator;
    BigInt denominator = number.denominator;
    cout << number.numerator << "/" << number.denominator;
    return outputStream;
}

istream& operator >> (istream& inputStream, Rational& number)
{
    char numberAsInt[200];
    inputStream >> numberAsInt;
    number.numerator = number.numeratorPart(numberAsInt);
    number.denominator = number.denominatorPart(numberAsInt);
    return inputStream;
}

BigInt Rational :: numeratorPart (const char number[]) const
{
    BigInt value;
    int i, len_num, flag(0);
    char *ptr, number2[100];
    len_num = strlen(number);
    for (i = 0; i < len_num; i++)
        number2[i] = number[i];
    ptr = strtok(number2, "/");                     //find where '/' is, and cut before '/'
    i = strlen(ptr) - 1;
    if (ptr[i] == '!')                              //if there is a '!', mark it
        flag = 1;
    if (flag == 1)                                  //if there is a mark, send value to factor()
    {
        ptr[i] = '\0';
        value = ptr;
        value = value.factor();
    }
    else                                            //if there isn't a mark, value equals to ptr
        value = ptr;
    return value;
}

BigInt Rational :: denominatorPart (const char number[]) const
{
    BigInt value;
    int i, len_num, len_ptr, j, flag(0);
    char *ptr, number2[100];
    len_num = strlen(number);
    for (i = 0; i < len_num; i++)
        number2[i] = number[i];
    ptr = strtok(number2, "/");                     //find where '/' is, and cut before '/'
    ptr = strtok(NULL, "/");                        //cut before '/'
    len_ptr = strlen(ptr);
    for(i = 0; i < len_ptr; i++)                    //if there are not number and not '!', then set it as '\0'
        if(ptr[i] < '0' && ptr[i] > '9')
            if(ptr[i] != '!')
                ptr[i] = '\0';
    len_ptr = strlen(ptr);
    i = len_ptr - 1;
   if (ptr[i] == '!')                               //if there is a '!', mark it
        flag = 1;
    if (flag == 1)                                  //if there is a mark, send value to factor()
    {
        ptr[i] = '\0';
        value = ptr;
        value = value.factor();
    }
    else                                            //if there isn't a mark, value equals to ptr
        value = ptr;
    if (value == 0)                                 //if value equals to 0, set it be 1
        value = 1;
    return value;
}

Rational :: Rational(BigInt numeratorValue, BigInt denominatorValue)
    : numerator(numeratorValue), denominator(denominatorValue)
{
    /*Body intentionally empty.*/
}

Rational :: Rational(BigInt numeratorValue) : numerator(numeratorValue), denominator(1)
{
    /*Body intentionally empty.*/
}

Rational :: Rational() : numerator(0), denominator(1)
{
    /*Body intentionally empty.*/
}

void Rational :: normalize()
{
    BigInt copyNumerator, copyDenominator, temp;
    copyNumerator = numerator;
    copyDenominator = denominator;
    while(1)                                            //find the Maximum common factor, use Removed by division
    {
        temp = copyNumerator / copyDenominator;
        temp = temp * copyDenominator;
        temp = copyNumerator - temp;
        copyNumerator = copyDenominator;
        copyDenominator = temp;
        if (temp == 0) break;
    }
    numerator = numerator / copyNumerator;
    denominator = denominator / copyNumerator;
    if (denominator <= -1)                              //if denominator is negative, let numerator and denominator change sign
    {
        numerator = 0 - numerator;
        denominator = 0 - denominator;
    }
}

BigInt Rational :: getNumerator() const
{
    return numerator;
}

BigInt Rational :: getDenominator() const
{
    return denominator;
}

bool Rational :: operator < (const Rational& number2) const
{
    bool flag;
    flag = (numerator * number2.denominator) == (number2.numerator * denominator);
    if (flag == true)
        return false;
    else
    {
        flag = (numerator * number2.denominator) <= (denominator * number2.numerator);
        return flag;
    }
}

bool Rational :: operator <= (const Rational& number2) const
{
    return ((numerator * number2.denominator) <= (denominator * number2.numerator));
}

bool Rational :: operator > (const Rational& number2) const
{
    bool flag;
    flag = (numerator * number2.denominator) <= (denominator * number2.numerator);
    if (flag == true)
        return false;
    else
        return true;
}

bool Rational :: operator >= (const Rational& number2) const
{
    bool flag;
    flag = (numerator * number2.denominator) == (number2.numerator * denominator);
    if (flag == false)
        return false;
    else
    {
        flag = (numerator * number2.denominator) <= (denominator * number2.numerator);
        if (flag == true)
            return false;
        else
            return true;
    }
}

const Rational operator + (const Rational& number1, const Rational& number2)
{
    BigInt plus_numerator = number1.getNumerator() * number2.getDenominator() +
                            number1.getDenominator() * number2.getNumerator();
    BigInt plus_denominator = number1.getDenominator() * number2.getDenominator();
    return Rational(plus_numerator, plus_denominator);
}

const Rational operator - (const Rational& number1, const Rational& number2)
{
    BigInt negative_numerator = number1.getNumerator() * number2.getDenominator() -
                                number1.getDenominator() * number2.getNumerator();
    BigInt negative_denominator = number1.getDenominator() * number2.getDenominator();
    return Rational(negative_numerator, negative_denominator);
}

const Rational operator - (const Rational& number)
{
    BigInt negative_numerator = 0 - number.getNumerator();
    BigInt negative_denominator = number.getDenominator();
    return Rational(negative_numerator, negative_denominator);
}

const Rational operator * (const Rational& number1, const Rational& number2)
{
    BigInt product_numerator = number1.numerator * number2.numerator;
    BigInt product_denominator = number1.denominator * number2.denominator;
    return Rational(product_numerator, product_denominator);
}

const Rational operator / (const Rational& number1, const Rational& number2)
{
    BigInt division_numerator = number1.numerator * number2.denominator;
    BigInt division_denominator = number1.denominator * number2.numerator;
    return Rational(division_numerator, division_denominator);
}

bool operator == (const Rational& number1, const Rational& number2)
{
    return ((number1.numerator * number2.denominator) == (number2.numerator * number1.denominator));
}

}
