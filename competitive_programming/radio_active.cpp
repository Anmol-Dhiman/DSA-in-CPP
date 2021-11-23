#include <iostream>
using namespace std;
int smallest(int a, int b, int c)
{
    if (a <= b && a <= c)
        return a;
    else if (b <= a && b <= c)
        return b;
    return c;
}
void func()
{
    int x;
    cin >> x;
    int a1, a2, a3, b, c1, c2, c3, d;
    cin >> a1 >> a2 >> a3 >> b >> c1 >> c2 >> c3 >> d;
    int sum=0;
    sum += (b + (d / 2));
    sum += smallest(a1, a2, a3);
    sum += smallest(c1, c2, c3);
    if (sum > x)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        func();
    return 0;
}