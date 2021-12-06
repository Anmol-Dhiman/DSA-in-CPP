#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "enter the number of input: ";
    cin >> n;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        int start;
        int end;
        cin >> start >> end;
        v.push_back({start, end});
    }

    // this is the lambda function: - the function which is used only once and it's defination is diclared in the code only
    sort(v.begin(), v.end(), [&](vector<int> &a, vector<int> &b)
         { return a[1] < b[1]; });
    int count = 1;
    int end = v[0][1];
    for (int i = 1; i < n; i++)
    {
        if (v[i][0] > end)
        {
            end = v[i][1];
            count++;
        }
    }
    cout << count << endl;
    return 0;
}