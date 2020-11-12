#include<stdlib.h>
#include<stdio.h>
#define QUEUE_MAX_NUM 5

typedef struct
{
	int queue[QUEUE_MAX_NUM];
	int front; //ͷָ��
	int rear;  //βָ��
	int s;	   //��־
} Queue_Type;  //����ṹ��

void InitQueue(Queue_Type *p); // ��ʼ������

void InQueue(Queue_Type *p, int m, int x); //��Ӻ���

int OutQueue(Queue_Type *p, int m); //���Ӻ���

void QuDuiTou(Queue_Type *p);

int main() //������
{
	int i, x, flag;
	Queue_Type p;
	while (1)
	{
		InitQueue(&p);
		printf("\n�����������:\n");
		for (i = 1; i <= QUEUE_MAX_NUM; i++)
		{
			scanf("%d", &x);
			InQueue(&p, i, x);
		}
        QuDuiTou(&p);
		printf("\n������������:\n");

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


void InitQueue(Queue_Type *p)//��ʼ��һ���ն���
{
	p->front = 0;//ͷָ��Ϊ0
	p->rear = 0;//βָ��Ϊ0
	p->s = 0;//����һ��s��־����Ϊѭ�����ж����ӿյı�־
}

void InQueue(Queue_Type *p, int m, int x)
{
	p->rear += 1;			   //���βָ�����һλ��
	if (p->rear == m + 1)	   //�ж϶����Ƿ�Ϊ��������������βָ��ָ������Ԫ�ص���һλ
		p->rear = 1;		   //ת��ͷ��
	p->queue[p->rear - 1] = x; //ÿ�ε���Ӷ�Ԫ��x����Ԫ��x��ֵ����β
	p->s = 1;				   //s=1���������
}


int OutQueue(Queue_Type *p, int m)
{
	int y;
	p->front = p->front % m + 1;//βָ������ƶ�һ��λ��
	y = p->queue[p->front - 1];//��ͷԪ�ظ�ֵ��y
	if (p->front == p->rear)//���пյ��ж�
		p->s = 0;//s=0ʱ������п�
	return y;
}

void QuDuiTou(Queue_Type *p)
{
    
	if (p->front==p->rear)
	{
		printf("��ͷ��Ԫ��\n");
	}
	else{
		int k;
    	k=p->queue[p->front];
    	printf("ȡ��ͷԪ��Ϊ��%d\n",k);
	}
}
