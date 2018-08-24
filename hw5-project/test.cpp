#include<iostream>
#include "Complex.h"
#include "Rational.h"
#include "BigInt.h"

using namespace BigIntA;
using namespace std;
using namespace LCS_Rational;
using namespace ComplexNum;

int maim()
{
    Complex c1,c2,ans;
    while(1)
    {
    cout<<"Test"<<endl;
    cout<<"Enter c1:";
    cin>>c1;
    cout<<"Enter c2:";
    cin>>c2;
    ans=c1+c2;
    cout<<"c1+c2:"<<ans<<endl;
    ans=c1-c2;
    cout<<"c1-c2:"<<ans<<endl;
    ans=c1*c2;
    cout<<"c1*c2:"<<ans<<endl;
    ans=c1/c2;
    cout<<"c1/c2:"<<ans<<endl;
    }
    return 0;
}
