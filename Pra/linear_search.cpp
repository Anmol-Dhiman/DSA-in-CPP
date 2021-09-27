#include <iostream>
using namespace std;

int linear_search(int n, int arr[], int key)
{
    for (int i = 0; i < n; i++)
    {
        if (key == arr[i])
        {
            return i;
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
    int k = linear_search(n, arr, key);
    if (k >= 0)
    {
        cout << key << " is in the array at index " <<k;
    }
    else{
        cout<<key<<" is not present in the array.";
    }

    return 0;
}