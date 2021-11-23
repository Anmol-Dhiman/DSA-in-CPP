// in insertion sort we compare the elemets form the back and move them into right side if the condition is illegal
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
void insertion_sort(int a[], int n)
{
    int key;
    int j;
    for (int i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
int main()
{
    int n;
    cout << "enter the number of value: ";
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    printing(a, n);
    insertion_sort(a, n);
    printing(a, n);
    return 0;
}