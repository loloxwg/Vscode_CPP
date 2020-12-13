//筛法求100以内所有素数
#define N 100
#include<cmath>
#include<iostream>
using namespace std;

void SiftPrime(int a[],int n);
void PrintPrime(int a [],int n);

int main()
{
    int a[N];
    SiftPrime(a,N);
    PrintPrime(a,N);
    return 0;
}


void SiftPrime(int a[],int n)
{
    int i,j;
    for ( i = 2; i <= N; i++)
    {
        a[i]=i;
    }
    for ( i = 2; i < sqrt(N); i++)
    {
        for ( j = i+1; j <=N; j++)
        {
            if (a[i]!=0&&a[j]!=0&&a[j]%a[i]==0)
            {
                a[j]=0;
            }
            
        }
        
    }
}


void PrintPrime(int a [],int n)
{
    int i ;
    for ( i = 2; i < N; i++)
    {
        if (a[i]!=0)
        {
            cout<<a[i]<<" ";
        }  
    } 
}