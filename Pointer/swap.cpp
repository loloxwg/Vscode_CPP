#include <iostream>
using namespace std;
//地址传递
void swap1(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
    cout << "inFun "
         << "*x=" << *x << " *y=" << *y << endl;
    cout << "inFun "
         << "x=" << x << " y=" << y << endl;
}
/*
before 2 3
before &a=0x61fe1c &b=0x61fe18 
inFun *x=3 *y=2
inFun x=0x61fe1c y=0x61fe18    
after 3 2
after &a=0x61fe1c &b=0x61fe18
*/



//引用传递
void swap2(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
    cout << "inFun "
         << "x=" << x << " y=" << y << endl;
    cout << "inFun "
         << "&x=" << &x << " &y=" << &y << endl;
}
/*
before 2 3
before &a=0x61fe1c &b=0x61fe18
inFun x=3 y=2
inFun &x=0x61fe1c &y=0x61fe18
after 3 2
after &a=0x61fe1c &b=0x61fe18
*/
int main()
{
    int a, b;
    a = 2;
    b = 3;
    cout << "before " << a << " " << b << endl;
    cout << "before "
         << "&a=" << &a << " &b=" << &b << endl;
    // swap1(&a,&b);
    swap2(a, b);
    cout << "after " << a << " " << b << endl;
    cout << "after "
         << "&a=" << &a << " &b=" << &b << endl;
}