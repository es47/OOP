/**/
#include <iostream>

using namespace std;

class BigInt
{
public:
    BigInt();
    BigInt();
    int getnumber() const;
    BigInt& operator = (const BigInt& rightnumber);
    friend ostream& operator << (ostream& outputStream, const BigInt& number);
    ~BigInt();
private:
    int *number;
};

int main()
{

    return 0;
}

ostream& operator << (ostream& outputStream, const BigInt& number)
{
    int numeration = number.numerator;
    int denominator = number.denominator;
    outputStream << numeration << "/" << denominator;
    return outputStream;
}

const BigInt operator + (const BigInt& number1, const BigInt& number2)
{
    int plus_numerator = number1.getNumerator() * number2.getDenominator() +
                         number1.getDenominator() * number2.getNumerator();
    int plus_denominator = number1.getDenominator() * number2.getDenominator();
    return Rational(plus_numerator, plus_denominator);
}

const BigInt operator - (const BigInt& number1, const BigInt& number2)
{
    int plus_numerator = number1.getNumerator() * number2.getDenominator() -
                         number1.getDenominator() * number2.getNumerator();
    int plus_denominator = number1.getDenominator() * number2.getDenominator();
    return Rational(plus_numerator, plus_denominator);
}

BigInt :: ~BigInt()
{
    delete [] number;
}
