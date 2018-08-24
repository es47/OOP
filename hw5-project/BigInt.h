#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#ifndef BIGINT
#define BIGINT
namespace BigIntA {



class BigInt
{
public:

    BigInt(const BigInt &a);
    BigInt(const char *a);
    BigInt(const int a);
    BigInt();
    ~BigInt();
    BigInt factor();
    friend int checkprefix(const BigInt &a, const BigInt &b);
    //Postcondition :to get the result sign


    friend bool operator <=(const BigInt& a, const BigInt& b);
    friend bool operator ==(const BigInt& a, const BigInt& b);

    BigInt& operator =(const BigInt &a);
    friend BigInt operator +(BigInt a, BigInt b);
    friend BigInt operator -(BigInt a, BigInt b);
    friend BigInt operator *(BigInt a, BigInt b);
    friend BigInt operator /(BigInt a, BigInt b);
    //Postcondition :the operator for +,-,*,/,=

    friend ostream& operator <<(ostream& output, const BigInt &a);

private:
    int *arr;  //the array for number
    int bits;   // how many bits the number is
    int prefix; // the first sign bit +/-
};


int checkprefix(const BigInt &a, const BigInt &b);
BigInt operator +(BigInt a, BigInt b);
BigInt operator -(BigInt a, BigInt b);
BigInt operator *(BigInt a, BigInt b);
BigInt operator /(BigInt a, BigInt b);
bool operator ==(const BigInt& a, const BigInt& b);
bool operator <=(const BigInt& a, const BigInt& b);
ostream& operator <<(ostream& output, const BigInt &a);


}
#endif // BigInt
