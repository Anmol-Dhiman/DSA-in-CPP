#include <iostream>
using namespace std;

void primeFactor(int n)
{
    int temp = 2;
    int a[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        a[i] = temp;
        temp++;
    }
    for (int i = 0; i < n - 1; i++) 
    {
        if (a[i] == i + 2)
        {
            for (int j = i * i - 2; j < n - 1; j += a[i])
            {
                if (a[j] == j + 2)
                {
                    a[j] = i + 2;
                }
            }
        }
    }
    while (n != 1)
    {
        cout << a[n - 2] << " ";
        n = n / a[n - 2];
    }
   
}

int main()
{
    int n;
    cout << "enter the number: ";
    cin >> n;
    primeFactor(n);
    return 0;
}