#include <iostream>
using namespace std;
int getbit(int n, int index)
{
    return ((n & (1 << index)) != 0);
}
int convert(int a, int b)
{
    int temp = a ^ b;
    int count = 0;
    for (int i = 0; i < 64; i++)
    {
        if (getbit(temp, i))
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int a;
    int b;
    cin >> a;
    cin >> b;
    cout << convert(a, b) << endl;
    return 0;
}