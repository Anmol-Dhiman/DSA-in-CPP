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
    vector<int> *arr;
    int *visited;

public:
    graph(int v)
    {
        n = v;
        arr = new vector<int>[v + 1];
        visited = new int[v + 1];
        for (int i = 0; i <= v; i++)
        {
            visited[i] = 0;
        }
    }
    void addEdge(int u, int v)
    {
        arr[u].push_back(v);
    }
    void topological_sort()
    {

        vector<int>::iterator j;
        queue<int> q;
        int indegre[n];
        for (int i = 0; i < n; i++)
        {
            indegre[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            for (j = arr[i].begin(); j != arr[i].end(); j++)
            {
                indegre[*j] += 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (indegre[i] == 0)
            {
                q.push(i);
            }
        }
        int node;
        vector<int>::iterator m;

        while (!q.empty())
        {
            node = q.front();
            q.pop();
            cout << node << " ";
            for (m = arr[node].begin(); m != arr[node].end(); m++)
            {
                indegre[*m]--;
                if (indegre[*m] == 0)
                {
                    q.push(*m);
                }
            }
        }
    }
};
int main()
{
    graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.topological_sort();
    return 0;
}