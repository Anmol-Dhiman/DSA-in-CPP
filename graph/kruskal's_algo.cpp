// *******not completed


// this algo is for finding the MST  by using the disjoint set data structrue

// algo: -
// first sort the edges according to the weight
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// code of the disjoint sets: -
class disjoint_set
{
    int n;
    int *parent;
    int *root;
    vector<pair<int, int>> *arr;

public:
    disjoint_set(int v)
    {
        n = v;
        parent = new int[v];
        root = new int[v];
        for (int i = 0; i <= v; i++)
        {
            parent[i] = i;
            root[i] = 0;
        }
        arr = new vector<pair<int, int>>[v];
    }
    int findPar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        // here we do the path compresion
        // i.e.eg : -1->2->3 if we have this then by uing this path comprehension we will update the parent of 1 as 3 instead of 2 in the array;
        return parent[node] = findPar(parent[node]);
    }
    void union_disjoint(int u, int v)
    {
        if (root[u] < root[v])
        {
            parent[v] = u;
        }
        else if (root[u] > root[v])
        {
            parent[u] = v;
        }
        else
        {
            parent[u] = v;
            root[u]++;
        }
    }
    // adding the node
    void node(int u, int v, int wt)
    {
        arr[u].push_back({wt, v});
        arr[v].push_back({wt, u});
    }
    void minimum_spanning(){
        int cost=0;
        sort(arr.begin(),arr.end());
    }
};
int main()
{
    disjoint_set d(7);
    d.node(1, 2, 2);
    return 0;
}