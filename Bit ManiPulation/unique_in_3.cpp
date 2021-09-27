#include <iostream>
using namespace std;
int getbit(int n, int index)
{
    return ((n & (1 << index)) != 0);
}
int setbit(int n, int index)
{
    return (n | (1 << index));
}
int unique(int a[], int n)
{
    int result = 0;
    int sum;
    for (int i = 0; i < 64; i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (getbit(a[j], i))
            {
                sum++;
            }
        }
        if (sum % 3 != 0)
        {
           
            result = setbit(result, i);
        }
    }
    return result;
}
int main()
{
    // int n;
    // cout << "enter the number of input";
    // cin >> n;
    int a[] = {1, 2, 3, 4, 2, 3, 1, 1, 2, 3};
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    // }
    cout << unique(a, 10) << endl;
    return 0;
}