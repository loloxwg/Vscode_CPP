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
        printf("��ʼ��ջʧ��\n");
        exit(0);
    }
    p.top = p.bottom;
    p.stack_size = MAX_SIZE;

    return p;
}
/* ��ջ */
stack Push (stack p)
{
    int data;
  
    printf("Please input data : ");
    scanf("%d", &data);
    *p.top = data;
    p.top++;

    return p;
}
/*��ջ */
stack Pop (stack p)
{
   
    p.top--;
    printf("��ջԪ��Ϊ��%d\n", *p.top);

    return p;
}

/*����ջ��Ԫ�أ���ӡ*/
void DisplyStack (stack p)
{
    
    printf("ջ��Ԫ��Ϊ��\n");
    if (p.top==p.bottom)
    {
        printf("��");
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
    printf("���γ�ջ\n");
    for (int i = 0; i < MAX_SIZE; i++)
    {
        p=Pop(p);
    }
    DisplyStack(p);
    
    return 0;
}
