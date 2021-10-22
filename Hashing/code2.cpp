#include <iostream>
#include <algorithm>
using namespace std;
int number_of_coins(int coins[], int value, int p, int price)
{
    if (value == 0)
    {
        return price;
    }
    price += value / coins[p];
    value %= coins[p];
    return number_of_coins(coins, value, p + 1, price);
}
int main()
{
    int n;
    cout << "Enter the number of type of coins: ";
    cin >> n;
    int a;
    cout << "Enter the cost of an activity: ";
    cin >> a;

    int value[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the value of coin: ";
        cin >> value[i];
    }
    sort(value, value + n);
    cout << "The minimum number of coins is : " << number_of_coins(value, a, 0, 0);

    return 0;
}