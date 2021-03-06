#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR_LEN 20
#define MAX_STUDENT_NUM 10
/*定义Student结构体
    参数：
    id:学号
    name:姓名
    phone：电话号码
*/
typedef struct student{
    int id;
    char name;
    int phone;
}STUDENT;
//插入学生信息//
int Insert(STUDENT student[],int num);
//打印学生信息
void PrintLine(STUDENT student[],int num);
//查询学生信息
void InsertionSort(STUDENT score[],int n);
//插入排序
int BinSearch(STUDENT student[],int student_id ,int num);
//按学号进行二分查找
int Search(STUDENT student[],int student_id);
//删除学生信息
int Delete(STUDENT student[],int student_id);
int main(){
    STUDENT a[MAX_STUDENT_NUM];
    STUDENT student;
    int res,num,student_id;
    int command;
    char home[]="********************\n1.Insert student\n2.Del student\n3.Search student\n4.Display all student\n5.exit\n6.BinSearch\n";

    while(1){
        printf("%s",home);
        scanf("%d",&command);
        fflush(stdin);
        switch(command){
            case 1:
                printf("输入需要插入的学生数量：\n");
                scanf("%d",&num);
                fflush(stdin);
                if(num>MAX_STUDENT_NUM){
                    printf("Exceeds the maximum\n");
                    continue;
                }
                res=Insert(a,num);
                if(res==2){
                    printf("success!\n");
                }else{
                    printf("false!\n");
                }
                break;
            case 2:
                printf("input the student id you want to del:\n");
                scanf("%d",&student_id);
                fflush(stdin);
                res=Search(a,student_id);
                if(res==-1){
                    printf("the student is not exist\n");
                }else{
                    Delete(a,res);
                    num=num-1;
                }
                break;
            case 3:
                printf("input the student number you want to search\n");
                scanf("%d",&student_id);
                fflush(stdin);
                res=Search(a,student_id);
                if(res==-1){
                    printf("the student is not exist\n");
                }else{
                    printf("该学生位于：%d\n",res);
                }
                break;
            case 4:
                PrintLine(a,num);
                break;
            case 5:
                return 0;
            case 6:
                printf("输入你要查找的学生的 id\n");
                scanf("%d",&student_id);
                fflush(stdin);
                InsertionSort(a,num);
                res=BinSearch(a,student_id,num);
                if(res==-1){
                    printf("the student is not exist\n");
                }else{
                    printf("该学生位于：%d\n",res);
                }
                break;
            default :
                printf("input error!\n");
                break;
        }


    }



}
int Insert(STUDENT student[],int num){
    int i;
    int res;
    for(i=0;i<=num-1;i++){
        printf("input the student id:\n");
        res=scanf("%d",&student[i].id);
        fflush(stdin);
        if(res==0){
            printf("error!input again\n");
            res=scanf("%d",&student[i].id);
        }
        printf("input the student name:\n");
        scanf("%s",&student[i].name);
        printf("input the student phone\n");
        scanf("%d",&student[i].phone);
        fflush(stdin);
        if(res==0){
            printf("error!input again\n");
            res=scanf("%d",&student[i].id);
        }

    }
    return 2;
}
void PrintLine(STUDENT student[],int num){
    int i;
    if(num==0){
        printf("the student array is null\n");
    }else{
        for(i=0;i<num;i++){

            printf("学号:%d,名字:%s,电话:%d",student[i].id,&student[i].name,student[i].phone);
            printf("\n");

        }


    }
}
int Search(STUDENT student[],int student_id){
    int i;
    for(i=0;i<=MAX_STUDENT_NUM;i++){
        if(student[i].id==student_id){
            return i+1;
        }
    }
    return -1;
}
void InsertionSort(STUDENT student[],int n)
{
    
    for (int i = 0; i < n; i++)
    {
        int temp=student[i].id;
        int j;
        for ( j = i-1; j >= 0&&student[j].id>temp; j--)
        {
            student[j+1].id=student[j].id;
        }
        student[j+1].id=temp;
        
    }
    return;
    
}
int BinSearch(STUDENT student[],int student_id,int num )
{
    int low=0;
    int high=num-1;
    int mid;

    while (low<=high)
    {
      
        mid=low+(high-low)/2;
        if (student_id>student[mid].id)
        {
            low=low+1;
        }
        else if (student_id<student[mid].id)
        {
            high=high-1;
        }
        else return mid;
    }
    return -1;
}

int Delete(STUDENT student[],int student_id){
    int j;
    for(j=student_id;j<=MAX_STUDENT_NUM;j++){
            student[j-1].id=student[j].id;
            student[j-1].name=student[j].name;
            student[j-1].phone=student[j].phone;
        }
    printf("success!\n");
    return 1;

}
