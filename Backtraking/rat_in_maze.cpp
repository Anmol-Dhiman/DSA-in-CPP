#include <iostream>
using namespace std;
bool isSafe(int **arr, int x, int y, int n)
{
    if (arr[x][y] == 1 && x < n && y < n)
    {
        return true;
    }
    return false;
}

bool ratinMaze(int **arr, int x, int y, int n, int **sol)
{
    if (y == n - 1 && x == n - 1)
    {
        sol[x][y] = 1;
        return true;
    }
    if (isSafe(arr, x, y, n))
    {
        sol[x][y] = 1;
        if (ratinMaze(arr, x + 1, y, n, sol))
        {
            return true;
        }
        if (ratinMaze(arr, x, y + 1, n, sol))
        {
            return true;
        }
        sol[x][y] = 0; //backtracking.
        return false;
    }
    return false;
}

int main()
{
    int n;
    cout << "enter the number of rows: ";
    cin >> n;

    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    int **sol = new int *[n];
    for (int i = 0; i < n; i++)
    {
        sol[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            sol[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    if (ratinMaze(arr, 0, 0, n, sol))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}