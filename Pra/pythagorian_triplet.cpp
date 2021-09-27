#include <iostream>
using namespace std;
void pytha_check(int max, int b, int c)
{
    if ((max * max) == (b * b + c * c))
    {
        cout << "yes these are pythagorian triplets.";
    }
    else
    {
        cout << "no they are not pythagorian triplets.";
    }
}
void check(int a, int b, int c)
{
    if (a > b)
    {
        if (a > c)
        {
            pytha_check(a, b, c);
        }
        else
        {
            pytha_check(c, a, b);
        }
    }
    else
    {
        if (b > c)
        {
            pytha_check(b, a, c);
        }
        else
        {
            pytha_check(c, a, b);
        }
    }
}

int main()
{
    int x, y, z;
    cout << "enter the data: ";
    cin >> x >> y >> z;
    check(x, y, z);
    return 0;
}