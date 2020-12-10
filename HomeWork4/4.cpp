#include<stdio.h>
#include<stdlib.h>
#include<string>

#define _CRT_SECURE_NO_WARNINGS

//二叉树结点
typedef struct BINARYNODE{
	char ch;
	struct BINARYNODE *lchild;
	struct BINARYNODE *rchild;
}BinaryNode;

//递归遍历
void CaculateLeafNum(BinaryNode*root,int *num){
	if (root == NULL)
	{
		return;
	}
	//没有左右树
	if (root->lchild==NULL && root->rchild==NULL)
	{
		(*num)++;
	}
	CaculateLeafNum(root->lchild,num);
	CaculateLeafNum(root->rchild, num);

}

void CreateBinaryTree(int *num){
	//生成结点
	BinaryNode node1 = { 'A', NULL, NULL };
	BinaryNode node2 = { 'B', NULL, NULL };
	BinaryNode node3 = { 'C', NULL, NULL };
	BinaryNode node4 = { 'D', NULL, NULL };
	BinaryNode node5 = { 'E', NULL, NULL };
	BinaryNode node6 = { 'F', NULL, NULL };
	BinaryNode node7 = { 'G', NULL, NULL };
	BinaryNode node8 = { 'H', NULL, NULL };
	//建立结点关系
	node1.lchild = &node2;
	node1.rchild = &node6;
	node2.rchild = &node3;
	node3.lchild = &node4;
	node3.rchild = &node5;
	node6.rchild = &node7;
	node7.lchild = &node8;
	CaculateLeafNum(&node1, num);
/*
        A
	   /  \
	  B    F
	   \    \
        C    G
	   / \   /
	  D   E H
*/	
}

int main(void){
	int num=0;//个数
	int n;
	CreateBinaryTree(&num);
	n=8-num;
	printf("%d", n);
	system("pause");
	return 0;
}
