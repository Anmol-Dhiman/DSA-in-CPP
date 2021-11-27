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
        v[start] = true;
        stack<pair<int, int>> s;
        s.push({start, -1});
        int node;
        int parent;
        while (!s.empty())
        {
            node = s.top().first;
            parent = s.top().second;
            s.pop();
          

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

    return 0;
}