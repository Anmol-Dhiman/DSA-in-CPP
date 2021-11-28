// this is not complete

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class graph

{
    int n;
    vector<int> *arr;
    int *visited;
    void findtopo(int node, stack<int> &s)
    {
        visited[node] = 1;
        vector<int>::iterator i;
        for (i = arr[node].begin(); i != arr[node].end(); i++)
        {
            if (visited[*i] == false)
            {
                findtopo(*i, s);
            }
        }
        s.push(node);
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
    void topological_sort()
    {
        stack<int> s;
        for (int i = 0; i <= n; i++)
        {
            if (visited[i] == 0)
                findtopo(i, s);
        }
        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
    }
};
int main()
{
    graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
   
    g.topological_sort();
    return 0;
}