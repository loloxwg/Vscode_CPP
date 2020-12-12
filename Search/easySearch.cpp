/*
最高分，最高分对应下标
*/
#include<stdio.h>
#include<iostream>
#define N 40
using namespace std;
int FindMaxIndex(int x[],int n);
int FindMaxValue (int x[],int n);
void ReadScore1(int score[],int n);
int ReadScore2(int score[]);

int FindMaxIndex(int x[],int n)
{
    int maxIndex,i;
    maxIndex=0;
    for ( i = 0; i < n; i++)
    {
        if (x[i]>x[maxIndex])
        {
            maxIndex=i;
        }
    }
    return maxIndex;
}
int FindMaxValue(int x[],int n)
{
    int maxValue ,i;
    maxValue=x[0];
    for ( i = 0; i < n; i++)
    {
        if (x[i]>maxValue)
        {
            maxValue=x[i];
        }
    }
    return maxValue;
}

void ReadScore1 (int score[],int n)
{
    int i;
    cout<<"\nplease input score: ";
    for ( i = 0; i < n;i++)
    {
        cin>>score[i];
    }
}


int ReadScore2(int score[])
{
    int i = -1;
    do
    {
        i++;
        cout<<"\nplease input score:";
        cin>>score[i];
    } while (score[i]>=0);
    return i;
}

int main (){
    int score[N],maxValue,maxIndex,n;
    n=ReadScore2(score);
    printf("Total students are %d\n",n);
    maxValue=FindMaxValue(score,n);
    cout<<"\nThe highest score is"<<maxValue;
    maxIndex=FindMaxIndex(score,n);
    cout<<"\nscore["<<maxIndex<<"]"<<"is the highest:"<<score[maxIndex];
    cout<<endl;
    return 0;
}