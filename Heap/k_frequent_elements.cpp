// in this question we have to find the k frequent elements.

#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

int main()
{
    unordered_map<int, int> mp;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int arr[] = {1, 1, 1, 2, 3, 3, 4};
    // the number of elements to be found
    int k = 2;

    for (int i = 0; i < 7; i++)
    {
        mp[arr[i]]++;
    }
    unordered_map<int, int>::iterator it;
    for (it = mp.begin(); it != mp.end(); it++)
    {
        pq.push({(*it).second, (*it).first});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    cout << "key value   frequency" << endl;
    while (!pq.empty())
    {

        cout << pq.top().second << " " << pq.top().first << endl;
        pq.pop();
    }

    return 0;
}