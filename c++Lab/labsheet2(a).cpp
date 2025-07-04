#include <iostream>
using namespace std;

void merge(int A[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int B[100];

    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    while (i <= mid)
        B[k++] = A[i++];
    while (j <= h)
        B[k++] = A[j++];

    for (i = l; i <= h; i++)
        A[i] = B[i];
}
void mergesort(int ar[], int ll, int hh)
{
    int mid;
    if (ll >= hh)
        return;
    mid = (ll + hh) / 2;
    mergesort(ar, ll, mid);
    mergesort(ar, mid + 1, hh);
    merge(ar, ll, mid, hh);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergesort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}