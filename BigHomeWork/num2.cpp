#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

typedef int Status; 

//ѧ����Ϣ���� 
typedef struct {
    char no[8];   //8λѧ��
    char name[20]; //����
    double price;     //�ɼ�
}student;

typedef student ElemType;

//����洢�ṹ
typedef struct LNode{
    ElemType   data;       //������
    struct LNode  *next;   //ָ����
}LNode,*LinkList;

//�����ʼ�� 
Status InitList(LinkList &L){
	L=new LNode;
	L->next=NULL; 
	return 1;
}
//��ʾѧ������Ϣ 
Status GetElem(LinkList L,int i,ElemType &e) 
{
	LinkList p;
	p=L->next;
	int j=1;
	while(p&&j<i)
	{
		p=p->next;
		++j;
	}
	if(!p||j>i)	
	    return 0;
	e=p->data;
	return 1;
}
// �������ֽ��в��� 
Status Search(LNode L,char str[],LinkList &p)
{
	p=L.next; 
	while(p)
	{
		if(strcmp(p->data.name,str)==0)
			return 1;
		p=p->next;
	}
	return 0;
}
// ��ָ��λ�ò���ĳ��ѧ������Ϣ
Status ListInsert(LinkList L,int i,ElemType e) 
{
	LinkList p,s;
	p=L;
	int j=0;
	while(p&&j<i-1)
	{
		p=p->next;
		++j;
	}
	if(!p||j>i-1)	
	    return 0;
	s=new LNode;
	s->data=e;
	s->next=p->next;
	p->next=s;
	return 1;
}
 // ɾ��ָ��λ�õ�ѧ����Ϣ 
Status ListDelete(LinkList p,int i) 
{
	int j=0;
	while((p->next)&&(j<i-1))
	{
		p=p->next;
		++j;
	}
	if(!(p->next)||(j>i-1))	return 0;
	LinkList q;
	q=p->next;
	p->next=q->next; 
	delete q;
	return 1;
}
 
void Input(ElemType *e)
{
	printf("����:");	scanf("%s",e->name);
	printf("ѧ��:");	scanf("%s",e->no);
	printf("�ɼ�:");	scanf("%lf",&e->price);
	printf("�������\n\n");
}
 
void Output(ElemType *e)
{
	printf("����:%-20s\nѧ��:%-10s\n�ɼ�:%-10.2lf\n\n",e->name,e->no,e->price);
}
 
int main(){
	LNode L;
	LinkList p;
	ElemType a,b,c,d;
	printf("\n1.��������\n");
	printf("2.����ѧ����Ϣ\n");
	printf("3.��ʾѧ������Ϣ\n");
	printf("4.�����������в���\n");
	printf("5.��ʾָ����λ��ѧ����Ϣ\n");
	printf("6.��ָ��λ�ò���ѧ����Ϣ\n");
	printf("7.ɾ��ָ��λ�õ�ѧ����¼\n");
	printf("8.ͳ��ѧ������\n");
	printf("9.�˳�\n\n");
	int n,choose;
	while(1) {
		printf("��ѡ��");
		scanf("%d",&choose);
		if(choose==9) break;
		switch(choose){
			case 1:if(InitList(p))  
			           printf("�ɹ���������\n");
			        else 
					   printf("ʧ��");
					break;
			case 2:	printf("������Ҫ¼���ѧ������:");
					scanf("%d",&n);
					for(int i=1;i<=n;i++)
					{
						printf("��%d��ѧ��:\n",i);
						Input(&a);
						ListInsert(&L,i,a);
					}
					break;
			case 3:for(int i=1;i<=n;i++)
					{
						GetElem(&L,i,b);
						Output(&b);
					}
					break;
			case 4:	char str[15];
					printf("������Ҫ���ҵ�ѧ������:");
					scanf("%s",str);
					if(Search(L,str,p))
						Output(&(p->data));
					else
						printf("û�д�ѧ����Ϣ��\n");
					break;
			case 5:printf("������Ҫ��ѯ��λ��:");
					int d1;
					scanf("%d",&d1);
					GetElem(&L,d1,c);
					Output(&c);
					break;
			case 6:	printf ("������Ҫ�����λ��:");
					int d2;
					scanf("%d",&d2);
					printf("������ѧ����Ϣ:\n");
					Input(&c);
					if(ListInsert(&L,d2,c))
					{
						n++;
						puts("����ɹ�");
					}
					else
					{
						puts("����ʧ��");	
					}
					break;
			case 7:printf("������Ҫɾ����λ��:");
					int d3;
					scanf("%d",&d3);
					if(ListDelete(&L,d3))
					{
						n--;
						puts("ɾ���ɹ�");
					}
					else
					{
						puts("ɾ��ʧ��");
					}
					break;
			case 8:printf("��¼���ѧ������Ϊ:%d\n\n",n);
				   break;	
		}
	}
	return 0;
}
