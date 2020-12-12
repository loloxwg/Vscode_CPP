//选择排序

void SelectionSort(int score[],int n);


void SelectionSort(int score[],int n)
{
    int i ,j ,k,temp;
    for ( i = 0; i < n; i++)
    {
        k=i;
        for ( j = i+1; j < n; j++)
        {
            if (score[j]<score[k])/**/
            {
                k=j;      /*记录最小数下标位k置*/
            }
            
        }
        if (k!=i)         /*若中记录的最小数不在下标i位置*/
        {
            temp =score[k];
            score[k]=score[i];
            score[i]=temp;
        }
        
    }
    
}