

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
class graph
{
    // number of nodes
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
    // breadth first search/ level wise traversal

    void bfs(int start)
    {
        // the same concept is used as compare to the adjacency matrix
        queue<int> q;
        q.push(start);
        bool *visited = new bool[n];
        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
        }
        visited[start] = true;
        int temp;
        vector<int>::iterator i;
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            cout << temp << " ";
            for (i = arr[temp].begin(); i != arr[temp].end(); i++)
            {
                if (!visited[*i])
                {
                    visited[*i] = true;
                    q.push(*i);
                }
            }
        }
        cout << endl;
    }
    void dfs(int start)
    {
        stack<int> s;
        s.push(start);
        bool *visited = new bool[n];
        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
        }
        visited[start] = true;
        int node;
        vector<int>::iterator i;
        while (!s.empty())
        {

            node = s.top();
            s.pop();
            if (!visited[node])
            {
                visited[node] = true;
                cout << node << " ";
            }
            for (i = arr[node].begin(); i != arr[node].end(); i++)
            {
                if (!visited[*i])
                {
                    visited[*i] = true;
                    s.push(*i);
                }
            }
        }
        cout << endl;
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
    g.bfs(2);
    g.dfs(2);
    return 0;
}