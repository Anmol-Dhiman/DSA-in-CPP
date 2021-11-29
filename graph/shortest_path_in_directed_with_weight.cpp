// this is also called the kahn's algorithm
// we can apply this algo only on DAG(directed acyclic graph)
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;
class graph

{
    int n;
    vector<pair<int, int>> *arr;
    int *distance;

public:
    graph(int v)
    {
        n = v;
        arr = new vector<pair<int, int>>[v + 1];
        distance = new int[v + 1];
        for (int i = 0; i <= v; i++)
        {
            distance[i] = INT_MAX;
        }
    }
    // this adding edge is for the undriected graph
    void addEdge(int u, int v, int weight)
    {
        arr[u].push_back({v, weight});
    }
    void shortest_distance_using_bfs(int src, int val)
    {
        distance[src] = 0;
        queue<int> q;
        q.push(src);

        int node;
        while (!q.empty())
        {
            node = q.front();
            q.pop();
            for (auto &i : arr[node])
            {
                if (distance[i.first] == INT_MAX)
                {
                    distance[i.first] = distance[node] + i.second;
                    q.push(i.first);
                }

                else
                {
                    if (distance[node] + i.second < distance[i.first])
                    {
                        distance[i.first] = distance[node] + i.second;
                    }
                }
            }
        }
        cout << distance[val];
    }
};
int main()
{
    graph g(6);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 4, 1);
    g.addEdge(4, 2, 2);
    g.addEdge(1, 2, 3);
    g.addEdge(4, 5, 4);
    g.addEdge(5, 3, 1);

    g.addEdge(2, 3, 6);
    g.shortest_distance_using_bfs(0, 3);
    return 0;
}