#include<iostream>

using namespace std;

void CallBySimulating(int *par);

int main(){
    int arg=1;
    cout<<"arg="<<arg<<endl;
    CallBySimulating(&arg);
    cout<<"arg="<<arg<<endl;
    return 0;
}

void CallBySimulating(int *par)
{
    cout<<"par="<<*par<<endl;
    *par=2;
}