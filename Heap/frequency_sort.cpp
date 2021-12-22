// we have to sort the elements on the basis of their frequency

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
int main()
{
    priority_queue<pair<int, int>> maxHeap;
    unordered_map<int, int> mp;
    int arr[] = {1, 1, 1, 2, 3, 3, 4};

    for (int i = 0; i < 7; i++)
    {
        mp[arr[i]]++;
    }
    unordered_map<int, int>::iterator it;
    for (it = mp.begin(); it != mp.end(); it++)
    {
        maxHeap.push({(*it).second, (*it).first});
    }
    int frequency;
    int index = 0;
    int data;
    while (!maxHeap.empty())
    {
        frequency = maxHeap.top().first;
        data = maxHeap.top().second;
        maxHeap.pop();
        for (int i = 0; i < frequency; i++)
        {
            arr[index] = data;
            cout << arr[index] << " ";
            index++;
        }
    }

    return 0;
}