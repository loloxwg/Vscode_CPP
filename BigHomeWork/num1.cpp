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
    //��������� 
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
//��ʼ��
SeqList* Init_SeqList()
{
    SeqList* L = new SeqList;
    if(L)
    {
        L->last= -1;
        return L;
    }
}
//�����㷨
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
//ɾ���㷨
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
//�����㷨
int Location_SeqList(SeqList *L,DateType x)
{
    int i=0;
    while(i <= L->last && L->data[i].num == x.num)//���ֱ�ӽ��бȽϣ�L->data[i]==x�����ᱨ���Զ�����������Ͳ���ֱ�ӱȽϡ��ж��ַ��������Խ���������
        i++;                                      //һ�ǣ�ͨ����������ؽ��бȽϡ����ǣ�����ֱ�ӱȽ����п���ȷ���ķߺ޵���Ϣ������������򵥵ķ��������Թ���һ���ϣ�
    if(i>L->last)
        return -1;
    else
        return i;
}
/*
//�����㷨
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
//���ѧ����Ϣ
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
    // printf("����������ͬѧ��ѧ�ţ����������䣬���Ƴɼ�\n");
    // for(int i=0;i<3;i++)
    // {
    //     p->last++;
    //     scanf("%d %s %d",&p->data[i].num,&p->data[i].name,&p->data[i].age);
    //     for(int j=0;j<10;j++)
    //         scanf("%f",&p->data[i].score[j]);
    // }
    int flag;
    printf("����������Ҫ���еĲ�����\n");
    printf("1.����ѧ����Ϣ\n");
	printf("2.ɾ��ѧ����Ϣ\n");
	printf("3.����ѧ����Ϣ\n");
	printf("4.��ѧ����Ϣ���л���\n");
	scanf("%d",&flag); 
	//�����㷨
	if(flag==1)
	{
		DateType dd;
		int locseat; 
		printf("����������Ҫ�����ѧ������Ϣ��λ�ã�\n");
        p->last++;
        scanf("%d %s %d",&dd.num,&dd.name,&dd.age);
        for(int j=0;j<10;j++)
            scanf("%f",&dd.score[j]);
        scanf("%d",&locseat);
		int insert_flag=Insert_SeqList(p,locseat,dd);
    	if(insert_flag==-1)
        	printf("�Բ��𣬱����������ܽ��в���ѧ����Ϣ����\n");
    	else if(insert_flag==0)
       		printf("�Բ��������ѧ����Ϣ��λ�ò��ԣ���\n");
   		else
    	{
         	printf("����ɹ�������\n");
         	print(p);
    	}
	}
	//ɾ�� 1
    if(flag==2)
	{	
		int seat; 
		printf("����������Ҫɾ����ѧ����Ϣ��λ�ã�\n");
		scanf("%d",&seat);
		int delete_flag=Delete_SeqList(p,seat);
    	if(delete_flag==0)
       		printf("�Բ���ɾ��ѧ����Ϣ��λ�ò��ԣ���\n");
    	else
    	{
      	   printf("ɾ���ɹ�������\n");
      	   print(p);
    	}
	}
	//λ�ò��� 1
	if(flag==3)
	{
		DateType d; 
		printf("����������Ҫ���ҵ�ѧ������Ϣ��\n");
		scanf("%d %s %d",&d.num,&d.name,&d.age);
        for(int j=0;j<10;j++)
            scanf("%f",&d.score[j]);
		int location_flag=Location_SeqList(p,d);
    	if(location_flag==-1)
     	   printf("�Բ���û�в��ҵ����ѧ������\n");
    	else
      	  printf("��ѧ����λ����%d\n",location_flag);
	}
	/*
	//�����㷨
	if(flag==4)
	{
		Part_SeqList(p);
    	print(p);
	}
	*/
    return 0;
}