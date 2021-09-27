#include <iostream>
using namespace std;

int getbit(int n, int index)
{
    return ((n & (1 << index)) != 0);
}
int setbit(int n, int index)
{
    return (n | (1 << index));
}
int copy_bit(int x, int y, int l, int r)
{
    int temp = x;
    for (int i = l; i <= r; i++)
    {
        if (getbit(y, i-1))
        {
            temp = setbit(x, i-1);
        }
    }
    return temp;
}

int main()
{
    int x, y, l, r;
    cout << "enter the value of x: ";
    cin >> x;
    cout << "enter the value of y: ";
    cin >> y;
    cout << "enter the value of l: ";
    cin >> l;
    cout << "enter the value of r: ";
    cin >> r;
    cout << copy_bit(x, y, l, r) << endl;
    return 0;
}