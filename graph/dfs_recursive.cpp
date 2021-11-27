#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class graph
{
    int n;
    vector<int> *arr;
    bool *visited;

public:
    graph(int v)
    {
        n = v;
        arr = new vector<int>[v + 1];
        visited = new bool[v + 1];
        for (int i = 0; i <= v; i++)
        {
            visited[i] = false;
        }
    }

    void addEdge(int u, int v)
    {
        arr[u].push_back(v);
    }
    void dfs(int start)
    {
        visited[start] = true;
        cout << start << " ";
        vector<int>::iterator i;
        for (i = arr[start].begin(); i != arr[start].end(); i++)
        {
            if (visited[*i] == false)
            {
                dfs(*i);
            }
        }
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
    g.dfs(2);
    return 0;
}