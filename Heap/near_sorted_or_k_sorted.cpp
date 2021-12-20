// in this problem we have to sort the array which is nearly sorted or k sorted which means
// that you will get the value of a particular index form k position right or left form that index

#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int arr[] = {7, 10, 4, 3, 20, 15};
    int k = 3;
    int index = 0;
    for (int i = 0; i < 6; i++)
    {
        minHeap.push(arr[i]);
        if (minHeap.size() > k)
        {
            arr[index] = minHeap.top();
            minHeap.pop();
            index++;
        }
    }

    while (!minHeap.empty())
    {
        arr[index] = minHeap.top();
        minHeap.pop();
        index++;
    }

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}