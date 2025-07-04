#include <iostream>
using namespace std;

class array
{
private:
    int n;
    int a[100];

public:
    void inputdata()
    {
        cout << "Enter the size of array" << endl;
        cin >> n;
        cout << "Enter the elements of array" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
    }
    void displayData()
    {
        cout << "The array is " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    void SearchNo()
    {
        int p;
        cout << "enter the number you wanted to search " << endl;
        cin >> p;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == p)
            {
                cout << "The number is at index " << i << endl;
            }

            else
            {
                cout << "The number was not found in the array " << endl;
            }
        }
    }
    void maxNo()
    {
        int max = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > max)
            {
                max = a[i];
            }
        }
        cout << "The max number in the array is " << max << endl;
    }
    void minNo()
    {
        int min = 999;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < min)
            {
                min = a[i];
            }
        }
        cout << "The min number in the array is " << min << endl;
    }
    void AsdOrder()
    {
        int temp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; (j + 1) < (n - i); j++)
            {
                if (a[j] > a[j + 1])
                {
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
        cout << "The Asd order array is " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    void DesOrder()
    {
        int tem;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; (j + 1) < (n - i); j++)
            {
                if (a[j] < a[j + 1])
                {
                    tem = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = tem;
                }
            }
        }
        cout << "The Des Order of Array is " << endl;
        for (int j = 0; j < n; j++)
        {
            cout << a[j] << " ";
        }
    }

    void betwnNo()
    {
        
    }
};
int main()
{
    array A;
    A.inputdata();
    A.displayData();
    A.SearchNo();
    A.maxNo();
    A.minNo();
    A.AsdOrder();
    A.DesOrder();
    return 0;
}
