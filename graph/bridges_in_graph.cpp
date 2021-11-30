// bridge in garph means if we remove any edges then the graph will break down into two or more components

#include <iostream>
#include <vector>
using namespace std;
class graph
{
    int n;
    vector<int> *arr;
    int *input;
    int *lowest_input;
    int *visited;

public:
    graph(int v)
    {
        n = v;
        arr = new vector<int>[n + 1];
        input = new int[n + 1];
        visited = new int[n + 1];
        lowest_input = new int[n + 1];
        for (int i = 0; i <= n; i++)
        {
            input[i] = 0;
            lowest_input[i] = 0;
            visited[i] = 0;
        }
    }
    void addEdge(int u, int v)
    {
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    void dfs(int node, int parent, int &timer)
    {
        visited[node] = 1;
        input[node] = lowest_input[node] = timer++;
        for (auto i : arr[node])
        {
            if (i == parent)
                continue;
            if (!visited[i])
            {
                dfs(i, node, timer);
                lowest_input[node] = min(lowest_input[node], lowest_input[i]);

                // main algo: - 
                // we compare the lowest time with the input time because if the lowest time of the 
                // connected node is greater then the input time of its parent node this means their 
                // is no other way to go to that node and this means it is the part of the bridge node
                // if we have the way to go that node then the lowest time of connected node will be equal to the input time of parent node
                
                if (lowest_input[i] > input[node])
                    cout << node << " " << i << endl;
            }
            else
                lowest_input[node] = min(lowest_input[node], lowest_input[i]);
        }
    }
    void bridege_exists()
    {
        int timer = 0;
        for (int i = 0; i <= n; i++)
        {
            if (!visited[i])
                dfs(i, -1, timer);
        }
    }
};

int main()
{
    graph g(7);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 1);
    g.addEdge(4, 3);
    g.addEdge(5, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 5);

    g.bridege_exists();

    return 0;
}