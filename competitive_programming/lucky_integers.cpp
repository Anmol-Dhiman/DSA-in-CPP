#include <iostream>
using namespace std;
int main()
{
    // test case
    int t;
    cin >> t;
    while (t--)
    {
        // number of element in array
        int n;
        cin >> n;

        int k;
        cin >> k;
        // value to be checked if equal or not
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
        int res;
        int z = 0;
        int q = n - 1;
        for (int i = 0; i < n - 1; i++)
        {
            if ((i - k) >= 0)
                z = i - k;

            for (int j = z; j <= q; j++)
            {
                if (a[i] == a[j])
                    continue;
                res = a[i] * a[j];
                if (res < Y)
                {
                    int p = Y - res;
                    if (p >= 0 && p < n)
                    {
                        cout << a[i] << " " << a[j] << " " << p << endl;
                        return 0;
                    }
                }
            }
        }
        cout << -1 << endl;
    }
    return 0;
}