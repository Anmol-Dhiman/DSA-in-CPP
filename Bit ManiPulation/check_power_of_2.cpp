#include <iostream>
using namespace std;
int ispower(int n)
{
    // n && is for the base case i.e. when input is 0
    // and n&n-1 will always be zero for the correct case so to make it true we use the ! operator
    // it will return only 0 or 1
    return (n && !(n & n - 1));
}
int main()
{
    int n;
    cout << "enter the number: ";
    cin >> n;
    if (ispower(n))
    {
        cout << "yes it is";
    }
    else
    {
        cout << "no it is not";
    }

    return 0;
}