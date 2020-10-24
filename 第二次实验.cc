#include "stdio.h"				
#include "stdlib.h"				//�ṩmalloc()��free()
#include "string.h"				//�ṩstrcpy()��

struct Node
{
	int a;				//������
	struct Node* next;	//ָ����(ָ��ڵ��ָ�룩
};

struct Node* head= NULL;
struct Node* end = NULL;

void AddListTill();
void AddListRand(int index,int a);
void ScanList();
struct Node* FindNode(int a );
void FreeList();
void AddListRand(int index,int a);
void DeleteListTail();
void DeleteListHead();
void DeleteListRand(int a);

void AddListTill(int a )
{
		//����һ���ڵ�
		struct Node* temp=(struct Node*)malloc(sizeof(struct Node));		//�˴�ע��ǿ������ת��

		//�ڵ����ݽ��и�ֵ
		temp->a=a;
		temp->next=NULL;		
		
		//���ӷ��������1.һ���ڵ㶼û��2.�Ѿ��нڵ��ˣ���ӵ�β����
		if(NULL==head)
		{	

			head=temp;
		//	end=temp;
		}
		else
		{
		end->next=temp;
	//	end=temp;			//β���Ӧ��ʼ��ָ�����һ��
		}
		end=temp;			//β���Ӧ��ʼ��ָ�����һ��
}

void ScanList()
{
	struct Node *temp =head;		//����һ����ʱ������ָ��ͷ
	while (temp !=NULL)
	{
		printf("%d\n",temp->a);
		temp = temp->next;		//tempָ����һ���ĵ�ַ ��ʵ��++����
	}

}


struct Node* FindNode(int a )
{
	struct Node *temp =head;
	while(temp !=NULL)
	{
	if(a == temp->a)
	{
		return temp;
	}
	temp = temp->next;
	}
	//û�ҵ�
		return NULL;
} 


void FreeList()
{
	//һ��һ��NULL
	struct Node *temp =head;		//����һ����ʱ������ָ��ͷ
	while (temp !=NULL)
	{
	//	printf("%d\n",temp->a);
		struct Node* pt =temp;
		temp = temp->next;		//tempָ����һ���ĵ�ַ ��ʵ��++����
		free(pt);					//�ͷŵ�ǰ
	}
	//ͷβ���	��Ȼ�´ε�ͷ�ͽ���0x10
	head =NULL;
	end =NULL;
}


void AddListRand(int index,int a)
{	

    if (NULL==head)
	{
		printf("����û�нڵ�\n");
		return;
	}	
    struct Node* pt =FindNode(index);
	if(NULL==pt)    //û�д˽ڵ�
	{
		printf("û��ָ���ڵ�\n");
		return;
	}
    //�д˽ڵ�
    //������ʱ�ڵ㣬�����ڴ�
	struct Node* temp =(struct Node *)malloc(sizeof(struct Node));
	//�ڵ��Ա���и�ֵ
	temp->a=a;
	temp->next=NULL;
	//���ӵ������� 1.�ҵ��Ľڵ���β�� 2.�ҵ��Ľڵ����м� 
	if (pt == end)
	{
	//β�͵���һ��ָ���²���Ľڵ�
	end->next=temp;
	//�µ�β��
	end=temp;
	}else
	{
	// �������� ���Ƚ�Ҫ����Ľڵ�ָ��ָ��ԭ���ҵ��ڵ����һ����
	temp->next=pt->next;
	//����ǰ��
	pt->next=temp;
	}

}



void DeleteListTail()
{ 
	if (NULL == end)
	{
		printf("����Ϊ�գ�����ɾ��\n");
		return;
	}
	//����Ϊ�� 
	//������һ���ڵ�
	 if (head==end)
	 {
		 free(head);
		 head=NULL;
		 end=NULL; 
	 }
	 else
	 {
		//�ҵ�β��ǰһ���ڵ�
		 struct Node* temp =head;
		 while (temp->next!=end)
		 {
			 temp = temp->next;
		 }
		 //�ҵ��ˣ�ɾβ��
		//�ͷ�β��
		 free(end);
		 //β��Ǩ��
		 end=temp;
		 //β��ָ��ΪNULL
		 end->next=NULL;
	 }

}


void DeleteListHead()
{	//��ס��ͷ
	struct Node* temp=head;
	//������ 
	if (NULL==head)
	{
			printf("����Ϊ��\n");
			return;
	}

	head=head->next;//ͷ�ĵڶ����ڵ����µ�ͷ
	free(temp);

}

void DeleteListRand(int a)
{

	//�����ж� �ǲ���û�ж���
	if(NULL==head)
	{
	printf("����û����\n");
	return;
	}
    //�����ж�����������ڵ�
	struct Node* temp =FindNode(a);
	if(NULL==temp)
	{
	printf("���޴˵�\n");
	return;
	}
	//�ҵ���,��ֻ��һ���ڵ�
	if(head==end)
	{
	free(head);
	head=NULL;
	end=NULL;
	}
	else if(head->next==end) //�������ڵ�
	{
	//����ɾ��ͷ����ɾ��β
	if(end==temp)
		{	DeleteListTail(); }
	else if(temp==head)
		{	DeleteListHead(); }	
	}
	else//����ڵ�
	{
		//����ɾ��ͷ����ɾ��β
		if(end==temp)
			DeleteListTail();
		else if(temp==head)
			DeleteListHead();	
		else	//ɾ���м�ĳ���ڵ�
		{	//��Ҫɾ��tempǰһ��������
			struct Node*pt =head;
			while(pt->next!=temp)
			{
			pt=pt->next;
			}
			//�ҵ���
			//��ǰһ��ֱ�����Ӻ�һ�� ����ָ���ļ���
			 pt->next=temp->next;
			 free(temp);
		
		}
	}
	

}

int main ()
{	
	struct Node *pFind;
	//���贴��5���ڵ�
    int n,j,k,o;
    printf("������Ҫ�����������м����ڵ� ");
    scanf("%d",&n);
	for(int i=0;i<n;i++)
	AddListTill(i);
	ScanList();

    printf("���룺����������Ԫ�ص�λ�� ");
    scanf("%d",&j);
	printf("���룺����������Ԫ�� ");
	scanf("%d",&k);
	AddListRand(j-2,k);		//��ָ��λ��4���ӽڵ�14oo
//	DeleteListTail();		//ɾ��һ��β���
    ScanList();	
    printf("������Ҫɾ����Ԫ�� ");
    scanf("%d",&o);
	DeleteListRand(o);		//ɾ��4�ڵ�
	ScanList();				//�����������
	FreeList();				//ɾ������
/*	pFind = FindNode(5);	//����5�ڵ�

	if (pFind !=  NULL)
	{
		printf("�ҵ�%d\n",pFind->a);	//�ҵ��ڵ㲢������ýڵ�����
	}
	else
	{
		printf("No Find!\n");
	}

*/
}
