// in this question we have to find the sum of values between k1 smallest and k2 smallest

#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int arr[] = {1, 3, 12, 5, 15, 11};
    int k1 = 3;
    int k2 = 6;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < 6; i++)
    {
        minHeap.push(arr[i]);
        if (minHeap.size() >= k2)
        {
            minHeap.pop();
        }
    }
    int sum = 0;
    for (int i = 0; i < k2 - k1 - 1; i++)
    {
        sum += minHeap.top();
        minHeap.pop();
    }

    cout << sum;
    return 0;
}