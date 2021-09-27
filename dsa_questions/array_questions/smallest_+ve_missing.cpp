#include <iostream>
using namespace std;

int missing_number(int a[], int n)
{
    int maxNum = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > maxNum)
        {
            maxNum = a[i];
        }
    }
    bool b[maxNum + 1];
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
        {
            b[a[i]] = true;
        }
    }
    for (int i = 0; i <= maxNum; i++)
    {
        if (b[i] == false)
        {
            return i;
        }
    }
    return -1;
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
    cout << missing_number(a, n) << endl;
    return 0;
}