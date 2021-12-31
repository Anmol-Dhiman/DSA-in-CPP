// this is the basic implementation of the min heap

// max heap mae top pae maximum milae ga aur min heap mae minimum
// the time complexity for insertion is log(n)

// **it is not necessary that we will get the sorted element below the top of heap 
// but when we remove the top element of the heap then the heapify occurs and it will auto matically sort again

#include <iostream>
#include <queue>
using namespace std;
int main()
{

    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    int arr[] = {7, 10, 4, 3, 20, 15};
    int k = 3;
    for (int i = 0; i < 6; i++)
    {
        minHeap.push(arr[i]);
        if (minHeap.size() > k)
        {
            minHeap.pop();
        }
    }
    while (!minHeap.empty())
    {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }

    return 0;
}