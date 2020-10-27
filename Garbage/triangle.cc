// 一个三角形的三边长分别是 aa、bb、cc，那么它的面积为 \sqrt{p(p-a)(p-b)(p-c)} 
// 开根号{p(p−a)(p−b)(p−c)}
//  ，其中 p=\frac{1}{2}(a+b+c)=1/2(a+b+c)
//输入这三个数字，计算三角形的面积，四舍五入精确到 1 位小数。

// 保证能构成三角形，0\leq a,b,c\leq 10000≤a,b,c≤1000，每个边长输入时不超过2位小数
#include<bits/stdc++.h>
using namespace std;
double a,b,c,p,ans;
int main()
{
	cin>>a>>b>>c;
	p=(a+b+c)/2;
	ans=sqrt(p*(p-a)*(p-b)*(p-c));
	printf("%.1lf",ans);
	return 0;
}