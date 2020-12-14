//螺旋方阵的其他构造方法
#include <iostream>
#include <iomanip>

using namespace std;
#define N 5

void setHelixArry2(int a[][N], int len, int n);
void PrintArray(int a[][N], int m, int n);
void setHelixArry3(int a[][N], int len, int start, int border);
void set_Recursive_HelixArray3(int a[][N],int len ,int start,int border);
int main()
{
    int a[N][N];
    int b[N][N];
    int c[N][N];
    int d[N][N];

    int m = 5;
    int n = 5;
    setHelixArry2(a, 1, n);
    PrintArray(a, m, n);
    cout<<endl;
    setHelixArry3(b,1,0,n-1);
    PrintArray(b,m,n);
    cout<<endl;
    set_Recursive_HelixArray3(c,1,0,n-1);
    PrintArray(c,m,n);
    return 0;
}

void PrintArray(int a[][N], int m, int n) //打印函数
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

//控制走过的格子数  m<=n*n
void setHelixArry2(int a[][N], int len, int n)
{
    int start = 0, border = n - 1, k, m = 1;
    while (m <= n * n) // <=
    {
        if (start > border) //n值小于0不需要处理，直接返回
        {
            return;
        }
        else if (start == border) //n为奇数单独处理，里边只有一个格子
        {
            a[start][start] = len;
            return; //返回值注意
        }
        else
        {
            for (k = start; k <= border - 1; k++)
            {
                a[start][k] = len++;
                m++;
            }
            for (k = start; k <= border - 1; k++)
            {
                a[k][border] = len++;
                m++;
            }
            for (k = border; k >= start + 1; k--)
            {
                a[border][k] = len++;
                m++;
            }
            for (k = border; k >= start + 1; k--)
            {
                a[k][start] = len++;
                m++;
            }
            start++;
            border--;
        }
    }
}

//控制边界 start <= border
void setHelixArry3(int a[][N], int len, int start, int border)
{
    int k;
    while (start <= border)
    {
        if (start == border)
        {
            a[start][start] = len;
            return;
        }
        else
        {
            for (k = start; k <= border - 1; k++)
            {
                a[start][k] = len++;
            }
            for (k = start; k <= border - 1; k++)
            {
                a[k][border] = len++;
            }
            for (k = border; k >= start + 1; k--)
            {
                a[border][k] = len++;
            }
            for (k = border; k >= start + 1; k--)
            {
                a[k][start] = len++;
            }
            start++;
            border--;
        }
    }
}
//递归法控制边界 start <= border
void set_Recursive_HelixArray3(int a[][N],int len ,int start,int border)
{
    int k;
    if (start>border)
    {
        return;
    }
    else if (start==border)
    {
        a[start][start]=len;
        return;
    }
    else
    {

        // 逆时针螺旋方阵
        for ( k = border; k >= start+1; k--)
        {
            a[start][k]=len++;
        }
        for ( k = start; k <= border-1; k++)
        {
            a[k][start]=len++;
        }
        for ( k = start; k <= border-1; k++)
        {
            a[border][k]=len++;
        }
        for ( k = border; k>= start+1; k--)
        {
            a[k][border]=len++;
        }
       
        set_Recursive_HelixArray3(a,len,start+1,border-1);
        
        
        
    }
    
    
}