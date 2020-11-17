#include"stdio.h"
#include<vector>
#include<iterator>
#include<algorithm>
#include<iostream>
using namespace std;
int a[100000];
int b[100000];
int x[1000];
int L[1000];
int R[1000];
int sum[1000];
int main()
{
	int n,m,i,j,temp;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&x[i],&L[i],&R[i]);
		for(j=L[i]-1;j<R[i];j++)
		{
			sum[i] = sum[i] + a[j];
		}
        
	if(x[i]%2!=0)
		{
		for(i=0;i<n/2;i++)
		{
			temp = a[i];
			a[i] = a[n-1-i];
			a[n-1-i] = temp;
			}
		}
	//fan
	vector<int>a(i);
    vector<int> :: iterator out;
    reverse(a.begin(),a.end());
     for(out=a.begin();out!=a.end();++out){
        cout<<*out<<" ";//指向元素值
    }

	}
	for(i=0;i<m;i++)
	{
	printf("%d\n",sum[i]);
	}


}