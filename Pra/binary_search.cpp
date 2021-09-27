#include <iostream>
using namespace std;

int binary_search(int n, int arr[], int key)
{
    int front = 0;
    int end = n - 1;
    int mid;
    while (front <= end)
    {
        mid = (front + end) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            front = mid + 1;
        }
    }
    return -1;
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
    int key;
    cin >> key;
    int k = binary_search(n, arr, key);
    if (k >= 0)
    {
        cout << key << " is present at the index " << k;
    }
    else
    {
        cout << key << " is not present in the array";
    }

    return 0;
}