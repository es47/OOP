#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include "BigInt.h"
using namespace std;

namespace BigIntA{


BigInt& BigInt::operator =(const BigInt &a)//for assign value
{

    delete [] arr;

    arr = new int [a.bits+1];
    bits = a.bits;
    prefix = a.prefix;
    for(int i=0; i<a.bits; i++)//copy
    {
        arr[i] = a.arr[i];
    }
    return *this;
}


BigInt::~BigInt()//free the memory
{
    delete [] arr;
}



BigInt::BigInt()//origin 0
{
    bits = 1;
    arr = new int [bits+2];
    arr[0] = 0;
    prefix = 0;
}



BigInt::BigInt(const char *a)//for array type
{
    int check;
    if(a[0]<0)check=0;
    else check=1;

    if(a[0] == '-')
    {
        prefix = 1;
    }
    else if(a[0] == '+' || (a[0]>='0' && a[0]<='9'))//decide the prefix
        prefix = 0;

    int temp(-1);

    int lenth = strlen(a);
    if(check==0)
    {
        for(int i=0; i<lenth ; i++)
        {
            if(a[i]=='+' || a[i]=='-' || a[i]=='0')
            {
                continue;
            }
            else
            {
                temp = i;
                break;
            }
        }
    }
    else if(check==1)
    {
        for(int i=0; i<lenth ; i++)
        {
            if(a[i]=='+' || a[i]=='-' || a[i]=='0')
            {
                continue;
            }
            else
            {
                temp = i;
                break;
            }
        }
    }
    for(int i=0; i<lenth ; i++)
    {
        if(a[i]=='+' || a[i]=='-' || a[i]=='0')
        {
            continue;
        }
        else
        {
            temp = i;
            break;
        }
    }

    if(temp == -1)temp = lenth -1;


    arr = new int [lenth *2+10];

    bits = lenth -temp;

    int cnt(0);

    for(int i=temp; i<lenth ; i++)
    {

        arr[cnt++] = a[i]-'0';
    }

}

BigInt::BigInt(int a)//for the integer type
{

    int temp=0;
    int cnt=0;
    if(a<0)
    {
        prefix = 1;
        temp=0;
    }
    else
    {
        prefix = 0;
        temp=1;
    }

    if(cnt==0)  a = abs(a);


    int lenth(0);

    if(a>0)
        lenth = log10(a)+1;//hoe many bits
    else
        lenth = 1;

    bits = lenth;

    arr = new int [lenth*2+10];
    if(temp==0)
    {
        for(int i=0; i<lenth; i++)
        {
            arr[i] = a%10;
            a/=10;
        }
    }
    else if(temp==1)
    {
        for(int i=0; i<lenth; i++)
        {
            arr[i] = a%10;
            a/=10;
        }
    }



    reverse(arr,arr+bits);
}



BigInt::BigInt(const BigInt &a)
{
    int len = a.bits;
    arr = new int [len*2+10];

    for(int i=0; i<len; i++)
    {
        arr[i] = a.arr[i];
    }
    prefix = a.prefix;
    bits = len;

}


ostream& operator <<(ostream& output, const BigInt &a)//for the output
{
    if(a.prefix == 1)
    {
        output << "-";
    }
    for(int i=0; i<a.bits; i++)
    {
        output << a.arr[i];
    }
    return output;
}




int checkprefix(const BigInt &a, const BigInt &b)//check the sign
{
    if(a.prefix == 0 && b.prefix == 0)
        return 0;
    if(a.prefix == 0 && b.prefix == 1)
        return 1;
    if(a.prefix == 1 && b.prefix == 0)
        return 2;
    if(a.prefix == 1 && b.prefix == 1)
        return 3;

}
BigInt operator +(BigInt a, BigInt b)//addition
{
    int sum_len(1);
    int len = max(a.bits,b.bits);
    int str1[len];
    int str2[len];
    int tmp1(0);
    int tmp2(0);

    if(a.bits < b.bits)//if b>a will be negative ,swap before add
    {
        swap(a,b);
    }
    else if(a.bits == b.bits)
    {
        for(int i=0; i<a.bits; i++)
        {
            if(a.arr[i] > b.arr[i])break;

            if(a.arr[i] < b.arr[i])
            {
                swap(a,b);
                break;
            }

        }

    }



    reverse(a.arr,a.arr+a.bits);
    reverse(b.arr,b.arr+b.bits);



    memset(str1,0,sizeof(str1));
    memset(str2,0,sizeof(str2));

    if(tmp2==0)//copy the array
    {
        for(int i=0; i<a.bits; i++)
        {
            str1[i] = a.arr[i];
        }

        for(int i=0; i<b.bits; i++)
        {
            str2[i] = b.arr[i];
        }

    }


    int tmp(0);


    int sign(0);
    if(tmp1==0)
    {
        if(a.prefix == b.prefix && a.prefix == 1)
        {
            tmp = 1;
            sign = 0;
        }
        else if(a.prefix == b.prefix && a.prefix == 0)
        {
            tmp = 0;
            sign = 0;
        }
        else
        {
            tmp = a.prefix;
            sign = 1;
        }
    }
    else
    {
        if(a.prefix == b.prefix && a.prefix == 1)
        {
            tmp = 1;
            sign = 0;
        }
        else if(a.prefix == b.prefix && a.prefix == 0)
        {
            tmp = 0;
            sign = 0;
        }
        else
        {
            tmp = a.prefix;
            sign = 1;
        }
    }



    int sum[len+3];

    memset(sum,0,sizeof(sum));



    for(int i=0; i<len; i++)//add by bits
    {
        if(sign == 0)
        {
            sum[i] = sum[i] + str1[i] + str2[i];
            sum[i+1] = sum[i]/10;
            sum[i]%=10;
        }
        else if(sign == 1)
        {
            sum[i] = sum[i] + str1[i] - str2[i];
            if(sum[i] < 0)
            {
                sum[i+1]--;
                sum[i]+=10;
            }
        }
    }


    for(int i=0; i<len+3; i++)
    {

        if(sum[i]!=0)
        {
            sum_len = i+1;
        }

    }


    reverse(sum,sum+sum_len);


    char fin[sum_len+4];

    memset(fin,'\0',sizeof(fin));

    if(tmp == 1)
    {
        fin[0] = '-';
    }
    else
    {
        fin[0] = '+';
    }

    for(int i=1; i<sum_len+1; i++)
    {
        fin[i] = '0' + sum[i-1];
    }


    return BigInt(fin);

}



BigInt operator -(BigInt a, BigInt b)//minus
{

    int sum_len(1);
    int len = max(a.bits,b.bits);
    int str1[len];
    int str2[len];
    int tmp1(0);

    if(b.prefix==1)b.prefix=0;//change the prefix and use addition
    else if(b.prefix==0)b.prefix=1;
    if(a.bits < b.bits)
    {
        swap(a,b);
    }
    else if(a.bits == b.bits)
    {
        for(int i=0; i<a.bits; i++)
        {
            if(a.arr[i] > b.arr[i])break;

            if(a.arr[i] < b.arr[i])
            {
                swap(a,b);
                break;
            }

        }

    }



    reverse(a.arr,a.arr+a.bits);
    reverse(b.arr,b.arr+b.bits);



    memset(str1,0,sizeof(str1));
    memset(str2,0,sizeof(str2));


    for(int i=0; i<a.bits; i++)
    {
        str1[i] = a.arr[i];
    }

    for(int i=0; i<b.bits; i++)
    {
        str2[i] = b.arr[i];
    }




    int tmp(0);


    int sign(0);
    if(tmp1==0)
    {
        if(a.prefix == b.prefix && a.prefix == 1)
        {
            tmp = 1;
            sign = 0;
        }
        else if(a.prefix == b.prefix && a.prefix == 0)
        {
            tmp = 0;
            sign = 0;
        }
        else
        {
            tmp = a.prefix;
            sign = 1;
        }
    }
    else
    {
        if(a.prefix == b.prefix && a.prefix == 1)
        {
            tmp = 1;
            sign = 0;
        }
        else if(a.prefix == b.prefix && a.prefix == 0)
        {
            tmp = 0;
            sign = 0;
        }
        else
        {
            tmp = a.prefix;
            sign = 1;
        }
    }



    int sum[len+3];

    memset(sum,0,sizeof(sum));



    for(int i=0; i<len; i++)
    {
        if(sign == 0)
        {
            sum[i] = sum[i] + str1[i] + str2[i];
            sum[i+1] = sum[i]/10;
            sum[i]%=10;
        }
        else if(sign == 1)
        {
            sum[i] = sum[i] + str1[i] - str2[i];
            if(sum[i] < 0)
            {
                sum[i+1]--;
                sum[i]+=10;
            }
        }
    }


    for(int i=0; i<len+3; i++)
    {

        if(sum[i]!=0)
        {
            sum_len = i+1;
        }

    }


    reverse(sum,sum+sum_len);


    char fin[sum_len+4];

    memset(fin,'\0',sizeof(fin));

    if(tmp == 1)
    {
        fin[0] = '-';
    }
    else
    {
        fin[0] = '+';
    }

    for(int i=1; i<sum_len+1; i++)
    {
        fin[i] = '0' + sum[i-1];
    }


    return BigInt(fin);


}

BigInt operator *(BigInt a, BigInt b)
{

    int len = a.bits + b.bits;

    int check=0;
    int tmp(0);
    int total[len+3];

    BigInt zero(0);
    if(a==zero||b==zero)return zero;
    memset(total,0,sizeof(total));

    reverse(a.arr,a.arr+a.bits);
    reverse(b.arr,b.arr+b.bits);



    for(int i=0; i<a.bits; i++)
    {
        for(int j=0; j<b.bits; j++)
        {
            total[i+j] += a.arr[i]*b.arr[j];
        }
    }

    if(check==0)
    {
           for(int i=0; i<len+1; i++)
    {
        total[i+1]+=total[i]/10;
        total[i]%=10;
    }
    }




    for(int i=0; i<len+1; i++)
    {
        if(total[i]!=0)
            tmp = i+1;
    }

    if(tmp == -1)
        tmp = len-1;

    reverse(total,total+tmp);



    int prefix = a.prefix^b.prefix;

    char Total[len+4];

    memset(Total,'\0',sizeof(Total));

    if(prefix)
        Total[0] = '-';
    else
        Total[0] = '+';

    for(int i=0; i<tmp; i++)
    {
        Total[i+1] = '0' + total[i];
    }

    return BigInt(Total);

}


BigInt operator /(BigInt a, BigInt b)
{

    int check=0;
    BigInt temp(0);
    BigInt result(0);
    BigInt temp1=1000000;
    int flag = a.prefix^b.prefix;//decide the prefix
    result.prefix = flag;
    int count=-1;
    if(b==temp)
    {
        cout<<"b can not be 0"<<endl;
        exit(1);
    }
    a.prefix = 0;
    b.prefix = 0;
    if(a==b)
    {
        result=1;
        result.prefix = flag;
        return result;
    }
    if(a<=b)
    {
        result=0;
        return result;
    }

    if(a<=temp1)//if it is small we use minus
    {
        while(a.prefix==0)
        {
            a=a-b;
            count++;
        }
         result=count;
         result.prefix = flag;
        return result;
    }
    if(check==0)//if the number is big we use minus by mult 10
    {
        for(int i=0; i<a.bits; i++)
        {
            int cnt(0);
            temp = temp*10;
            temp = temp + a.arr[i];
            while(b*(cnt+1) <= temp) cnt++;
            temp = temp - b*cnt;
            result = result*10;
            result = result+cnt;
        }
    }
    else if(check==1)
    {
        for(int i=0; i<a.bits; i++)
        {
            int cnt(0);
            temp = temp*10;
            temp = temp + a.arr[i];
            while(b*(cnt+1) <= temp) cnt++;
            temp = temp - b*cnt;
            result = result*10;
            result = result+cnt;
        }
    }


    result.prefix = flag;

    if(result == 0)result.prefix = 0;
     if(result.prefix == 0)result=result+1;
    else result=result-1;
    if(b*result==a)
    {

    }
    else
    {
         if(result.prefix == 0)result=result-1;
         else result=result+1;
    }
    return result;
}
BigInt BigInt::factor()//factorial
{

    BigInt result(1);
    BigInt i(1);
    BigInt c(1);
    BigInt d(*this);
    int sign;
    int cnt=0;
    if(d.prefix==0)sign=0;
    else if(d.prefix==1)
    {
        d.prefix=0;
        sign=1;
    }
    while(1)
    {
        i.prefix=0;

        if(i<=d)
        {
            cnt++;
        }
        else break;

        result = result*i;//factorial

        i = i+c;

    }
    result = result*i;
    if(sign==1)result.prefix=1;
    else if(sign==0)result.prefix=0;
    return result;

}


bool operator ==(const BigInt& a, const BigInt& b)
{
    int temp=0;
    if(a.arr[0] == 0 && b.arr[0] == 0)//0
        return true;


    if(a.bits > b.bits)
    {
        temp=1;
        return false;
    }
    else if(a.bits < b.bits)
    {
        temp=1;
        return false;
    }
    for(int i=0; i<a.bits; i++)
    {
        if(a.arr[i] > b.arr[i])
            temp=1;
        if(a.arr[i] < b.arr[i])
            temp=1;
    }

   // if(a.prefix == b.prefix)temp=1;


    if(temp==0)
    {
        if((checkprefix(a,b) == 0 || checkprefix(a,b) == 3))
            return true;
    }

    return false;

}

bool operator <=(const BigInt& a, const BigInt& b)
{
    if(checkprefix(a,b)==1)
    {

        if(a.arr[0] == 0 && b.arr[0] == 0)
            return true;
        else
            return false;

    }
    else if(checkprefix(a,b)==0)
    {

        int temp;

        if(a.bits > b.bits)
        {
            return false;
        }
        else if(a.bits < b.bits)
        {
            return true;
        }
        for(int i=0; i<a.bits; i++)
        {
            if(a.arr[i] > b.arr[i])
                return false;
            if(a.arr[i] < b.arr[i])
                return true;
        }

        if(a.prefix == b.prefix)return false;
        return true;

    }

    else if(checkprefix(a,b)==2)
    {

        if(a.arr[0] == 0 && b.arr[0] == 0)
            return true;
        else
            return true;


    }
    else if(checkprefix(a,b)==3)
    {

        if(a.bits > b.bits)
        {
            return true;
        }
        else if(a.bits < b.bits)
        {
            return false;
        }
        for(int i=0; i<a.bits; i++)
        {
            if(a.arr[i] > b.arr[i])
                return true;
            if(a.arr[i] < b.arr[i])
                return false;
        }

        if(a.prefix == b.prefix)
            return false;
        return true;
    }



}

}
