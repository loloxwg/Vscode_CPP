//冒泡排序

void BubbleSort(int score[],int n);
void FastBubbleSort(int score[],int n);

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

//加速版冒泡排序
void FastBubbleSort(int score[],int n)
{
    int i ,j ,temp;
    for ( i = 0; i < n; i++)
    {
        bool isSorted=true;//

        for ( j = 0; j < n-i; j++)
        {
            if (score[j]<score[j-1])
            {
                temp=score[j];
                score[j]=score[j-1];
                score[j-1]=temp;

                isSorted=false;//
            }
            
        }
        if (isSorted)
        {
            break;
        }
        
        
    }
    
}


//冒泡排序超级加倍

void FFFastBubbleSort (int score[],int n)
{
    int i,j,temp;
    int LastExchangeIndex=0;//
    int sortBorder=n-1;//
    for ( i = 0; i < n-1; i++)//
    {
        bool isSorted =true;
        for ( j = 0; j < sortBorder; j++)//
        {
            if (score[j]<score[j-1])
            {
                temp=score[j];
                score[j]=score[j-1];
                score[j-1]=temp;
                isSorted=false;
                LastExchangeIndex=j;//
            }
            sortBorder=LastExchangeIndex;//

            if (isSorted)
            {
                break;    
            }
            
            
        }
        
    }
    
}