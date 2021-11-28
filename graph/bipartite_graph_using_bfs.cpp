// bipartite graph means: - if we colour the nodes with two differnt colours then no two adjacents nodes have the same colour
// and the trick to find any graph is bipartite or not : -
// if the graph have a cycle with odd nodes then it is not bipartite otherwise it is bipartite

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
        queue<int> q;
        q.push(node);
        color[node] = 1;
        int temp;
        vector<int>::iterator i;
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            for (i = arr[temp].begin(); i != arr[temp].end(); i++)
            {
                if (color[*i] == -1)
                {
                    color[*i] = 1 - color[temp];
                    q.push(*i);
                }
                else if (color[*i] == color[temp])
                    return false;
            }
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
        // this for loop will only be usefull when the graph have the components or we can say that graph is divides into more than 1 part
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
    cout << g.is_bipartite();
    return 0;
}