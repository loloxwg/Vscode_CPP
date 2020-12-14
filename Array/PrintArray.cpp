//用来打印array
#define N 5
#include<iostream>
#include<iomanip>
using namespace std;
void PrintArray(int a[][N], int m, int n);

void PrintArray(int a[][N], int m, int n)//打印函数
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout.width(2);
            cout << setiosflags(ios::right);
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}