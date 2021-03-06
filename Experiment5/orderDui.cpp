#include<stdlib.h>
#include<stdio.h>
#define QUEUE_MAX_NUM 5

typedef struct
{
	int queue[QUEUE_MAX_NUM];
	int front; //头指针
	int rear;  //尾指针
	int s;	   //标志
} Queue_Type;  //定义结构体

void InitQueue(Queue_Type *p); // 初始化队列

void InQueue(Queue_Type *p, int m, int x); //入队函数

int OutQueue(Queue_Type *p, int m); //出队函数

void QuDuiTou(Queue_Type *p);

int main() //主函数
{
	int i, x, flag;
	Queue_Type p;
	while (1)
	{
		InitQueue(&p);
		printf("\n请输入队数据:\n");
		for (i = 1; i <= QUEUE_MAX_NUM; i++)
		{
			scanf("%d", &x);
			InQueue(&p, i, x);
		}
        QuDuiTou(&p);
		printf("\n出队数据如下:\n");

		for (i = 1; i <= QUEUE_MAX_NUM; i++)
		{
			flag = OutQueue(&p, i);
			printf("%d\n", flag);
		}
		
		QuDuiTou(&p);
		printf("\n-------------------\n");
	}
	return 0;
}


void InitQueue(Queue_Type *p)//初始化一个空队列
{
	p->front = 0;//头指针为0
	p->rear = 0;//尾指针为0
	p->s = 0;//定义一个s标志，作为循环队列队满队空的标志
}

void InQueue(Queue_Type *p, int m, int x)
{
	p->rear += 1;			   //入队尾指针后移一位，
	if (p->rear == m + 1)	   //判断队列是否为满，如果满，如果尾指针指向第五个元素的下一位
		p->rear = 1;		   //转到头部
	p->queue[p->rear - 1] = x; //每次的入队对元素x，把元素x赋值给队尾
	p->s = 1;				   //s=1代表队列满
}


int OutQueue(Queue_Type *p, int m)
{
	int y;
	p->front = p->front % m + 1;//尾指针向后移动一个位置
	y = p->queue[p->front - 1];//队头元素赋值给y
	if (p->front == p->rear)//队列空的判断
		p->s = 0;//s=0时代表队列空
	return y;
}

void QuDuiTou(Queue_Type *p)
{
    
	if (p->front==p->rear)
	{
		printf("队头无元素\n");
	}
	else{
		int k;
    	k=p->queue[p->front];
    	printf("取队头元素为：%d\n",k);
	}
}
