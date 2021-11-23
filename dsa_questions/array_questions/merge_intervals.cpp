#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    // intervals = [[1,3],[2,6],[8,10],[15,18]]
    vector<vector<int>> intervals;
    vector<int> temp;
    temp.push_back(1);
    temp.push_back(3);
    intervals.push_back(temp);

    temp.clear();
    temp.push_back(2);
    temp.push_back(6);
    intervals.push_back(temp);

    temp.clear();
    temp.push_back(8);
    temp.push_back(10);
    intervals.push_back(temp);

    temp.clear();

    temp.push_back(15);
    temp.push_back(18);
    intervals.push_back(temp);
    stack<vector<int>> s;
    s.push(intervals[0]);
    vector<int> val;
    for (int i = 1; i < intervals.size(); i++)
    {
        val = s.top();
        if (val[1] >= intervals[i][0])
        {
            val[1] = intervals[i][1];
            s.pop();
            s.push(val);
        }
        else
        {
            s.push(intervals[i]);
        }
    }
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        cout << s.top()[0] << " " << s.top()[1] << endl;
        s.pop();
    }
    // cout << s.top()[0] << " " << s.top()[1] << endl;

    return 0;
}