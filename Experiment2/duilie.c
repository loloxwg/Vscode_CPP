#include<stdio.h>
#define N 5

// int Input();
// int Read();
int main(){
    int a[N];
    int i;
    printf("input 5 datas:\n");
    for ( int i = 0; i < N; i++)
    {
        scanf("%d",&a[i]);
    }

    printf("output 5 datas:\n");
    for ( int j = N-1; j >=0; j--)
    {
        printf("%d\n",a[j]);
    }
    getchar();
}

// int Input(){

// }

// int Read (){

// }