#include <iostream>
using namespace std;

void printarray(int arr[], int n)
{
    cout << "printing the array" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void SwappAlternate(int arr[], int n)
{
    for (int i = 0; i < n; i += 2)
    {
        swap(arr[i], arr[i + 1]);
    }
}

int main()
{
    int rho[6] = {1, 2, 3, 4, 5, 6};

    SwappAlternate(rho, 6);
    printarray(rho, 6);

    return 0;
}