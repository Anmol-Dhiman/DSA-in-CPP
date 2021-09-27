#include <iostream>
using namespace std;

int count(int n)
{
    int temp = n;
    int num = 0;
    int setbit = 0;
    int pos = 0;
    while (temp > 0)
    {
        temp = temp & (temp - 1);
        num++;
    }
    if (num != 1)
    {
        return -1;
    }
    else
    {
        while (setbit != 1)
        {
            setbit = n & 1;
            pos++;
            n = n >> 1;
        }
        return pos;
    }
}

int main()
{
    int n;
    cout << "enter the number: ";
    cin >> n;
    cout << count(n) << endl;
    return 0;
}