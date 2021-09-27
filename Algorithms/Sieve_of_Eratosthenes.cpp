#include <iostream>
using namespace std;

void prime_numbers(int n)
{
    int a[n - 1];
    int temp = 2;
    for (int i = 0; i < n - 1; i++)
    {
        a[i] = temp;
        temp++;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] != 0)
        {
            for (int j = (a[i] * a[i]) - 2; j < n - 1; j += a[i])
            {
                if (a[j] % a[i] == 0)
                {
                    a[j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] != 0)
        {
            cout << a[i] << " ";
        }
    }
}

int main()
{
    int n;
    cout << "enter the number: ";
    cin >> n;
    prime_numbers(n);
    return 0;
}