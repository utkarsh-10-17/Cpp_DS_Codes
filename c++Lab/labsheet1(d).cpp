#include<iostream>
using namespace std;
 
// InsertionSort

void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;

        while (j >= 0)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            else
            {
                break;
            }
        }

        arr[j + 1] = temp;
    }
}

// printing array

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{

    int jeff[5] = {23, 56, 32, 52, 5};

    InsertionSort(jeff, 5);
    printArray(jeff, 5);

    return 0;
}