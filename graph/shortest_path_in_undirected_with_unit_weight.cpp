
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;
class graph

{
    int n;
    vector<int> *arr;
    int *distance;

public:
    graph(int v)
    {
        n = v;
        arr = new vector<int>[v + 1];
        distance = new int[v + 1];
        for (int i = 0; i <= v; i++)
        {
            distance[i] = INT_MAX;
        }
    }
    // this adding edge is for the undriected graph
    void addEdge(int u, int v)
    {
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    void shortest_distance(int ref, int val)
    {

        // logic: - for finding the shortest distance we just modify the bfs algo 
        // we will use a array named distance and if the value at any node is equal to the INT_MAX then we will modify it by adding 1 to the distance value of previous node
        // and push it into the queueH
        // and continues the process until the queue is empty
        queue<int> q;
        q.push(ref);
        distance[ref] = 0;
        vector<int>::iterator i;
        int node;
        while (!q.empty())
        {
            node = q.front();
            q.pop();
            for (i = arr[node].begin(); i != arr[node].end(); i++)
            {
                if (distance[*i] == INT_MAX)
                {
                    distance[*i] = distance[node] + 1;
                    q.push(*i);
                }
            }
        }
        cout << distance[val] << endl;
    }
};
int main()
{
    graph g(8);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(4, 6);
    g.addEdge(3, 6);
  
    g.addEdge(6, 7);
    g.shortest_distance(0, 6);
    return 0;
}