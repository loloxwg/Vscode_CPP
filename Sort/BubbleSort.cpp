//冒泡排序

void BubbleSort(int score[],int n);
void BubbleSort(int score[],int n)
{
    int i ,j ,temp;
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n-i; j++)
        {
            if (score[j]<score[j-1])
            {
                temp=score[j];
                score[j]=score[j-1];
                score[j-1]=temp;
            }
            
        }
        
    }
    
}