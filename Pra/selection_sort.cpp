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
void sorting(int a[], int n)
{
    int mid;
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        mid = i;
        for (int j = i; j < n; j++)
        {
            if (a[j] < a[mid])
            {
                mid = j;
            }
        }
        temp = a[i];
        a[i] = a[mid];
        a[mid] = temp;
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
    sorting(arr, n);
    traversal(arr, n);
    return 0;
}