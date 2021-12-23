// in this question we have to find k closest elements form the origin


// we need to find the minimum distance so that we have to use the max Heap
// as in max heap the maximum elements are at the top 

#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
float cal(int a, int b)
{
    return sqrt(pow(a, 2) + pow(b, 2));
}

int main()
{
    priority_queue<pair<float, pair<int, int>>> maxHeap;
    pair<int, int> arr[4];

    // the input
    arr[0].first = 1;
    arr[0].second = 3;
    arr[1].first = -2;
    arr[1].second = 2;
    arr[2].first = 5;
    arr[2].second = 8;
    arr[3].first = 0;
    arr[3].second = 1;

    int k = 2;
    for (int i = 0; i < 4; i++)
    {
        maxHeap.push({cal(arr[i].first, arr[i].second), {arr[i].first, arr[i].second}});
        if (maxHeap.size() > k)
        {
            maxHeap.pop();
        }
    }
    int x;
    int y;
    while (!maxHeap.empty())
    {
        x = maxHeap.top().second.first;
        y = maxHeap.top().second.second;
        maxHeap.pop();
        cout << x << " " << y << endl;
    }

    return 0;
}