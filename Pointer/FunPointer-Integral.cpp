//函数指针求定积分
#include<iostream>
using namespace std;


float F2(float x);
float F1(float x);
float Integral(float  (*f)(float),float a,float b);
int main()
{
    float a,b;
    float y1,y2;
    y1=Integral(F1,0.0,2.0);
    y2=Integral(F2,0.0,233333.0);
    cout<<y1<<endl;
    cout<<y2<<endl;

    return 0;
}

float Integral(float  (*f)(float),float a,float b)
{
    float s, h;
    int n =100 ,i;
    s=((*f)(a)+(*f)(b))/2;
    h=(b-a)/n;
    for ( i = 1; i < n; i++)
    {
        s=s+(*f)(a+i*h);

    }
    return s*h;
    
}

float F1(float x)
{
    return 1+x*x;
}

float F2(float x)
{
    return x/(1+x*x);
}
