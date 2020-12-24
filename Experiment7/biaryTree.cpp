#include <stdio.h>
#include <stdlib.h>
#define maxsize 10001
int j;
typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
BiTree CreatBiTree(BiTree r,int m)
{
    BiTree p,q,w;
        p = (BiTree)malloc(sizeof(BiTNode));
        p->rchild = NULL;
        p->lchild = NULL;
        p->data = m;
        q = r;
        while(q)
        {
            if(m>q->data)
            {  w = q;
                q = q->rchild;
            }
            else if(m<=q->data)  //加了一个else，一个等于号
            {  w = q;
                q = q->lchild;
            }
        }
        if(m>w->data)
            w->rchild = p;
        else
            w->lchild = p;
        return r;
 
 
    }
BiTree InitBiTree()  //初始化头结点
{
    BiTree root;
    root = (BiTree)malloc(sizeof(BiTNode));
    root->lchild = NULL;
    root->rchild = NULL;
    return root;
 
}
void midPrint(BiTree root)//中序输出
{
    if(root)
    {
        midPrint(root->lchild);
        if(j==1)
        {
            j++;printf("%d",root->data);
        }
        else
            printf(" %d",root->data);
 
 
        midPrint(root->rchild);
    }
}
int main()
{
     int m;
     scanf("%d",&m);
       BiTree root;
       int a[maxsize],i;
       j = 1;
       root = InitBiTree();
       scanf("%d",&root->data);
       for(i = 1;i<=m-1;i++)
       {
           scanf("%d",&a[i]);
           CreatBiTree(root,a[i]);
       }
            midPrint(root);
            printf("\n");
    return 0;
}
//二叉排序树