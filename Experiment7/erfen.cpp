#include<stdio.h>
#include<iostream>
using namespace std;
int binary_Search(int array[],int n ,int target){
    int low=0;
    int high=n-1;
    int mid;
    while (low<=high) {
        mid = (low + high) / 2;
        if (array[mid] == target){
            return mid;
        } else if (array[mid]>target){
            high=mid-1;
        } else{
            low=mid+1;
        }
    }
    return -1;
}

int main (){
    int i;
    int pos;
    int n=15;
    int a[n];
    int target;
    printf("请输入15个数：\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);    //输入由小到大的15个数

    cout<<"请输入查找的值";
    cin>>target;
    //接收值
    pos=binary_Search( a, n , target);
    
    if (pos==-1)
    {
        cout<<"没找到";

    }else
    {
        cout<<pos+1;
    }

}