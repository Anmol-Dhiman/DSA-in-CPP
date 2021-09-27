#include <iostream>
using namespace std;
int count(int n)
{
    int val = 0;
    while (n > 0)
    {
        n = n & (n - 1);
        val++;
    }
    return val;
   
}
int main()
{
    int n;
    cout << "enter the nubmer:";
    cin >> n;
    cout << count(n);
    return 0;
}