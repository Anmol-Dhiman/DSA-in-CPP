#include <iostream>
using namespace std;
void swaping(int a[], int left, int right)
{
    int temp = a[left];
    a[left] = a[right];
    a[right] = temp;
}
void waveSort(int a[], int n)
{
    for (int i = 1; i < n - 1; i+=2)
    {
        if (a[i - 1] < a[i])
        {
            swaping(a, i - 1, i);
        }
        if (a[i] > a[i + 1] && i <= n - 2)
        {
            swaping(a, i, i + 1);
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
    waveSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}