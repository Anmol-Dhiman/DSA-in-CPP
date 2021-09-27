#include <iostream>
using namespace std;

void traversal(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubble(int a[], int n)
{
    int s = n - 1;
    for (int i = 0; i < n - 1; i++)
    {
        int c = 1;
        for (int j = 0; j < s; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                c = 0;
            }
        }
        s--;
        if (c == 1)
        {
            return;
        }
    }
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
    traversal(arr, n);
    bubble(arr, n);
    traversal(arr, n);
    return 0;
}