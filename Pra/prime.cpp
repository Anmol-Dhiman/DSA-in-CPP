#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cout << "enter the number: ";
    cin >> n;
    bool check;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cout << n;
            cout << " is Non prime number" << endl;
            check = 1;
            break;
        }
    }
    if (check == 0)
    {
        cout << n;
        cout << "is prime number." << endl;
    }

    return 0;
}