#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include<iostream>
#define none '#' 
typedef int ElemType; //��������

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lChild, *rChild;
} BiTNode, *BiTree;


int createBiTree(BiTree& T){ 
	ElemType ch;
	scanf("%c",&ch);
	if(ch == none ) T = NULL;
	else{
		T = new BiTNode;
		T->data = ch;
		createBiTree(T->lChild);
		createBiTree(T->rChild);
	}
	return 1;	
}
//�������������
void TraverseBiTree(BiTree T)
{
    if (T == NULL)
    {
        return;
    }
    printf("%d", T->data);
    TraverseBiTree(T->lChild);
    TraverseBiTree(T->rChild);
}

//�������������
void InOrderBiTree(BiTree T)
{
    if (T == NULL)
    {
        return;
    }
    InOrderBiTree(T->lChild);
    printf("%d", T->data);
    InOrderBiTree(T->rChild);
}

//�������������
void PostOrderBiTree(BiTree T)
{
    if (T == NULL)
    {
        return;
    }
    PostOrderBiTree(T->lChild);
    PostOrderBiTree(T->rChild);
    printf("%d", T->data);
}


//�������Ҷ�ӽ�����
int Leafcount(BiTree T, int &num)
{
    if (T)
    {
        if (T->lChild == NULL && T->rChild == NULL)
        {
            num++;
            printf("%d\n",T->data);
        }
        Leafcount(T->lChild, num);
        Leafcount(T->rChild, num);
    }
    return num;
}
//ɾ��Ҷ�ӽڵ�
void DeleteNode(BiTree T){
     if (T)
    {
        int i=0;
        i=T->data;
        if (T->lChild == NULL && T->rChild == NULL)
        {

            free(T);
            printf("%d\n",T->data);
        }
    
        DeleteNode(T->lChild);
        DeleteNode(T->rChild);
    }
}
//������
int main(void)
{
    BiTree T;
    BiTree *p = (BiTree *)malloc(sizeof(BiTree));
    int deepth, num = 0,num2=0;
    printf("������������Ľ�㣬�������룺\n");
    createBiTree(T);
    printf("���������������\n");
    TraverseBiTree(T);
    printf("\n");
    printf("���������������\n");
    InOrderBiTree(T);
    printf("\n");
    printf("���������������\n");
    PostOrderBiTree(T);
    printf("\n");
    Leafcount(T, num);
    printf("Ҷ�ӽ�����Ϊ��%d", num);
    printf("\n");
    DeleteNode(T);
    printf("\n");
    Leafcount(T, num);
    printf("��ʱҶ�ӽ�����Ϊ��%d", num);
    printf("\n");
    return 0;
}