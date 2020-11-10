#include <stdio.h>
#include <stdlib.h>

typedef struct lineStack{
    int data;
    struct lineStack * next;
}lineStack;

lineStack* push(lineStack * stack,int a){
    lineStack * line=(lineStack*)malloc(sizeof(lineStack));
    line->data=a;
    line->next=stack;
    stack=line;
    printf("入栈元素：%d\n",a);
    return stack;
}

lineStack * pop(lineStack * stack){
    if (stack) {
        lineStack * p=stack;
        stack=stack->next;
        printf("出栈元素：%d \n",p->data);
  
        free(p);
    }else{
        printf("栈内没有元素");
        return stack;
    }
    return stack;
}


int main() {
    lineStack * stack=NULL;

    for (int i = 0; i < 5; i++)
    {
        stack=push(stack,i);
    }
    printf("-----接下来依次出栈-----\n");
    for (int i = 5; i >= 0; i--)
    {
        stack=pop(stack);
    }
    return 0;
}