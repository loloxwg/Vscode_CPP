// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #define N 5 //矩阵级数
// #define K 9 //矩阵中元素的最大值
// void main()
// {
//   int num[N][N];
//   int j, x, i, b = 0, p = 0;

//   for (i = 0; i < N; i++)
//     num[0][i] = rand() % K; //第一行元素随机输出
//   do                        //do while退出条件循环，好处在于判断条件在执行循环后检查判断条件，保证循被循环体语句至少被循环一次，while for都是入口条件循环，在每次执行循环之前先检查判断条件
//   {
//     for (j = b; j < N; j++)
//     {
//       num[b][j] = num[0][p];
//       num[j][b] = num[0][p];
//       p++;
//     }
//     b++;
//   } while (b != N); //do while循环本身是一个语句，需要分号
//   for (x = 0; x < N; x++)
//   {
//     for (i = 0; i < N; i++)
//     {
//       printf("%2d ", num[x][i]);
//     }
//     printf("\n\n");
//   }
// }

#include <stdio.h>

int i, j, a[10][10] = {0};

/*int a[4][4] = {
	{1,2,3,4},
	{2,2,2,3},
	{3,2,3,4},
	{4,3,4,4},
};*/

int main()
{
  srand((unsigned)time(NULL)); //用时间做种，每次产生随机数不一栿
  for (i = 0; i < 10; ++i)
  {
    //a[i][0] = i+1;
    for (j = 0; j < 10; ++j)
    {
      if (j > i)
        a[i][j] = rand() % 10 + 1;
      else if (i > j)
        a[i][j] = a[j][i];
      else
        a[i][j] = rand() % 10 + 1;
    }
  }
  for (i = 0; i < 10; ++i)
  {
    for (j = 0; j < 10; ++j)
      printf("%4d", a[i][j]);
    printf("\n");
  }
  return 0;
}