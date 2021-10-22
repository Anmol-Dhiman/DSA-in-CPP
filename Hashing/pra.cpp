#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main()
{
    bool temp = true;
    set<int> s;
    s.insert(2);
    s.insert(1);
    s.insert(6);
    s.insert(4);
    set<int>::iterator itr;
    for (itr = s.begin(); itr != s.end(); itr++)
    {
        cout << *itr;
    }
    return 0;
}