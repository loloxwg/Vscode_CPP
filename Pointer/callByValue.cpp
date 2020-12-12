#include<iostream>
using namespace std;
void FunNo(int par);
int FunYes(int par);
int main ()
{
    int arg =1;
    cout<<"arg="<<arg<<endl;
    // FunNo(arg);
    arg=FunYes(arg);
    cout<<"arg="<<arg<<endl;
    return 0;
}

//传不成
void FunNo(int par)
{
    cout<<"par="<<par<<endl;
    par=2;
}
//传成功
int FunYes(int par)
{
    cout<<"par="<<par<<endl;
    par=2;
    return par;
}