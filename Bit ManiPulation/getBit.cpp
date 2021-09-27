#include <iostream>
using namespace std;
int getbit(int n, int index)
{
    return ((n & (1 << index)) != 0);
}
int setbit(int n, int index)
{
    return ((n | (1 << index)) != 0);
}
int clearbit(int n, int index)
{
    return (n & (~(1 << index)));
}

int updatebit(int n, int index, int val)
{
    int a = clearbit(n, index);
    return (a | (val << index));
}
int main()
{
    // int n;
    // cout << "enter the binary number:";
    // cin >> n;
    // int index;
    // cout << "enter the index: ";
    // cin >> index;
    // cout << getbit(n, index);
    // cout << clearbit(21, 2);
    cout << updatebit(5, 1, 1);
    return 0;
}