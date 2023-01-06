// we see in the array that there are n number of elements then there will be 2 ^ n - 1 number of subsets.
// and the count goes from 0 to 2^n - 1.
// in this program we will print the value corresponding to the setbit

#include <iostream>
#include <vector>
using namespace std;

void subset(int a[], int n)
{
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & 1 << j)
            {
                cout << a[j] << " ";
            }
        }
        cout << endl;
    }
}
int main()
{
    return 0;
}