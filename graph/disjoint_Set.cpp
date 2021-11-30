// this disjoint set is an sanother type of data structrue which will help to find the MST 
#include <iostream>
using namespace std;
class disjoint_set
{
    int n;
    int *parent;
    int *root;

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
};
int main()
{

    return 0;
}