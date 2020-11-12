//利用STL模板实现元素的逆置

#include<iostream>
#include<functional>
#include<vector>
#include<iterator>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    vector<int>v(3);
    v[0]=1;
    v[1]=2;
    v[2]=3;
    vector<string>a(2);
    a[0]="aaa";
    a[1]="bbb";
    vector<string>::iterator out2;
    vector<int> ::iterator out;
    for(out=v.begin();out!=v.end();++out){
        cout<<*out<<" ";//指向元素值
        
    }
    for (out2=a.begin();out2!=a.end();++out2)
    {
        cout<<*out2<<" ";
    }
    
    cout<<endl<<endl;
    reverse(v.begin(),v.end());
    reverse(a.begin(),a.end());
    for (int i = 0; i < 3; i++)
    {
        /* code */
        cout<<v[i]<<" ";
       
    }
    for (out2= a.begin();out2!=a.end() ;out2++)
    {
        cout<<*out2<<" ";
    }
    
    return 0;

}   
