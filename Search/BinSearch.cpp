int BinSearch(long num[],long x ,long n);
/*-------------二分查找---------------------*/
//最多所需比较次数是第一个大于表中元素个数的2的幂次数
//必须是有序表
int BinSearch(long num[],long x ,long n)
{
    int low=0;
    int high=n-1;
    int mid;

    while (low<=high)
    {
        // mid=(high+low)/2;
        //防御式编程实现防止在加法运算low+high溢出
        //这里改写成减法
        //如果数组很大，low+high的和大于有符号整数的极限值
        //就会发生溢出，使mid成为一个负数
        mid=low+(high-low)/2;
        if (x>num[mid])
        {
            low=low+1;
        }
        else if (x<num[mid])
        {
            high=high-1;
        }
        else return mid;
    }
    return -1;
}
