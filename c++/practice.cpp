/*#include <iostream>
using namespace std;

bool search(int arr[], int size, int key)
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

int main()
{

    int arr[10] = {32, 65, 23, 67, 25, 98, 56, 34, 2, 11};

    cout << "enter the element you want to find " << endl;
    int key;
    cin >> key;

    bool found = search(arr, 10, key);

    if (found)
    {
        cout << "key is present " << endl;
    }
    else
    {
        cout << "key is absent " << endl;
    }

    return 0;
} */

/*#include<iostream>
using namespace std;

void print(int arr[] , int n)
{
    for(int i = 0 ; i< n ; i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;

}

void reverse(int arr[] , int n)
{
    int start = 0;
    int end = n -1;

    while(start <= end)
    {
        swap(arr[start],arr[end]);
        start++;
        end--;
    }

}

int main(){

    int arr[6] = {1,4,5,7,8,9};
    int brr[5] = {4,8,42,9,1};

    reverse(arr,6);
    reverse(brr,5);

    print(arr,6);
    print(brr,5);


return 0;
}*/

/*#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key)
{
    int start = 0;
    int end = n - 1;
    int mid = (start + end) / 2;

    while (start <= end)
    {
        if (arr[mid] == key)
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

    int even[6] = {1, 4, 5, 7, 8, 9};
    int odd[5] = {4, 8, 42, 9, 1};

    int eveIndex = binarySearch(even, 6, 7);

    cout << "index of 7 is " << eveIndex << endl;

    int oddIndex = binarySearch(odd, 5, 42);
    cout << "index of 42 is " << oddIndex << endl;

    return 0;
}*/

// sorting

/*#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

void BubbleSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

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
            }
            else
            {
                break;
            }

            j--;
        }
        arr[j + 1] = temp;
    }
}

void merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // copy values
    int mainArrayIndex = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }
    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

    // Merge 2 sorted arrays

    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
            arr[mainArrayIndex++] = second[index2++];
    }

    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }

    while (index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }
}

void MergeSort(int *arr, int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }

    int mid = (s + e) / 2;

    // left wala part sort karna
    MergeSort(arr, s, mid);
    // right wala part sort karna
    MergeSort(arr, mid + 1, e);

    // Merge
    merge(arr, s, e);
}

int partition(int arr[], int s, int e)
{
    int pivot = arr[s];
    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }

    // place pivot at right position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    // left and right wala part sambhalna
    int i = s, j = e;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] < pivot)
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

void quickSort(int arr[], int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }

    // partition
    int p = partition(arr, s, e);

    // left part sort karo
    quickSort(arr, s, p - 1);

    // right part sort karo
    quickSort(arr, p + 1, e);
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{

    int brr[10] = {32, 65, 23, 67, 25, 98, 56, 34, 2, 11};
    int n = 10;

    //  cout<<"The sorted array is: "<<endl;
    //  selectionSort(brr, 10);
    //  print(brr, 10);

    // cout<<"The sorted array is: "<<endl;
    // BubbleSort(brr, 10);
    // print(brr, 10);

    // cout << "The sorted array is: " << endl;
    // InsertionSort(brr, 10);
    // print(brr, 10);

    // cout << "The sorted array is: " << endl;
    // MergeSort(brr, 0, 9);
    // print(brr, 10);

    cout << "The sorted array is: " << endl;
    quickSort(brr, 0, n - 1);
    print(brr, n);

    return 0;
}*/
