#include <iostream>
#include <algorithm>
using namespace std;
bool search(int a[], int key)
{
    sort
}
void func()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    int Y;
    cin >> Y;
    int a[n];
    a[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int curr = a[i - 1] - i;
        int j;
        for (j = 0; j < i; j++)
        {
            // If arr[i-1] - i is negative or
            // already exists.
            if ((a[j] == curr) || curr < 0)
            {
                curr = a[i - 1] + i;
                break;
            }
        }
        a[i] = curr;
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        func();
    }

    return 0;
}