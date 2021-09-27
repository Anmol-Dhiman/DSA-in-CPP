#include <iostream>
using namespace std;
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
    int count = 0;
    int maxNum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        count += a[i];
        if (count < 0)
        {
            count = 0;
        }
        maxNum = max(maxNum, count);
    }
    cout << maxNum;
    return 0;
}