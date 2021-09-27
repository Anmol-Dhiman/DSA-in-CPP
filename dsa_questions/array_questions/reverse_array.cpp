// it's time complexity is O(n)

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

void reverse(int arr[], int n)
{
    // just swaping the last and the first elements until we reach to the middle point
    int front_index = 0;
    int last_index = n - 1;
    int temp;
    for (front_index = 0; front_index < n / 2; front_index++)
    {
        temp = arr[front_index];
        arr[front_index] = arr[last_index];
        arr[last_index] = temp;
        last_index--;
    }
}
// void rvereseArray(int arr[], int start, int end)
// {
//     while (start < end)
//     {
//         int temp = arr[start];
//         arr[start] = arr[end];
//         arr[end] = temp;
//         start++;
//         end--;
//     }
// }

// recursive function of reversing an array

void reverse_recursive(int arr[], int start, int end)
{
    if (start == end)
    {
        return;
    }
    reverse_recursive(arr, start + 1, end - 1);
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
}

int main()
{
    int n;
    cout << "enter the number of inputs:";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    traversal(a, n);
    reverse_recursive(a, 0, n - 1);
    // reverse(a, n);
    traversal(a, n);
    return 0;
}