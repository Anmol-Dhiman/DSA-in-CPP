#include <iostream>
#include <stack>
using namespace std;
int visited[7] = {0, 0, 0, 0, 0, 0, 0};

int adjacent_matrix[7][7] = {{0, 1, 1, 1, 0, 0, 0},
                             {1, 0, 1, 0, 0, 0, 0},
                             {1, 1, 0, 1, 1, 0, 0},
                             {1, 0, 1, 0, 1, 0, 0},
                             {0, 0, 1, 1, 0, 1, 1},
                             {0, 0, 0, 0, 1, 0, 0},
                             {0, 0, 0, 0, 1, 0, 0}};
// the recursive method for dfs and it will automatically use the stack 
void dfs_recursive(int i)
{
    cout << i << " ";
    visited[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if (adjacent_matrix[i][j] == 1 && visited[j] == 0)
        {
            dfs_recursive(j);
        }
    }
}
int main()
{
    stack<int> s;
    s.push(0);
    int node;
    while (!s.empty())
    {
        node = s.top();
        s.pop();
        if (visited[node] == 0)
        {
            visited[node] = 1;
            cout << node << " ";
        }

        for (int i = 0; i < 7; i++)
        {
            if (adjacent_matrix[node][i] == 1 && visited[i] == 0)
            {
                s.push(i);
            }
        }
    }

    return 0;
}