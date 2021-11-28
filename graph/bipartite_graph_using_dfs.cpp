

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class graph

{
    int n;
    vector<int> *arr;
    int *color;
    bool checking_bipartite(int node)
    {
        // this condition will be used only once for the first node only
        if (color[node] == -1)
        {
            color[node] = 1;
        }
        vector<int>::iterator i;
        for (i = arr[node].begin(); i != arr[node].end(); i++)
        {
            if (color[*i] == -1)
            {
                color[*i] = 1 - color[node];
                if (!checking_bipartite(*i))
                    return false;
            }
            else if (color[*i] == color[node])
                return false;
        }
        return true;
    }

public:
    graph(int v)
    {
        n = v;
        arr = new vector<int>[v + 1];
        color = new int[v + 1];
        for (int i = 0; i <= v; i++)
        {
            color[i] = -1;
        }
    }
    void addEdge(int u, int v)
    {
        arr[u].push_back(v);
    }

    bool is_bipartite()
    {
        // this for loop is only used when the graph have the components
        for (int i = 0; i <= n; i++)
        {
            if (color[i] == -1)
            {
                if (!checking_bipartite(i))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
int main()
{

    graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    cout << g.is_bipartite();
    return 0;
}