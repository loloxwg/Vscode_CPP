#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100

typedef int Status; 

//学生信息定义 
typedef struct {
    char no[8];   //8位学号
    char name[20]; //姓名
    double price;     //成绩
}student;
typedef student ElemType;

//顺序表存储结构
typedef struct{
	ElemType *elem;
	int length;
}SqList;

//顺序表初始化 
Status InitList(SqList &L){
	L.elem=new ElemType[MAXSIZE];
	if(!L.elem) exit(0);
	L.length=0;
	return 1;
}
//返回学生信息 
ElemType GetElem(SqList L,int i){
	return L.elem[i];
}
// 根据名字查找
int Search(SqList &L,char str[])  
{
	for(int i=1;i<=L.length;i++)
	{
		if(strcmp(L.elem[i].name,str)==0)
			return i;
	}
	return 0;
}
// 在 i位置插入某个学生的信息 
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
 // 在顺序表中删除 i位置的学生信息
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
	printf("姓名:");	scanf("%s",e->name);
	printf("学号:");	scanf("%s",e->no);
	printf("成绩:");	scanf("%lf",&e->price);
	printf("输入完成\n\n");
}
 
void Output(ElemType *e)
{
	printf("姓名:%-20s\n学号:%-10s\n成绩:%-10.2lf\n\n",e->name,e->no,e->price);
}
 
int main(){
	SqList L;
	ElemType a,b,c,d;
	printf("\n1.构造顺序表\n");
	printf("2.输入学生信息\n");
	printf("3.显示学生表信息\n");
	printf("4.根据姓名进行查找\n");
	printf("5.显示指定的位置学生信息\n");
	printf("6.在指定位置插入学生信息\n");
	printf("7.删除指定位置的学生记录\n");
	printf("8.统计学生人数\n");
	printf("9.退出\n\n");
	int n,choose;
	while(1) {
		printf("请选择：");
		scanf("%d",&choose);
		if(choose==9) break;
		switch(choose){
			case 1:if(InitList(L))  
			           printf("成功建立顺序表\n");
			        else 
					   printf("失败");
					break;
			case 2:	printf("请输入要录入的学生人数:");
					scanf("%d",&n);
					for(int i=1;i<=n;i++)
					{
						printf("第%d个学生:\n",i);
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
					printf("请输入要查找的学生姓名:");
					scanf("%s",str);
					if(Search(L,str))
						Output(&L.elem[Search(L,str)]);
					else
						printf("没有此学生信息！\n");
					break;
			case 5:printf("请输入要查询的位置:");
					int id1;
					scanf("%d",&id1);
					b=GetElem(L,id1);
					Output(&b);
					break;
			case 6:	printf ("请输入要插入的位置:");
					int id2;
					scanf("%d",&id2);
					printf("请输入学生信息:\n");
					Input(&c);
					if(ListInsert(L,id2,c))
					{
						n++;
						puts("插入成功");
					}
					else
					{
						puts("插入失败");	
					}
					break;
			case 7:printf("请输入要删除的位置:");
					int id3;
					scanf("%d",&id3);
					if(ListDelete(L,id3))
					{
						n--;
						puts("删除成功");
					}
					else
					{
						puts("删除失败");
					}
					break;
			case 8:printf("已录入的学生个数为:%d\n\n",L.length);
				   break;	
		}
	}
	return 0;
}
