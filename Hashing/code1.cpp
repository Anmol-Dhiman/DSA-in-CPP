#include <iostream>
using namespace std;
void printing_array(int arr[], int len)
{
    cout << "[";
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]";
    cout << endl;
}
int counting_violation(int a[], int len, int index, int count)
{
    if (index == len)
    {
        return count;
    }
    int temp = a[index];
    for (int i = index + 1; i < len; i++)
    {
        if (temp > a[i])
        {
            count++;
        }
    }
    return counting_violation(a, len, index + 1, count);
}
int main()
{
    int n;
    cout << "Enter the number of input: ";
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the number: ";
        cin >> a[i];
    }
    printing_array(a, n);
    cout << "The number of violation is : " << counting_violation(a, n, 0, 0);
    return 0;
}
