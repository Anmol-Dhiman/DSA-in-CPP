// basically we want to find those numbers which are closest to the given number
// eg: - the input is 7 then the most closest are 6 and 8 and 7 itself

#include <iostream>
#include <queue>

using namespace std;
int main()
{
    priority_queue<pair<int, int>> maxHeap;
    int arr[] = {5, 6, 7, 8, 9};
    int given_value;
    int number_closest_k;
    cout << "enter the key value: ";
    cin >> given_value;
    cout << "enter the number of closest elements to be found: ";
    cin >> number_closest_k;

    for (int i = 0; i < 5; i++)
    {
        maxHeap.push({abs(arr[i] - given_value), arr[i]});
        if (maxHeap.size() > number_closest_k)
        {
            maxHeap.pop();
        }
    }
    while (!maxHeap.empty())
    {
        cout << maxHeap.top().second << " ";
        maxHeap.pop();
    }

    return 0;
}