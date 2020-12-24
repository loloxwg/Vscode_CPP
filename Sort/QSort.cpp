
int Partition(int score[],int low,int high);
void QSort (int scroe[],int m);


int Partition(int score[],int low ,int high)
{
    int pivotkey;
    // score[0]=score[low];
    pivotkey=score[low];
    while (low<high)
    {
        while (low<high&&score[high]>=pivotkey) 
        {
            high--;
        }
        if (low<high)
        {
            score[low]=score[high];
        }
        while (low<high&&score[low]<=pivotkey)
        {
            low++;
            
        }
        if (low<high)
        {
            score[high]=score[low];
        }
        
    }
    score[low]=pivotkey;
    return low;
}

void QSort (int score[],int low,int high)
{
    int pivotloc;
    if (low<high)
    {
        pivotloc=Partition(score,low,high);
        QSort(score,low,pivotloc-1);
        QSort(score,pivotloc+1,high);

    }
    
}

