#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100

typedef int Status; 

//ѧ����Ϣ���� 
typedef struct {
    char no[8];   //8λѧ��
    char name[20]; //����
    double price;     //�ɼ�
}student;
typedef student ElemType;

//˳���洢�ṹ
typedef struct{
	ElemType *elem;
	int length;
}SqList;

//˳����ʼ�� 
Status InitList(SqList &L){
	L.elem=new ElemType[MAXSIZE];
	if(!L.elem) exit(0);
	L.length=0;
	return 1;
}
//����ѧ����Ϣ 
ElemType GetElem(SqList L,int i){
	return L.elem[i];
}
// �������ֲ���
int Search(SqList &L,char str[])  
{
	for(int i=1;i<=L.length;i++)
	{
		if(strcmp(L.elem[i].name,str)==0)
			return i;
	}
	return 0;
}
// �� iλ�ò���ĳ��ѧ������Ϣ 
Status ListInsert(SqList &L,int i,ElemType e)
{
	if((i<1)||(i>L.length+1))	return 0;
	if(L.length==MAXSIZE)	return 0;
	for(int j=L.length;j>=i;j--)
	{
		L.elem[j+1]=L.elem[j];
	}
	L.elem[i]=e;
	++L.length;
	return 1;
}
 // ��˳�����ɾ�� iλ�õ�ѧ����Ϣ
Status ListDelete(SqList &L,int i)  
{
	if((i<1)||(i>L.length))	return 0;
	for(int j=i;j<=L.length;j++)
	{
		L.elem[j]=L.elem[j+1];
	}
	--L.length;
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
	SqList L;
	ElemType a,b,c,d;
	printf("\n1.����˳���\n");
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
			case 1:if(InitList(L))  
			           printf("�ɹ�����˳���\n");
			        else 
					   printf("ʧ��");
					break;
			case 2:	printf("������Ҫ¼���ѧ������:");
					scanf("%d",&n);
					for(int i=1;i<=n;i++)
					{
						printf("��%d��ѧ��:\n",i);
						Input(&L.elem[i]);
					}
					L.length=n;
					break;
			case 3:for(int i=1;i<=n;i++)
					{
						a=GetElem(L,i);
						Output(&a);
					}
					break;
			case 4:	char str[15];
					printf("������Ҫ���ҵ�ѧ������:");
					scanf("%s",str);
					if(Search(L,str))
						Output(&L.elem[Search(L,str)]);
					else
						printf("û�д�ѧ����Ϣ��\n");
					break;
			case 5:printf("������Ҫ��ѯ��λ��:");
					int id1;
					scanf("%d",&id1);
					b=GetElem(L,id1);
					Output(&b);
					break;
			case 6:	printf ("������Ҫ�����λ��:");
					int id2;
					scanf("%d",&id2);
					printf("������ѧ����Ϣ:\n");
					Input(&c);
					if(ListInsert(L,id2,c))
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
					int id3;
					scanf("%d",&id3);
					if(ListDelete(L,id3))
					{
						n--;
						puts("ɾ���ɹ�");
					}
					else
					{
						puts("ɾ��ʧ��");
					}
					break;
			case 8:printf("��¼���ѧ������Ϊ:%d\n\n",L.length);
				   break;	
		}
	}
	return 0;
}
