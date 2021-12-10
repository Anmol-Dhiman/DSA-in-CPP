// question: -

// in this problem we have some objects with their price and their weight give to us and we have a knapsack or container with fixed
// capacity and we have to fill those object in that container so that we get the maximum profit

// **we can also take the objects in fraction

// in 0 - 1 knapsack we cannot take to fraction objects

#include <iostream>
#include <algorithm>
using namespace std;

void solving(int n, int wgt[], int price[], int capacity)
{
    int x[n];
    for (int i = 0; i < n; i++)
    {
        x[i] = price[i] / wgt[i];
    }
    int profit_sum = 0;
    sort(x[0], x[n - 1]);
    for (int i = n - 1; i >= 0; i++)
    {
        if (wei < capacity)
        {
            capacity -= x[i];
            sum+=
        }
    }
}
int main()
{
    int number_of_objects;
    cout << "enter the number of objects : ";
    cin >> number_of_objects;
    int capacity;
    cout << "enter the capacity of container : ";
    cin >> capacity;
    int weight[number_of_objects];
    int price[number_of_objects];
    for (int i = 0; i < number_of_objects; i++)
    {
        cout << "enter the input";
        cin >> weight[i];
    }
    for (int i = 0; i < number_of_objects; i++)
    {
        cout << "enter the input";
        cin >> price[i];
    }

    solving(number_of_objects, weight, price, capacity);

    return 0;
}