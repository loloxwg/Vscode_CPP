#include <iostream>


using namespace std;


#define none 0        
typedef int TelemType; // �ڵ�����������

// ��������洢 
typedef struct Binode{
	TelemType data;
	struct Binode *left,*right;
}Binode,* Bitree;
// ���������뽨�������� 
int createBiTree(Bitree& T){ 
	TelemType ch;
	scanf("%d",&ch);
	if(ch == none ) T = NULL;
	else{
		T = new Binode;
		T->data = ch;
		createBiTree(T->left);
		createBiTree(T->right);
	}
	return 1;	
}
// ����������������� 
int preOrder(Bitree T){
	if(T){
		printf("%d ",T->data);
		preOrder(T->left);
		preOrder(T->right);
		return 1;
	} else return 0;
}
//�������
int inOrder(Bitree T){
	if(T){
		if(T->left) inOrder(T->left);
		printf("%d ",T->data);
		if(T->right) inOrder(T->right);
		return 1;
	} else return 0;
} 
//�������
int postOrder(Bitree T){
	if(T){
		if(T->left) postOrder(T->left);
		if(T->right) postOrder(T->right);
		printf("%d ",T->data);
		return 1;
	}return 0;
} 
//�������Ҷ�ӽ�����
int Leafcount(Bitree T, int &num)
{
    if (T)
    {
        if (T->left == NULL && T->right == NULL)
        {
            num++;
        }
        Leafcount(T->left, num);
        Leafcount(T->right, num);
    }
    return num;
}
 
int treeDeepth(Bitree &T,int &h){
	int left,right;
	if(!T) h=0;
	else{
		left=treeDeepth(T->left,h);
		right=treeDeepth(T->right,h);
		if(left>right){
			h=left+1;
		}
		else h=right+1;
	}
	return h;
}

// int DeleteLeafcount(Bitree T, int &num)
// {
//     if (T)
//     {
//         if (T->left == NULL && T->right == NULL)
//         {
//             num++;
//         }
//         DeleteLeafcount(T->left, num);
//         DeLeafcount(T->right, num);
//     }
//     return num;
// }


int main(){
	//�������룺
    //  // 12##3##
    //
    //     25 30 6 22 71 
    //    25 30 6 22 # # 71 # # 16 # # 26 2 4 36 # # # 5 # # 33 # 40 55 # # 44 # #
    //    '25''30''6''22'##'71'##'16'##'26''24''36'###'5'##'33'#'40''55'##'44'##
    //  25 30 6 22 0 0 71 0 0 10 0 0 26 2 4 36 0 0 0 5 0 0 33 0 40 55 0 0 44 0 0
    //2530622##71##16##262436###5##33#4055##44##
    //    1 2 0 0 3 0 0
	Bitree T;
    int num =0;
	int numh=0;
    cout<<"����������";
	createBiTree(T);
	cout<<"���������";
	preOrder(T);
	cout<<"\n���������";
	postOrder(T);
	cout<<"\n���������";
	inOrder(T);
    // cout<<"\nҶ�ӽ��";
    Leafcount(T,num);
    printf("��ʱҶ�ӽ�����Ϊ��%d", num);

	treeDeepth(T,numh);
	cout<<"��ȣ�"<<numh;
	cout<< endl; 

	
	return 0;
}
