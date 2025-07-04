#include <iostream>
using namespace std;

int partition(int arr[], int size, int e)
{

    int pivot = arr[size];

    int cnt = 0;
    for (int i = size + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }

    int pivotIndex = size + cnt;
    swap(arr[pivotIndex], arr[size]);

    int i = size, j = e;

    while (i < pivotIndex && j > pivotIndex)
    {

        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int size, int e)
{

    if (size >= e)
        return;

    int p = partition(arr, size, e);

    quickSort(arr, size, p - 1);

    quickSort(arr, p + 1, e);
}
void find(int *ar, int k)
{
    cout << "k is " << k << "s,Therefore the smallest element in array is: " << ar[k - 1] << endl;
}

int main()
{

    int arr[6] = {5, 7, 32, 6, 76, 21};
    int n = 6;

    cout << "The sorted array is:" << endl;
    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int k;
    cout << "enter the value of k" << endl;
    cin >> k;
    find(arr, k);

    return 0;
}