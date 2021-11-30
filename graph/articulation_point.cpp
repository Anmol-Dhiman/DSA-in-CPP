// Articulation point: - by removing of the nodes or points , the graph is divided into the two or more parts
// is called the ariculation points

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

    return 0;
}