#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int Number_of_Activity(vector<vector<int>> v)
{
    int count = 1;
    // here we use the merge sort for sorting in the assending order of the end time
    // [] is the lambda funciton
    sort(v.begin(), v.end(), [](vector<int> &a, vector<int> &b)
         { return a[1] < b[1]; });
    int end = v[0][1];
    // if the starting time of the next activity is greator then the ending time
    // of the first activity then we can do that activity and our count for number
    // of activity will increase
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i][0] > end)
        {
            end = v[i][1];
            count++;
        }
    }
    return count;
}
int main()
{
    // taking the input of number of start and end cases
    int n;
    cout << "enter the number of input: ";
    cin >> n;
    // taking the input of start and end time in a vector which stors vector
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        int start;
        int end;
        cout << "Enter the starting time: ";
        cin >> start;

        cout << "Enter the ending time: ";
        cin >> end;

        v.push_back({start, end});
    }
    cout << Number_of_Activity(v) << endl;
    return 0;
}