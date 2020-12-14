#define N 5
#include<iostream>
#include <stdio.h>
using namespace std;
void PrintArray(int a[][N],int m,int n);
void SetArray(int a[][N], int m, int n);

void SetArray(int a[][N], int m, int n)
{
    int i, j, len = 1;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[i][j] = len;
            len++;
        }
    }
}

void PrintArray(int a[][N],int m,int n)
{
    int i ,j ;
    for ( i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
//            cout<<a[i][j]<<" ";
            printf("%d\t",a[i][j]);

        }
        printf("\n");
//        cout<<endl;


    }

}

int main()
{
    int m=5;
    int n=5;
    int a[N][N];
    SetArray(a,m,n);
    PrintArray(a,m,n);
    return 0;
}