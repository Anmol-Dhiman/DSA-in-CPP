// we use the same logic as the topological sort
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
    bool is_cycle_present()
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
        int count = 0;
        while (!q.empty())
        {
            node = q.front();
            q.pop();
            count++;
            for (m = arr[node].begin(); m != arr[node].end(); m++)
            {
                indegre[*m]--;
                if (indegre[*m] == 0)
                {
                    q.push(*m);
                }
            }
        }
        // if count is equal to the n or the number of noes then their is no cycle in the graph
        if (count == n)
            return false;
        return true;
    }
};
int main()
{
    graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 2);
 
    cout << g.is_cycle_present();
    return 0;
}