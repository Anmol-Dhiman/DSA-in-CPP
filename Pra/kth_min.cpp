#include <iostream>
using namespace std;
void kth_max(int a[], int n, int k)
{
    int temp = a[0];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (a[j] < temp)
            {
                a[j] = INT_MAX;
            }
        }
    }
    for (int j = 1; j < n; j++)
    {
        if (a[j] < temp)
        {
            a[j] = INT_MAX;
        }
    }
    cout << temp;
}
int main()
{
    int a[] = {7, 4, 3, 10, 20, 12};
    kth_max(a, 6, 3);
    return 0;
}