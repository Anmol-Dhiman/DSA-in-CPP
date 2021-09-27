#include <iostream>
using namespace std;

int hcf(int a, int b)
{
    int temp;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return temp;
}

int main()
{
    int a;
    int b;
    cout << "enter the value of A: ";
    cin >> a;

    cout << "enter the value of B: ";
    cin >> b;
    cout << hcf(a, b) << endl;
    return 0;
}