#include <iostream>
using namespace std;

class array
{
public:
    int input[100], count, i, num;
    void inputData()
    {
        cout << "Enter Number of Elements in Array\n";
        cin >> count;

        cout << "Enter " << count << " numbers \n";
    }

    void displaydata()
    {
        for (i = 0; i < count; i++)
        {
            cin >> input[i];
        }
    }

    void searchNo()
    {

        for (i = 0; i < count; i++)
        {
            if (input[i] == num)
            {
                cout << "Element found at index " << i << endl;
            }
        }

        if (i != count)
        {
            cout << "Element Not Present in Input Array\n";
        }
    }
    void sortAscending()
    {
        int index_1, index_2, temp;

        for (index_1 = 0; index_1 <= 4; index_1++)
        {

            for (index_2 = 0; index_2 < 4 - index_1; index_2++)
            {

                if (input[index_2] > input[index_2 + 1])
                {

                    temp = input[index_2];
                    input[index_2] = input[index_2 + 1];
                    input[index_2 + 1] = temp;
                }
            }
        }
    }

    void sortDescending()
    {
        int index_1, index_2, temp;

        for (index_1 = 0; index_1 <= 4; index_1++)
        {

            for (index_2 = 0; index_2 < 4 - index_1; index_2++)
            {

                if (input[index_2] < input[index_2 + 1])
                {

                    temp = input[index_2];
                    input[index_2] = input[index_2 + 1];
                    input[index_2 + 1] = temp;
                }
            }
        }
    }

    int maxN0()
    {

        int max = input[0];

        for (int index = 1; index <= 4; index++)
        {

            if (input[index] > max)
            {
                max = input[index];
            }
        }

        return max;
    }

    int minNo()
    {
        int min = input[0];

        for (int index = 1; index <= 4; index++)

            if (input[index] > min)
            {
                min = input[index];
            }
        return min;
    }
    void merge(int *arr, int s, int e)
    {
        int mid = (s + e) / 2;

        int len1 = mid - s + 1;
        int len2 = e - mid;

        int *first = new int[len1];
        int *second = new int[len2];

        int mainArrayindex = s;
        for (int i = 0; i < len1; i++)
        {
            first[i] = arr[mainArrayindex++];
        }

        int k = mid + 1;
        for (int i = 0; i < len2; i++)
        {
            second[i] = arr[mainArrayindex++];
        }

        int index1 = 0;
        int index2 = 0;
        mainArrayindex = s;
    }

    void mergeSort(int *arr, int s, int e)
    {
        if (s > e)
        {
            return;
        }
    }
};

int main()
{
    array A;
    A.inputData();
    A.displaydata();
    A.searchNo();
    A.maxN0();
    cout << "the maximum number is:" << endl;
    A.minNo();
    cout << "the minimum number is:" << endl;
    A.sortAscending();
    cout << "the sorted array is: " << endl;
    A.sortDescending();
    cout << "the sorted array is:" << endl;

    return 0;
}
