#include<stdio.h>
#include<iostream>
using namespace std;

// int NumberOfZeroDegree(BTNode *T)//求二叉树中度为0的节点个数 
// {
//     int i=0;
//     if(NULL != T)
//     {
//             if(NULL==T->lchild  && NULL==T->rchild)
//             {
//                          i=1;       
//             }
//             else
//             {
//                 i= NumberOfZeroDegree(T->lchild)+NumberOfZeroDegree(T->rchild);
//             }
             
//     }
//     return i;
// }


// int NumberOfOneDegree(BTNode *T)//求二叉树中度为1的节点个数 

// {
//     int i=0;
//     if(NULL != T)
//     {
           
//            if((NULL!=T->lchild  && NULL==T->rchild) ||(NULL!=T->rchild && NULL ==T->lchild))
//             {
//                  i=1+NumberOfOneDegree(T->lchild)+NumberOfOneDegree(T->rchild);
//             }
//             else
//             {
//                  i=NumberOfOneDegree(T->lchild)+NumberOfOneDegree(T->rchild);
//             }
            
//     }
//     return i;
    
// }


// int NumberOfTwoDegree(BTNode *T)//求二叉树中度为2的节点个数 

// {
//     int i=0;
    
//     if(NULL != T)
//     {
//             if((NULL!=T->lchild)&&(NULL!=T->rchild))
//               i=1+NumberOfTwoDegree(T->lchild)+NumberOfTwoDegree(T->rchild); 
//             else
//               i=NumberOfTwoDegree(T->lchild)+NumberOfTwoDegree(T->rchild); 
//     }
//     return i;
// }


// int NumberAllNodes(BTNode *T)
// {
//     return NumberOfZeroDegree(T)+NumberOfOneDegree(T)+NumberOfTwoDegree(T);
// }

