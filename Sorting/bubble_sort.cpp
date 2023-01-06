// in bubble sort we compare the adjacent number and if it was illegal then we swap them
#include <iostream>
using namespace std;
void printing(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void bubble_sort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
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
        cout << "enter the number: ";
        cin >> a[i];
    }
    printing(a, n);
    bubble_sort(a, n);
    printing(a, n);

    return 0;
}