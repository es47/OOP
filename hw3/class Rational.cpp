/* 404410062 資工二*/
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class Rational
{
public:
    Rational(int numeratorValue, int denominatorValue);
    //Postcondition : transform enter number into Rational type.
    Rational(int numeratorValue);
    //Postcondition : transform enter number into Rational type and default denominator.
    Rational();
    //Postcondition : default numerator and denominator.
    void normalize();
    //Postcondition : to normalize the rational.
    int getNumerator() const;
    int getDenominator() const;
    bool operator < (const Rational& number2) const;
    bool operator <= (const Rational& number2) const;
    bool operator > (const Rational& number2) const;
    bool operator >= (const Rational& number2) const;
    int operator [] (const bool number) const;
    friend const Rational operator * (const Rational& number1, const Rational& number2);
    friend const Rational operator / (const Rational& number1, const Rational& number2);
    friend bool operator == (const Rational& number1, const Rational& number2);
    friend ostream& operator << (ostream& outputStream, const Rational& number);
    friend istream& operator >> (istream& inputStream, Rational& number);
private:
    int numerator;
    int denominator;
    int numeratorPart (const char number[]) const;
    //Postcondition : get the numerator part from input string.
    int denominatorPart (const char number[]) const;
    //Postcondition : get the denominator part from input string.
};

const Rational operator +(const Rational& number1, const Rational& number2);

const Rational operator -(const Rational& number1, const Rational& number2);

const Rational operator -(const Rational& number);

int main()
{
    Rational number1, number2, number3;
    bool result;
    int numerator, denominator;
    char choose;
    while (1)
    {
        cout << "Please enter the first number's numeration and denominator: ";
        cin >> number1;
        number1.normalize();
        cout << "Please enter the second number's numeration and denominator: ";
        cin >> number2;
        number2.normalize();
        number3 = number1 + number2;
        number3.normalize();
        cout << number1 << " + " << number2 << " = " << number3 << endl;
        number3 = number1 - number2;
        number3.normalize();
        cout << number1 << " - " << number2 << " = " << number3 << endl;
        number3 = -number1;
        number3.normalize();
        cout << "-(" << number1 << ") = " << number3 << endl;
        number3 = -number2;
        number3.normalize();
        cout << "-(" << number2 << ") = " << number3 << endl;
        number3 = number1 * number2;
        number3.normalize();
        cout << "(" << number1 << ") * (" << number2 << ") = " << number3 << endl;
        number3 = number1 / number2;
        number3.normalize();
        cout << "(" << number1 << ") / (" << number2 << ") = " << number3 << endl;
        result = (number1 == number2);
        cout << "(" << number1 << ") == (" << number2 << ") ? ";
        if (result == 0)
            cout << "No!\n";
        else
            cout << "Yes!\n";
        result = (number1 < number2);
        cout << "(" << number1 << ") < (" << number2 << ") ? ";
        if (result == 0)
            cout << "No!\n";
        else
            cout << "Yes!\n";
        result = (number1 <= number2);
        cout << "(" << number1 << ") <= (" << number2 << ") ? ";
        if (result == 0)
            cout << "No!\n";
        else
            cout << "Yes!\n";
        result = (number1 > number2);
        cout << "(" << number1 << ") > (" << number2 << ") ? ";
        if (result == 0)
            cout << "No!\n";
        else
            cout << "Yes!\n";
        result = (number1 >= number2);
        cout << "(" << number1 << ") >= (" << number2 << ") ? ";
        if (result == 0)
            cout << "No!\n";
        else
            cout << "Yes!\n";
        numerator = number1[0];
        cout << number1 << " [0] : " << numerator << endl;
        denominator = number1[1];
        cout << number1 << " [1] : " << denominator << endl;
        numerator = number2[0];
        cout << number2 << " [0] : " << numerator << endl;
        denominator = number2[1];
        cout << number2 << " [1] : " << denominator << endl;
        cout << "Are you want to continue?\n";
        cout << "Enter (Y/y) to continue, (N/n) to exit : ";
        cin >> choose;
        if (choose == 'N' || choose == 'n') break;
    }
    return 0;
}

