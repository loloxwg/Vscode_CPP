#include<stdio.h>
#include<stdlib.h>
///队列
typedef int ElemType;
typedef struct QNode
{
    ElemType data;
	struct QNode *next;
}QNode,*QueuePtr;
 
typedef struct
{
    QueuePtr Front;///队头指针
    QueuePtr Rear;///队尾指针
}LinkQueue;

void InitQueue(LinkQueue &Q)
{
    Q.Front=Q.Rear=(QueuePtr)malloc(sizeof(QNode));///生成新结点作为头结点，队头和队尾指针指向此结点
    if(!Q.Front)
        return;
    Q.Front->next=NULL;///头结点的指针域置空
}

int QueueEmpty(LinkQueue Q)
{
    if(Q.Front==Q.Rear)
        return 1;
    return 0;
}
void EnQueue(LinkQueue &Q,ElemType e)
{
    int bt;
    QueuePtr s;
    s=(QueuePtr)malloc(sizeof(QNode));
    s->data=bt;
    s->next=NULL;
    Q.Rear->next=s;///将新结点插入到队尾
    Q.Rear=s;///修改队尾指针
}

void DeQueue(LinkQueue &Q,ElemType &e)
{
    int bt;
	if(Q.Front==Q.Rear)
		return;
    QueuePtr s;
	s=Q.Front->next;		///p指向队头
	Q.Front->next=s->next;
    bt=s->data;//回收		///修改头指针
	if(Q.Rear==s)
		Q.Rear=Q.Front;		///最后一个元素被删，队尾指针指向头结点
	free(s);
}

void GetHead(LinkQueue Q,ElemType &e)
{
	if(Q.Rear==Q.Front)
		return;
	e=Q.Front->next->data;
}


int main(){
    LinkQueue q;
    int m;
    int i, x, flag;

	while (1)
	{
		InitQueue(q);
		printf("\n请输入队数据:\n");
		for (i = 1; i <= 5; i++)
		{
			scanf("%d", &x);
			EnQueue(q, x);
		}
        DeQueue(q,i);
		printf("\n出队数据如下:\n");

		for (i = 1; i <= 5; i++)
		{
			m=DeQueue(q, i);
			printf("%d\n", flag);
		}
		
		
		// printf("\n-------------------\n");
	}
    // for (int i = 0; i < 5; i++)
    // {
    //     InitQueue(q);
    //     scanf("%d",&m);
    //     EnQueue(q,m);
    //     printf("%d\n",m);

    //     GetHead(q,m);
    //     printf("%d",m+1);
    // }
    
    // printf("取队首：\n");
    // GetHead(q,m);
    // for (int i = 0; i < 5; i++)
    // {
    //     DeQueue(q,m);
    // }
    
}