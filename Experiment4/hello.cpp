#include<stdlib.h>
#include<stdio.h>
int main(){
    printf("hello");
}


//先序创建二叉树
// int CreateBiTree(BiTree *T)
// {
//     ElemType ch;
//     ElemType temp;
//     scanf("%d", &ch);
//     temp = getchar();
//     if (ch == -1)
//     {
//         *T = NULL;
//     }
//     else
//     {
//         *T = (BiTree)malloc(sizeof(BiTNode));
//         if (!(*T))
//         {
//             exit(-1);
//         }
//         (*T)->data = ch;
//         printf("输入%d的左子结点：", ch);
//         CreateBiTree(&(*T)->lChild);
//         printf("输入%d的右子结点：", ch);
//         CreateBiTree(&(*T)->rChild);
//     }
//     return 1;
// }