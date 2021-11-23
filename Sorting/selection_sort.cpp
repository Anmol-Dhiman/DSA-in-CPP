// int selection sort we find the minimum element and place it into the first position
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
void selection_sort(int a[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_index])
            {
                min_index = j;
            }
        }
        swap(a[i], a[min_index]);
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
    selection_sort(a, n);
    printing(a, n);
    return 0;
}