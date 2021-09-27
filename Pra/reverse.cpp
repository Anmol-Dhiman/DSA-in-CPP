#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter the number: ";
    cin >> n;
    int count = 0;
    int val;
    while (n >0)
    {
        val = n % 10;
        n = n / 10;
        count = (count * 10) + val;
    }
    cout << count;
    return 0;
}