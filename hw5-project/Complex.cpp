/*NO.25  Cai Ming-Xian  404410054 6/12*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include "BigInt.h"
#include "Complex.h"
#include "Rational.h"
using namespace std;
using namespace LCS_Rational;
using namespace BigIntA;
namespace ComplexNum
{
    Complex::Complex(const Rational &rNum,const Rational &iNum)
    {
        real=rNum;
        real.normalize();
        imaginary=iNum;
        imaginary.normalize();
    }
    Complex::Complex(const Rational &rNum):imaginary(0)
    {
        real=rNum;
        real.normalize();
        //Only one parameter
    }
    Complex::Complex():real(0),imaginary(0)
    {
        /*No parameter*/
    }
    const Complex operator +(const Complex &augend,const Complex &addend)
    {
        Rational newR,newI;
        newR=(augend.real+addend.real);
        newI=(augend.imaginary+addend.imaginary);
        newR.normalize();
        newI.normalize();
        return Complex(newR,newI);
    }
    const Complex operator -(const Complex &minuend,const Complex &subtrahend)
    {
        Rational newR,newI;
        newR=(minuend.real-subtrahend.real);
        newI=(minuend.imaginary-subtrahend.imaginary);
        newR.normalize();
        newI.normalize();
        return Complex(newR,newI);
    }
    const Complex operator /(const Complex &divisor,const Complex &dividend)
    {
        Rational newR,newI;
        newR=((divisor.real*dividend.real)+(divisor.imaginary*dividend.imaginary))/((dividend.real*dividend.real)+(dividend.imaginary*dividend.imaginary));
        newI=(divisor.imaginary*dividend.real-divisor.real*dividend.imaginary)/(dividend.real*dividend.real+dividend.imaginary*dividend.imaginary);
        newR.normalize();
        newI.normalize();
        return Complex(newR,newI);
    }
    const Complex operator *(const Complex &multiplicand,const Complex &multiplier)
    {
        Rational newR,newI;
        newR=(multiplicand.real*multiplier.real)-(multiplicand.imaginary*multiplier.imaginary);
        newI=(multiplicand.real*multiplier.imaginary)+(multiplier.real*multiplicand.imaginary);
        newR.normalize();
        newI.normalize();
        return Complex(newR,newI);
    }
    istream& operator >>(istream& inputStream,Complex &theObject)
    {
        char *input;
        input=new char[1024];
        char *ptr;
        cin>>input;
        ptr=input+1;
        if(strstr(ptr,"-")==NULL&&strstr(ptr,"+")==NULL)//If no + -,tell the user is invlaid
        {
            cout<<"Invalid input"<<endl;
            exit(1);
        }
        theObject.real=theObject.realPart(input);
        theObject.imaginary=theObject.imaginaryPart(input);
        theObject.real.normalize();
        theObject.imaginary.normalize();
        return inputStream;
    }
    Rational Complex ::realPart(char *complexStr) const
    {
        if(complexStr[strlen(complexStr)-1]=='i')
        {
            int i;
            char *firstNum,*secondNum;//firstNum is used to store the numerator of Rational.secondNum is used to store the dineminator of Rational
            firstNum=new char [1024];
            for(i=0;complexStr[i]!='/';i++)
            {
                firstNum[i]=complexStr[i];
            }
            firstNum[i]='\0';
            char *ptr=complexStr+i+1;
            secondNum=new char[1024];
            for(i=0;(ptr[i]!='+'||i==0)&&(ptr[i]!='-'||i==0);i++)
            {
                secondNum[i]=ptr[i];
            }
            secondNum[i]='\0';
            BigInt a,b;
            if(strstr(firstNum,"!")!=NULL)
            {
                firstNum[strlen(firstNum)-1]='\0';
                a=BigInt(firstNum);
                a=a.factor();
            }
            else
            {
                a=BigInt(firstNum);
            }
            if(strstr(secondNum,"!")!=NULL)
            {
                secondNum[strlen(secondNum)-1]='\0';
                b=BigInt(secondNum);
                b=b.factor();
            }
            else
            {
                b=BigInt(secondNum);
            }
            delete []firstNum;
            delete []secondNum;
            return Rational(a,b);
        }
        else
        {
            int i;
            char *firstNum,*secondNum,*ptr;
            ptr=strstr(complexStr,"i");
            ptr=ptr+1;
            if((*ptr)=='+')
                ptr++;
            firstNum=new char[1024];
            for(i=0;ptr[i]!='/';i++)
            {
                firstNum[i]=ptr[i];
            }
            firstNum[i]='\0';
            ptr=ptr+1+i;
            secondNum=new char[1024];
            for(i=0;ptr[i]!='\0';i++)
            {
                secondNum[i]=ptr[i];
            }
            secondNum[i]='\0';
            BigInt a,b;
            if(strstr(firstNum,"!")!=NULL)
            {
                firstNum[strlen(firstNum)-1]='\0';
                a=BigInt(firstNum);
                a=a.factor();
            }
            else
            {
                a=BigInt(firstNum);
            }
            if(strstr(secondNum,"!")!=NULL)
            {
                secondNum[strlen(secondNum)-1]='\0';
                b=BigInt(secondNum);
                b=b.factor();
            }
            else
            {
                b=BigInt(secondNum);
            }
            delete []firstNum;
            delete []secondNum;
            return Rational(a,b);
        }
    }
    Rational Complex:: imaginaryPart(char *complexStr) const
    {
        if(complexStr[strlen(complexStr)-1]!='i')
        {
            char *firstNum,*secondNum;
            firstNum=new char[1024];
            int i;
            for(i=0;complexStr[i]!='/';i++)
            {
                firstNum[i]=complexStr[i];
            }
            firstNum[i]='\0';
            char *ptr=complexStr+i+1;
            secondNum=new char[1024];
            for(i=0;(ptr[i]!='+'||i==0)&&(ptr[i]!='-'||i==0)&&ptr[i]!='i';i++)
            {
                secondNum[i]=ptr[i];
            }
            secondNum[i]='\0';
           BigInt a,b;
            if(strstr(firstNum,"!")!=NULL)
            {
                firstNum[strlen(firstNum)-1]='\0';
                a=BigInt(firstNum);
                a=a.factor();
            }
            else
            {
                a=BigInt(firstNum);
            }
            if(strstr(secondNum,"!")!=NULL)
            {
                secondNum[strlen(secondNum)-1]='\0';
                b=BigInt(secondNum);
                b=b.factor();
            }
            else
            {
                b=BigInt(secondNum);
            }
            delete []secondNum;
            delete []firstNum;
            return Rational(a,b);
        }
        else
        {
            char *firstNum,*secondNum;
            int i;
            char *ptr=complexStr,*qtr;
            if(complexStr[0]=='-'||complexStr[0]=='+')
                ptr++;
            if((qtr=strstr(ptr,"+"))!=NULL)
            {
                ptr=qtr+1;
            }
            else if((qtr=strstr(ptr,"-"))!=NULL)
            {
                ptr=qtr;
            }
            firstNum=new char[1024];
            for(i=0;ptr[i]!='/';i++)
            {
                firstNum[i]=ptr[i];
            }
            firstNum[i]='\0';
            ptr=ptr+i+1;
            secondNum=new char[1024];
            for(i=0;ptr[i]!='i';i++)
            {
                secondNum[i]=ptr[i];
            }
            secondNum[i]='\0';
           BigInt a,b;
            if(strstr(firstNum,"!")!=NULL)
            {
                firstNum[strlen(firstNum)-1]='\0';
                a=BigInt(firstNum);
                a=a.factor();
            }
            else
            {
                a=BigInt(firstNum);
            }
            if(strstr(secondNum,"!")!=NULL)
            {
                secondNum[strlen(secondNum)-1]='\0';
                b=BigInt(secondNum);
                b=b.factor();
            }
            else
            {
                b=BigInt(secondNum);
            }
            delete []firstNum;
            delete []secondNum;
            return Rational(a,b);
        }
    }
    ostream& operator <<(ostream &outputStream,Complex &theObject)
    {
        if(theObject.imaginary<Rational(BigInt(0),BigInt(1)))
        {
            outputStream<<theObject.real<<theObject.imaginary<<"i";//Because '-' has exits in BigInt
        }
        else
        {
            outputStream<<theObject.real<<"+"<<theObject.imaginary<<"i";
        }
        return outputStream;
    }
}
