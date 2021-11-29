#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<pair<int, int>> a;
    a.push_back({1, 2});
    a.push_back({23, 24});
    pair<int, int> p;
    p = a.front();
    a.pop_back();

    p = a.front();
    a.pop_back();
    cout << p.first;
    return 0;
}