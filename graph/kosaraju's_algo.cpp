// some of the main points of kosaraju's aglo: -

// this algo helps to find the strongly connected components (SCC) in a graph

// strongly connected component: - the component in which we can go to any node form any node
// i.e. if we start with any node then we can go to the every other node

// a single node can also be the SCC i.e. single scc

// the algo sequence: -
// 1. find the toposort using DFS ans store it into the stack
// 2. transpose the graph i.e. reverse the edges
// 3. now find the dfs using that stack in step 1 and print the dfs


#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class graph
{
    int n;
    vector<int> *arr;
    int *visited;
    void findTopo(int node, stack<int> &s)
    {
        visited[node] = 1;
        for (auto i : arr[node])
        {
            if (!visited[i])
            {
                findTopo(i, s);
            }
        }
        s.push(node);
    }
    void get_transpose(vector<int> transpose[])
    {
        for (int i = 0; i <= n; i++)
        {
            visited[i] = 0;
            for (auto j : arr[i])
            {
                transpose[j].push_back(i);
            }
        }
    }
    void dfs_reverse(int node, vector<int> transpose[])
    {
        visited[node] = 1;
        cout << node << " ";
        for (auto i : transpose[node])
        {
            if (!visited[i])
            {
                dfs_reverse(i, transpose);
            }
        }
    }

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
    void SCC_kosaraju()
    {
        stack<int> s;
        for (int i = 0; i <= n; i++)
        {
            if (!visited[i])
                findTopo(i, s);
        }
        // while (!s.empty())
        // {
        //     cout << s.top() << " ";
        //     s.pop();
        // }

        vector<int> transpose[n + 1];
        get_transpose(transpose);
        int node;
        while (!s.empty())
        {
            node = s.top();
            s.pop();
            if (!visited[node])
            {
                cout << "SCC"
                     << " ";
                dfs_reverse(node, transpose);
                cout << endl;
            }
        }
    }
};
int main()
{

    graph g(5);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(2, 4);
    g.addEdge(4, 5);
    
    g.SCC_kosaraju();
    return 0;
}