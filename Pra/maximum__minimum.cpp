#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int maxno = INT_MIN;
    int mainno = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        maxno = max(maxno, arr[i]);
        mainno = min(mainno, arr[i]);
    }
    cout << maxno << endl;
    cout << mainno;
    return 0;
}