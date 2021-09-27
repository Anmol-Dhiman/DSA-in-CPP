#include <iostream>
using namespace std;

int count_to_convert(int a, int b)
{
    int temp = a ^ b;
    int count = 0;
    while (temp > 0)
    {
        temp = temp & (temp - 1);
        count++;
    }
    return count;
}

int main()
{
    int a, b;
    cout << "enter the value of A: ";
    cin >> a;
    cout << "enter the value of B: ";
    cin >> b;
    cout << count_to_convert(a, b) << endl;
    return 0;
}