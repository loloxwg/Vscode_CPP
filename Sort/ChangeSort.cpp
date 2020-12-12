//交换排序法

void ChangeSort(int score[],int n)
{
    int i ,j,temp;
    for ( i = 0; i < n-1; i++)
    {
        for ( j = i+1; j < n; j++)
        {
            if (score[j]<score[j-1])// <升序
            {
                temp=score[j];
                score[j]=score[j-1]; 
                score[j-1]=temp;
            }
            
        }
        
    }
    
}