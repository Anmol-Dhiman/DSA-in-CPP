// total number of subarray in an array of n elements are (n*(n+1))/2
#include <iostream>
using namespace std;

void subarray_sum_print(int arr[], int n)
{
    int sum;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            cout << sum << " ";
        }
    }
}

int main()
{
    int n;
    cout << "enter the number of input: ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    subarray_sum_print(a, n);
    return 0;
}