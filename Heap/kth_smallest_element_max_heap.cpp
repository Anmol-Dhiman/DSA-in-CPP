// this is the basic implementation of max heap

// this is the question where we have to find the kth smallest element in the array


#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue<int> max;
    int arr[] = {7, 10, 4, 3, 20, 15};
    int k = 3;
    for (int i = 0; i < 6; i++)
    {
        max.push(arr[i]);
        if (max.size() > k)
        {
            max.pop();
        }
    }
    cout << max.top();
    return 0;
}