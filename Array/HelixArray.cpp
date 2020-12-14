#include <iostream>
#include <iomanip>

using namespace std;
#define N 5
void SetRowArray(int a[][N], int m, int n)//行排列
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

void SetColumnArray(int (*a)[N], int m, int n)//列排列
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
//控制走过的圈数 (n+1)/2
//非递归螺旋方阵
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
//递归螺旋方阵
void set_Recursive_HelixArray(int a[][N], int len, int n, int m)
{
    int k, level;
    level = n > 0 ? (n + 1) / 2 : -1;
    if (m >= level)
        return;
    else
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
        set_Recursive_HelixArray(a, len, n, m + 1);
    }
}
int main()
{
    int a[N][N];
    int b[N][N];
    int c[N][N];
    int d[N][N];

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
    cout << endl;
    set_Recursive_HelixArray(d, 1, n, 0);//m=0从第一圈开始跑
    PrintArray(d, m, n);
    cout << endl;
    return 0;
}