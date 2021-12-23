// here we have an array in which we have to sum two number and again add this element in the array and so on
// just like that we have to find the minimum sum

// algo: - we will add all the elements in the minHeap and then pop out first two element and add them and push the sum agian
// until the heap is empty
#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int arr[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        minHeap.push(arr[i]);
    }
    // we will store the previous sum and add it with the new sum
    // so that we have the proper value addition
    
    int cost = 0;
    int first;
    
    int second;
    while (minHeap.size() > 1)
    {
        first = minHeap.top();
        minHeap.pop();
        second = minHeap.top();
        minHeap.pop();
        cost = cost + first + second;
        minHeap.push(first + second);
    }
    cout << cost;
    return 0;
}