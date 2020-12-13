// 函数指针选择排序

#include<iostream>
using namespace std;

int Ascending(int a  ,int b);
int Descending(int a,int b);
void Swap(int *a,int*b);
void SeletionSort(int a[],int n,int (*compare)(int,int));
void SeletionSort(int a[],int n,int (*compare)(int,int))
{
    int i ,j,k;
    for ( i = 0; i < n-1; i++)
    {
        k=i;
        for ( j= i+1; j < n; j++)
        {
            if ((*compare)(a[j],a[k]))
            {
                k=j;
            }
        }
        if (k!=i)
        {
            Swap(&a[k],&a[i]);
        }
        
        
    }
    
}

int Ascending(int a  ,int b)
{
    return a<b;
}
int Descending(int a,int b)
{
    return a>b;
}

void Swap(int *a,int*b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}


int main()
{   
    int i ; 
    int n=5;
    int a[n]={1,8,2,1,5};
    SeletionSort(a,n,Descending);
    for ( i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    SeletionSort(a,n,Ascending);
    for ( i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    
    return 0;
}
