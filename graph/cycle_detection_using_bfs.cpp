// algo: - 
// we will store the data in the queue in pair like node and it's parent node
// and if we found any connected node is which is visited is not equal to the prev, then we have the cycle in the graph 
// and we will return true at that point of time 
 

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
class graph
{
    int n;
    vector<int> *arr;

public:
    graph(int v)
    {
        n = v;
        arr = new vector<int>[v];
    }
    void addEdge(int u, int v)
    {
        arr[u].push_back(v);
    }
    bool cycle_present(int start, vector<bool> &v)
    {
        queue<pair<int, int>> q;
        q.push({start, -1});
        v[start] = true;
        while (!q.empty())
        {
            int node = q.front().first;
            int prev = q.front().second;
            q.pop();
            for (auto i : arr[node])
            {
                if (!v[i])
                {
                    v[i] = true;
                    q.push({i, node});
                }
                else if (prev != i)
                    return true;
            }
        }
        return false;
    }
    bool is_cycle()
    {
        // we use the bfs tech to find the cycle
        vector<bool> visited(n + 1, false);
        for (int i = 0; i <= n; i++)
        {
            if (!visited[i])
                if (cycle_present(i, visited))
                    return true;
        }
        return false;
    }
};
int main()
{
    graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout << g.is_cycle();
    return 0;
}