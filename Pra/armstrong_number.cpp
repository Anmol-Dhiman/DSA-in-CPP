#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cout << "enter the number: ";
    cin >> n;
    int sum = 0;
    int temp = n;
    while (temp > 0)
    {
        int lastdigit = temp % 10;
        temp = temp / 10;
        sum += pow(lastdigit, 3);
    }
    if (sum == n)
    {
        cout << n;
        cout << " is the armstrong number.";
    }
    else
    {
        cout << n;
        cout << " is not the armstrong number.";
    }
    

    return 0;
}