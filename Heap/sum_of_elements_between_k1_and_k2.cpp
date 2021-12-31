// in this question we have to find the sum of values between k1 smallest and k2 smallest

#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int arr[] = {1, 3, 12, 5, 15, 11};
    int k1 = 3;
    int k2 = 6;
    priority_queue<int> maxHeap;
    // first we will find the k1th smallest and then find the k2th smallest
    // and the number between k1st and k2nd we will add them into the sum

    for (int i = 0; i < 6; i++)
    {
        maxHeap.push(arr[i]);
        if (maxHeap.size() > k1)
        {
            maxHeap.pop();
        }
    }
    int k1st_smallest = maxHeap.top();
    while (!maxHeap.empty())
    {
        maxHeap.pop();
    }

    for (int i = 0; i < 6; i++)
    {
        maxHeap.push(arr[i]);
        if (maxHeap.size() > k2)
        {
            maxHeap.pop();
        }
    }
    int k2th_smallest = maxHeap.top();
    int sum = 0;
    for (int i = 0; i < 6; i++)
    {
        if (arr[i] > k1st_smallest && arr[i] < k2th_smallest)
        {
            sum += arr[i];
        }
    }
    cout << sum;
    return 0;
}