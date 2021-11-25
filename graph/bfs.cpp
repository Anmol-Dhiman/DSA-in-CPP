// here we will see the BFS using the adjacent matrix
// the bfs is like we add the any node the exploration queue and then marked it visited in the visited queue and then we will move to all the
// nodes connected to it and the mark them visited and add them in the exploration queue
#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<int> q;
    int node;
    int index = 0;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    q.push(index);
    cout << index << " ";
    visited[index] = 1;
    int adjacent_matrix[7][7] = {{0, 1, 1, 1, 0, 0, 0},
                                 {1, 0, 1, 0, 0, 0, 0},
                                 {1, 1, 0, 1, 1, 0, 0},
                                 {1, 0, 1, 0, 1, 0, 0},
                                 {0, 0, 1, 1, 0, 1, 1},
                                 {0, 0, 0, 0, 1, 0, 0},
                                 {0, 0, 0, 0, 1, 0, 0}};
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int i = 0; i < 7; i++)
        {
            if (adjacent_matrix[node][i] == 1 && visited[i] == 0)
            {
                cout << i << " ";
                visited[i] = 1;
                q.push(i);
            }
        }
    }

    return 0;
}