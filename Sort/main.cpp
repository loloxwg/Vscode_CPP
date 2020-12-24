#include <iostream>
using namespace std;
#include "QSort.cpp"
#include "BubbleSort.cpp"
#include "SelectionSort.cpp"
#include "InsertionSort.cpp"
#define N 5

void InputArray(int score[])
{
    cout << "输入要排序的序列" << endl;
    for (int i = 0; i < N; i++)
    {

        cin >> score[i];
    }
}
void OutputArray(int score[])
{
    for (int i = 0; i < N; i++)
    {
        cout << score[i] << " " << endl;
    }
}
int main()
{
    // int low=0;
    // int high=N;
    int a[N];
    int temp[N];
    int selection;
    InputArray(a);
    temp[N] = a[N];
    while (1)
    {
        cout << "选择你的算法" << endl;
        cout << "1.选择排序" << endl;
        cout << "2.冒泡排序" << endl;
        cout << "3.快速排序" << endl;
        cout << "4.插入排序" << endl;
        cin >> selection;
        cout << endl;
        switch (selection)
        {
        case 1:
            SelectionSort(a, N);
            break;
        case 2:
            BubbleSort(a, N);
            break;
        case 3:
            QSort(a, 0, N - 1);
            break;
        case 4:
            InsertionSort(a, N);
        default:
            break;
        }

        OutputArray(a);
        cout << "数组恢复原序列" << endl;
        a[N] = temp[N];
        cout << endl;
    }

    return 0;
}
