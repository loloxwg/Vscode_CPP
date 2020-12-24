#include <iostream>
using namespace std;
#include "QSort.cpp"
#include "BubbleSort.cpp"
#include "SelectionSort.cpp"
#include "InsertionSort.cpp"
#define N 5

void InputArray(int score[])
{
    cout << "����Ҫ���������" << endl;
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
        cout << "ѡ������㷨" << endl;
        cout << "1.ѡ������" << endl;
        cout << "2.ð������" << endl;
        cout << "3.��������" << endl;
        cout << "4.��������" << endl;
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
        cout << "����ָ�ԭ����" << endl;
        a[N] = temp[N];
        cout << endl;
    }

    return 0;
}
