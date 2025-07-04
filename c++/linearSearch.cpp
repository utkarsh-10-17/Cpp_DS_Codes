#include <iostream>
using namespace std;

// linear search

bool Search(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return 1;
        }
    }
    return 0;
}

// Array reverse
void Reverse(int arr[], int size)
{
    int start = 0;
    int end = size - 1;

    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// Print Array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{

    int nigg[6] = {1, 23, 54, 55, 65, 64};

    int key;

    cout << "Enter the element to be searched" << endl;
    cin >> key;

    bool found = Search(nigg, 6, key);

    if (found)
    {
        cout << "element is present" << endl;
    }
    else
    {
        cout << "Element is not present" << endl;
    }

    int okrr[5] = {1, 43, 65, 45, 23};

    Reverse(okrr, 5);
    printArray(okrr, 5);

    return 0;
}
