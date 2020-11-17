#include"stdio.h"
#include"string.h"

char a[]="search";
char b[]="spread";
char c[]="self";
char str[10];
int shu[100000];
int A()
{
		int i,n,number=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
		  scanf("%s",str);
		  if(strcmp(a,str)==0)
		  {
			number=number+4;
			continue;
		  }	
		  else if(strcmp(b,str)==0)
		  {
				number=number+2; 
				continue;
			
		  
		  }
		  else if(strcmp(c,str)==0)
		  {
				number=number+0; 
				continue;
		  }
			
		}

		return number;


}
int main()
{ 
	int T,i;
	scanf("%d",&T);
	   for(i=0;i<T;i++)
	   {
			shu[i] = A();	
	   }
	   for(i=0;i<T;i++)
	   {
	        printf("%d\n",shu[i]);	
	   }	
}
