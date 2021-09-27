#include <iostream>
using namespace std;

void swaping(int a[], int low, int mid)
{
    int temp = a[low];
    a[low] = a[mid];
    a[mid] = temp;
}

void DnfSort(int a[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while (mid != high)
    {
        if (a[mid] == 0)
        {
            swaping(a, low, mid);
            low++;
            mid++;
        }
        else if (a[mid] = 1)
        {
            mid++;
        }
        else
        {
            swaping(a, high, mid);
            high--;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    DnfSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}