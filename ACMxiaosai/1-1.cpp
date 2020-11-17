#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<cstring>
using namespace std;



int main(){
    
    int n;
    
    char x[10];
    char a[]="spearch";
    char b[]="spread";
    char c[]="self";
    int sum =0;
    
    
    cin>>n;
    
    for (int  i = 0; i < n; i++)
    {
        cin>>x;
        if (strcmp(x,a)==0)
        {
            sum+=2;
            continue;
        }
        else if (strcmp(x,b)==0)
        {
            sum+=4;
            continue;
        }
        else if(strcmp(x,c)==0)
        {
            sum+=0;
            continue;
        }
        return sum;
    }

    for (int i = 0; i < n; i++)
    {
        
        
    }
    

    cout<<sum;
    
    //  if (x[i]=="search")
    //     {
    //         sum+=4;
    //     }
    //     if (x[i]=="spread")
    //     {
    //         sum+=2;
    //     }
    //     else sum+=0;
    //     return sum;
    
    
    

    
}