ostream& operator << (ostream& outputStream, const Rational& number)
{
    int numeration = number.numerator;
    int denominator = number.denominator;
    outputStream << numeration << "/" << denominator;
    return outputStream;
}

istream& operator >> (istream& inputStream, Rational& number)
{
    char numberAsInt[100];
    inputStream >> numberAsInt;
    number.numerator = number.numeratorPart(numberAsInt);
    number.denominator = number.denominatorPart(numberAsInt);
    return inputStream;
}

int Rational :: numeratorPart (const char number[]) const
{
    int value, i;
    char *ptr, number2[100];
    for (i = 0; i < strlen(number); i++)
        number2[i] = number[i];
    ptr = strtok(number2, "/");
    value = atoi(ptr);
    return value;
}

int Rational :: denominatorPart (const char number[]) const
{
    int value, i;
    char *ptr, number2[100];
    for (i = 0; i < strlen(number); i++)
        number2[i] = number[i];
    ptr = strtok(number2, "/");
    ptr = strtok(NULL, "/");
    value = atoi(ptr);
    if (value == 0)
        value = 1;
    return value;
}

Rational :: Rational(int numeratorValue, int denominatorValue)
    : numerator(numeratorValue), denominator(denominatorValue)
{
    /*Body intentionally empty.*/
}

Rational :: Rational(int numeratorValue) : numerator(numeratorValue), denominator(1)
{
    /*Body intentionally empty.*/
}

Rational :: Rational() : numerator(0), denominator(1)
{
    /*Body intentionally empty.*/
}

void Rational :: normalize()
{
    int copyNumerator, copyDenominator, temp;
    copyNumerator = numerator;
    copyDenominator = denominator;
    while(copyDenominator != 0)
    {
        temp = copyNumerator % copyDenominator;
        copyNumerator = copyDenominator;
        copyDenominator = temp;
    }
    numerator /= copyNumerator;
    denominator /= copyNumerator;
    if (denominator < 0)
    {
        numerator = -numerator;
        denominator = -denominator;
    }
}

int Rational :: getNumerator() const
{
    return numerator;
}

int Rational :: getDenominator() const
{
    return denominator;
}

bool Rational :: operator < (const Rational& number2) const
{
    return ((numerator * number2.denominator) < (denominator * number2.numerator));
}

bool Rational :: operator <= (const Rational& number2) const
{
    return ((numerator * number2.denominator) <= (denominator * number2.numerator));
}

bool Rational :: operator > (const Rational& number2) const
{
    return ((numerator * number2.denominator) > (denominator * number2.numerator));
}

bool Rational :: operator >= (const Rational& number2) const
{
    return ((numerator * number2.denominator) >= (denominator * number2.numerator));
}

int Rational :: operator [] (const bool number) const
{
    if (number == 0)
        return numerator;
    else
        return denominator;
}

const Rational operator + (const Rational& number1, const Rational& number2)
{
    int plus_numerator = number1.getNumerator() * number2.getDenominator() +
                         number1.getDenominator() * number2.getNumerator();
    int plus_denominator = number1.getDenominator() * number2.getDenominator();
    return Rational(plus_numerator, plus_denominator);
}

const Rational operator - (const Rational& number1, const Rational& number2)
{
    int plus_numerator = number1.getNumerator() * number2.getDenominator() -
                         number1.getDenominator() * number2.getNumerator();
    int plus_denominator = number1.getDenominator() * number2.getDenominator();
    return Rational(plus_numerator, plus_denominator);
}

const Rational operator - (const Rational& number)
{
    int negative_numerator = - number.getNumerator();
    int negative_denominator = number.getDenominator();
    return Rational(negative_numerator, negative_denominator);
}

const Rational operator * (const Rational& number1, const Rational& number2)
{
    int product_numerator = number1.numerator * number2.numerator;
    int product_denominator = number1.denominator * number2.denominator;
    return Rational(product_numerator, product_denominator);
}

const Rational operator / (const Rational& number1, const Rational& number2)
{
    int division_numerator = number1.numerator * number2.denominator;
    int division_denominator = number1.denominator * number2.numerator;
    return Rational(division_numerator, division_denominator);
}

bool operator == (const Rational& number1, const Rational& number2)
{
    return ((number1.numerator * number2.denominator) == (number2.numerator * number1.denominator));
}
