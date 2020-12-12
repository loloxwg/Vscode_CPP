#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int a =0;
    int* pa=&a;
    *pa=1;
    cout<<pa<<endl;
    cout<<&a<<endl;
    cout<<a<<endl;
    cout<<*pa<<endl;
}