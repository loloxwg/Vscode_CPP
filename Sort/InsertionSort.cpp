//直接插入
#include<iostream>
using namespace std;
void InsertionSort(int score[],int n);

void InsertionSort(int score[],int n)
{
    
    for (int i = 0; i < n; i++)
    {
        int temp=score[i];
        int j;
        for ( j = i-1; j >= 0&&score[j]>temp; j--)
        {
            score[j+1]=score[j];
        }
        score[j+1]=temp;
        
    }
    return;
    
}
void InsertionSort2(int score[],int n)
{
    int i ,j;
    int temp;
    for (i = 1; i < n; i++)
    {
        if (score[i]<score[i-1])
        {
            temp=score[i];
            
            for ( j = i-1; temp<score[j];j--)
            {
                score[j+1]=score[j];
            }
            score[j+1]=temp;      
            
        }          
    }
    
}
void InsertionSort3(int score[],int n)
{
    int i ,j;
    for ( i = 2; i < n; i++)
    {
        if (score[i]<score[i-1])
        {
            score[0]=score[i];
            score[i]=score[i-1];
            for ( j = i-2; score[0]<score[j]; i++)
            {
                score[j+1]=score[j];
            }
            score[j+1]=score[0];
        }
        
    }
    
}
int main ()
{
    int a[]={9,7,3,4,5};
    InsertionSort(a,5);
    for (int i = 0; i < 5; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}