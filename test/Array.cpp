#include <iostream>
using namespace std;
#define N 5
void SetRowArray(int a[][N], int m, int n)
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

void SetColumnArray(int (*a)[N], int m, int n)
{
    int i, j, len = 1;
    for (j = 0; j < n; j++)
    {
        for (i = 0; i < m; i++)
        {
            a[i][j] = len;
            len++;
        }
    }
}
void PrintArray(int a[][N], int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void setHelixArray(int (*a)[N], int len, int n)
{
    int m, k, level;
    level = n > 0 ? (n + 1) / 2 : -1;
    for (m = 0; m < level; m++)

    {
        //top
        for (k = m; k < n - m; k++)
        {
            a[m][k] = len++;
        }
        //right
        for (k = m + 1; k < n - m - 1; k++)
        {
            a[k][n - m - 1] = len++;
        }
        //bottom
        for (k = n - m - 1; k > m; k--)
        {
            a[n - m - 1][k] = len++;
        }
        //left
        for (k = n - m - 1; k > m; k--)
        {
            a[k][m] = len++;
        }
    }
}
int main()
{
    int a[N][N];
    int b[N][N];
    int c[N][N];
    int m = 5;
    int n = 5;
    SetRowArray(a, m, n);
    PrintArray(a, m, n);
    cout << endl;
    SetColumnArray(b, n, m);
    PrintArray(b, m, n);
    cout << endl;
    setHelixArray(c, 1, n);
    PrintArray(c, n, n);

    return 0;
}