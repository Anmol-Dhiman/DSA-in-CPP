#include <bits/stdc++.h>

#define ll long long int
#define func                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define size_ 4
#define MAXN 100001
#define test  \
    int t;    \
    cin >> t; \
    while (t--)

using namespace std;

void dist_(int dp[][size_])
{
    int d[size_][size_];
    for (int i = 0; i < size_; i++)
        for (int j = 0; j < size_; j++)
            d[i][j] = dp[i][j];

    for (int k = 0; k < size_; k++)
    {
        for (int i = 0; i < size_; i++)
        {
            for (int j = 0; j < size_; j++)
                if (d[i][j] > (d[i][k] + d[k][j]) && (d[k][j] != MAXN && d[i][k] != MAXN))
                    d[i][j] = d[i][k] + d[k][j];
        }
    }

    for (int i = 0; i < size_; i++)
    {
        for (int j = 0; j < size_; j++)
        {
            if (d[i][j] == 1000)
                cout << "N"
                     << "  ";
            else
                cout << d[i][j] << "  ";
        }
        cout << endl;
    }
}

void solve()
{
    int dp[size_][size_];
    cout << "Enter 1000 if the node is not reachable in the test case." << endl;
    for (int i = 0; i < size_; i++)
    {
        for (int j = 0; j < size_; j++)
        {
            cin >> dp[i][j];
        }
    }
    dist_(dp);
}

int main()
{
    func
        test
    {
        solve();
    }
    return 0;
}