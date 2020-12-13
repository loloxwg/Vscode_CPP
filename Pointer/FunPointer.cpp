#include<iostream>
using namespace std;
void Fun (int x ,int y,int (*f)(int ,int));

int Max(int x ,int y);
int Min(int x ,int y);
int Add(int x ,int y);

int main ()
{
    int a ,b;
    cin>>a>>b;
    Fun(a,b,Max);
    Fun(a,b,Min);
    Fun(a,b,Add);

}
void Fun(int x,int y,int(*f)(int,int))
{
    int result;
    result=(*f)(x,y);
    cout<<result<<endl;
}

int Max (int x,int y)
{
    cout<<"max=";
    return x>y?x:y;
}

int Min(int x,int y)
{
    cout<<"min=";
    return  x<y?x:y;
}

int Add (int x,int y)
{
    cout<<"sum=";
    return x+y;

}