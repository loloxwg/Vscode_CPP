#include<stdio.h>
#include<string.h>
#define MaxSize 1000
typedef struct Student
{
    int num;
    char name[20];
    int age;
    float score[10];
    /*
    //运算符重载 
    bool operator == (const Student& datetype) const
    {
        if((num == datetype.num) && (stricmp(name, datetype.name)) && (age == datetype.age))
        {
            int flag=0;
            for(int i=0;i<10;i++)
            {
                if(score[i] == datetype.score[i])
                    flag++;
            }
            if(flag==10)
                return true;
            else
                return false;
        }
        return false;
    }
    bool operator < (const Student& datetype) const
    {
        if((num < datetype.num) && (stricmp(name, datetype.name)<0) && (age < datetype.age))
        {
            int flag=0;
            for(int i=0;i<10;i++)
            {
                if(score[i] < datetype.score[i])
                    flag++;
            }
            if(flag==10)
                return true;
            else
                return false;
        }
        return false;
    }
    */
}DateType;
typedef struct SeqList
{
    DateType data[MaxSize];
    int last;
}SeqList;
//初始化
SeqList* Init_SeqList()
{
    SeqList* L = new SeqList;
    if(L)
    {
        L->last= -1;
        return L;
    }
}
//插入算法
int Insert_SeqList(SeqList *L,int i,DateType x)
{
    int j;
    if(L->last+1==MaxSize)
        return -1;
    if(i<1||i>L->last+2)
        return 0;
    for(j=L->last;j>=i-1;j--)
        L->data[j+1]=L->data[j];
    L->data[i-1]=x;
    L->last++;
    return 1;
}
//删除算法
int Delete_SeqList(SeqList *L,int i)
{
    int j;
    if(i<1||i>L->last+1)
        return 0;
    for(j=i;j<=L->last;j++)
    {
        L->data[j-1]=L->data[j];
    }
    L->last--;
    return 1;
}
//查找算法
int Location_SeqList(SeqList *L,DateType x)
{
    int i=0;
    while(i <= L->last && L->data[i].num == x.num)//如果直接进行比较（L->data[i]==x），会报错。自定义的数据类型不能直接比较。有多种方法，可以解决这个问题
        i++;                                      //一是，通过运算符重载进行比较。二是，可以直接比较其中可以确定的愤恨的信息。如果有其他简单的方法，可以共享一下呦！
    if(i>L->last)
        return -1;
    else
        return i;
}
/*
//划分算法
void Part_SeqList(SeqList *L)
{
    int i,j;
    DateType x,y;
    x=L->data[0];
    for(i=1;i<=L->last;i++)
    {
        if(L->data[i]<x)
        {
            y=L->data[i];
            for(j=i-1;j>=0;j--)
            {
                L->data[j+1]=L->data[j];
            }
            L->data[0]=y;
        }
    }
}
*/
//输出学生信息
void print(SeqList *L)
{
    for(int i=0;i<=L->last;i++)
    {
        printf("%d %10s %2d",L->data[i].num,L->data[i].name,L->data[i].age);
        for(int j=0;j<10;j++)
        {
            printf("%6.2f ",L->data[i].score[j]);
        }
        printf("\n");
    }
}
int main()
{
    SeqList* p = Init_SeqList();
    int num;
    // printf("请输入三名同学的学号，姓名，年龄，各科成绩\n");
    // for(int i=0;i<3;i++)
    // {
    //     p->last++;
    //     scanf("%d %s %d",&p->data[i].num,&p->data[i].name,&p->data[i].age);
    //     for(int j=0;j<10;j++)
    //         scanf("%f",&p->data[i].score[j]);
    // }
    int flag;
    printf("请输入你需要进行的操作：\n");
    printf("1.插入学生信息\n");
	printf("2.删除学生信息\n");
	printf("3.查找学生信息\n");
	printf("4.对学生信息进行划分\n");
	scanf("%d",&flag); 
	//插入算法
	if(flag==1)
	{
		DateType dd;
		int locseat; 
		printf("请输入你需要插入的学生的信息和位置：\n");
        p->last++;
        scanf("%d %s %d",&dd.num,&dd.name,&dd.age);
        for(int j=0;j<10;j++)
            scanf("%f",&dd.score[j]);
        scanf("%d",&locseat);
		int insert_flag=Insert_SeqList(p,locseat,dd);
    	if(insert_flag==-1)
        	printf("对不起，表已满，不能进行插入学生信息！！\n");
    	else if(insert_flag==0)
       		printf("对不起，你插入学生信息的位置不对！！\n");
   		else
    	{
         	printf("插入成功！！！\n");
         	print(p);
    	}
	}
	//删除 1
    if(flag==2)
	{	
		int seat; 
		printf("请输入你需要删除的学生信息的位置：\n");
		scanf("%d",&seat);
		int delete_flag=Delete_SeqList(p,seat);
    	if(delete_flag==0)
       		printf("对不起，删除学生信息的位置不对！！\n");
    	else
    	{
      	   printf("删除成功！！！\n");
      	   print(p);
    	}
	}
	//位置查找 1
	if(flag==3)
	{
		DateType d; 
		printf("请输入你需要查找的学生的信息：\n");
		scanf("%d %s %d",&d.num,&d.name,&d.age);
        for(int j=0;j<10;j++)
            scanf("%f",&d.score[j]);
		int location_flag=Location_SeqList(p,d);
    	if(location_flag==-1)
     	   printf("对不起，没有查找到这个学生！！\n");
    	else
      	  printf("该学生的位置在%d\n",location_flag);
	}
	/*
	//划分算法
	if(flag==4)
	{
		Part_SeqList(p);
    	print(p);
	}
	*/
    return 0;
}