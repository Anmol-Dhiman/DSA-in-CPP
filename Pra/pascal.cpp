#include <iostream>
using namespace std;
int fact(int a)
{
    int fac = 1;
    for (int i = 2; i <= a; i++)
    {
        fac *= i;
    }
    return fac;
}
int main()
{
    int n;
    cout << "enter the number: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j <= i; j++)
        {
            cout << fact(i) / (fact(j) * fact(i - j)) << " ";
        }
        cout << endl;
    }
    return 0;
}