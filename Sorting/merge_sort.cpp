#include <iostream>
using namespace std;

void printing(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void merger(int a[], int low, int mid, int high)
{
    int b[high + 1];
    int i = low;
    int j = mid + 1;
    int k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        k++;
        j++;
    }

    for (int i = 0; i <= high; i++)
    {
        a[i] = b[i];
    }
}
void merger_sort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int mid = (low + high) / 2;
    merger_sort(arr, low, mid);
    merger_sort(arr, mid + 1, high);
    merger(arr, low, mid, high);
}
int main()
{
    int arr[] = {2, 1, 3, 9, 4, 4, 8, 7, 5, 6};
    int n = 10;
    // printing before the sorting
    printing(arr, n);
    merger_sort(arr, 0, n - 1);
    // printing after sorting
    printing(arr, n);
    return 0;
}