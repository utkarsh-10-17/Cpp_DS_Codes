#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid = (start + end) / 2;

    while (start <= end)
    {
        if (key == arr[mid])
        {
            return mid;
        }
        if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

        mid = (start + end) / 2;
    }
    return -1;
}

int main()
{

    int even[6] = {12, 34, 56, 76, 98, 99};
    int odd[5] = {1, 2, 3, 4, 5};

    int evenindex = binarySearch(even, 6, 76);

    cout << "Index found at:" << evenindex << endl;

    int oddindex = binarySearch(odd, 5, 5);

    cout << "Index found at:" << oddindex << endl;

    return 0;
}