#include <iostream>
using namespace std;
void primeNum(int n)
{
    int a[n + 1] = {0};
    for (int i = 2; i <= n; i++)
    {
        if (a[i] != 1)
        {
            for (int j = i * i; j <= n; j += i)
            {
                a[j] = 1;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == 0)
        {
            cout << i << " ";
        }
    }
}

int main()
{
    int n;
    cout << "enter the number: ";
    cin >> n;
    primeNum(n);
    return 0;
}