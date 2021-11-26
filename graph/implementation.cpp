#include <iostream>
#include <vector>
using namespace std;
void add_node_undirected(vector<int> a[], int u, int v)
{
    //   if we have to make the directed graph then we have to do the first step only
    a[u].push_back(v);
    a[v].push_back(u);
}
int main()
{
    // this is the implementation of undirected graph using adjacency matrix
    // the space complexity of matrix is n ^ 2;
    int n;
    cout << "enter the number of nodes: ";
    cin >> n;
    int a[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        int u, v;
        cout << "enter the nodes which are connected";
        cin >> u >> v;
        a[u][v] = 1;
        a[v][u] = 1;
    }

    // here the implemenation of undirected graph using the list
    // using the list is more space efficient
    // the space complexity of list is N + 2 edges
    int m;
    cout << "enter the number of nodes: ";
    vector<int> adj_undirected[m];
    add_node_undirected(adj_undirected, 1, 2);

    return 0;
}