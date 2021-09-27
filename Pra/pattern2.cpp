#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter the input: ";
    cin >> n;
    int count = n - 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= count; j++)
        {
            cout << "  ";
        }
        for (int j = 1; j <= n; j++)
        {
            cout << "* ";
        }
        count--;
        cout << endl;
    }
    return 0;
}