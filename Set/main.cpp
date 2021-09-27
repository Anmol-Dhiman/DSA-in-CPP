// insertion will take O(log n)
// deletion will take O(log n)
// lowerbound and upper bound will take O(log n)
// Lower bound means element having the same key or greater than that.
// Upper bound means greater than that key.
#include <set>
#include <iostream>
using namespace std;
int main()
{
    // it can contain unique elements only
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(4);
    s.erase(3);
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << s.size() << endl;
    for (auto i = s.begin(); i != s.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    // when we add the number is this set then they will automatically arange in deceding order
    set<int, greater<int>> s1;

    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(4);
    s1.insert(4);
    for (auto i : s1)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}