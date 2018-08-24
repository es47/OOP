#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Rational.h"
#include "Complex.h"
#include "BigInt.h"
using namespace std;
using namespace BigIntA;
using namespace LCS_Rational;
using namespace ComplexNum;
int main()
//Precondiction:Enter two complex number separately
//Precondiction:The form of input is a/b+c/di
//Precondiction :First enter the one complex c1,then enter second complex number c2
//Postcondiction:Output the complex number from c1/c2
{
    cout<<"If you want to input factorial num"<<endl;
    cout<<"Must add '!' at the end of number!!"<<endl<<endl;
    Complex c2,c1,ans;
    char cont;
    while(1)
    {
        cout<<"Input c1"<<endl<<"c1:";
        cin>>c1;
        cout<<"Input c2"<<endl<<"c2:";
        cin>>c2;
        ans=c1+c2;
        cout<<"c1+c2="<<ans<<endl<<endl;
        ans=c1-c2;
        cout<<"c1-c2="<<ans<<endl<<endl;
        ans=c1*c2;
        cout<<"c1*c2="<<ans<<endl<<endl;
        cout<<"Solve the c1/c2"<<endl;
        ans=c1/c2;
        cout<<endl<<"Answer:";
        cout<<ans<<endl<<endl;
        cout<<"Continue?(y/n)"<<endl;
        cin>>cont;
        if(cont!='y')
            break;
    }
    return 0;
}
