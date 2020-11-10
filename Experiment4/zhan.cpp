#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5

typedef struct Sta
{
    int *top;
    int *bottom;
    int stack_size;
    
}stack;


stack InitStack (stack p)
{
    p.bottom = (int *)malloc(p.stack_size * sizeof(int));
    if (p.bottom == NULL)
    {
        printf("初始化栈失败\n");
        exit(0);
    }
    p.top = p.bottom;
    p.stack_size = MAX_SIZE;

    return p;
}
/* 入栈 */
stack Push (stack p)
{
    int data;
  
    printf("Please input data : ");
    scanf("%d", &data);
    *p.top = data;
    p.top++;

    return p;
}
/*出栈 */
stack Pop (stack p)
{
   
    p.top--;
    printf("出栈元素为：%d\n", *p.top);

    return p;
}

/*遍历栈中元素，打印*/
void DisplyStack (stack p)
{
    
    printf("栈中元素为：\n");
    if (p.top==p.bottom)
    {
        printf("空");
    }
    
    while (p.top != p.bottom)
    {
        p.top--;
        printf("%d ", *p.top);
    }

}

int main()
{
    stack p;
    char ch;

    p.stack_size = MAX_SIZE;
    p = InitStack (p);   
    for ( int i = 0; i <MAX_SIZE; i++)
    {
        p=Push(p);

    }
    DisplyStack(p);
    printf("\n");
    printf("依次出栈\n");
    for (int i = 0; i < MAX_SIZE; i++)
    {
        p=Pop(p);
    }
    DisplyStack(p);
    
    return 0;
}
