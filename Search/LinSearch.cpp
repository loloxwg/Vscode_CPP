#include<stdio.h>
#include<iostream>
#include "BinSearch.cpp"
#define N 40
using namespace std;
int LinSearch(long num[],long x,int n);
int ReadScore (long num[],int score[]); 

int ReadScore (long num[],int score[])
{
    int i=-1;
    do
    {
        i++;
        cout<<"Input num,score"<<endl;
        cin>>num[i]>>score[i];
    } while (score[i]>=0);
    return i;
}
/*****************线性查找**************/
int LinSearch(long num[],long x,int n)
{
    int i;
    for ( i = 0; i < n; i++)
    {
        if (num[i]==x)
        {
            return i;
        }       
    }
    return -1;
}
/**************************************/

int main()
{
    int score[N],n,pos,poss;
    long num[N],x;
    n=ReadScore(num,score);
    cout<<"input the searching ID"<<endl;
    cin>>x;
    pos=LinSearch(num,x,n);
    if (pos!=-1)
    {
        cout<<"\nscore="<<score[pos];
    }
    else
    {
        cout<<"\nNot Found Score";
    }
    poss=BinSearch(num,x,n);
    if (poss!=-1)
    {
        cout<<"\nindex="<<pos;
    }
    else
    {
        cout<<"\nNot Found Index";
    }
    
    return 0;
}
