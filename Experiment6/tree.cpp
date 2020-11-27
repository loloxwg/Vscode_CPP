#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include<iostream>
#define none '#' 
typedef int ElemType; //数据类型

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
//先序遍历二叉树
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

//中序遍历二叉树
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

//后序遍历二叉树
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


//求二叉树叶子结点个数
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
//删除叶子节点
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
//主函数
int main(void)
{
    BiTree T;
    BiTree *p = (BiTree *)malloc(sizeof(BiTree));
    int deepth, num = 0,num2=0;
    printf("请输入二叉树的结点，先序输入：\n");
    createBiTree(T);
    printf("先序遍历二叉树：\n");
    TraverseBiTree(T);
    printf("\n");
    printf("中序遍历二叉树：\n");
    InOrderBiTree(T);
    printf("\n");
    printf("后序遍历二叉树：\n");
    PostOrderBiTree(T);
    printf("\n");
    Leafcount(T, num);
    printf("叶子结点个数为：%d", num);
    printf("\n");
    DeleteNode(T);
    printf("\n");
    Leafcount(T, num);
    printf("此时叶子结点个数为：%d", num);
    printf("\n");
    return 0;
}