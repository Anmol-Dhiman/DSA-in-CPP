// in this problem we have to sort the array which is nearly sorted or k sorted which means
// that you will get the value of a particular index form k position right or left form that index

#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    vector<int> v;

    int index = 0;
    for (int i = 0; i < 7; i++)
    {
        minHeap.push(arr[i]);
        if (minHeap.size() > k)
        {
            v.push_back(minHeap.top());
            minHeap.pop();
        }
    }

    while (!minHeap.empty())
    {
        v.push_back(minHeap.top());

        minHeap.pop();
    }

    for (int i = 0; i < 7; i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}