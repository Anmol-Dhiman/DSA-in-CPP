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
    // multiset can store the identicals values also
    multiset<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;
    // this will delete all the values equal to the given input value
    s.erase(3);
    // this find function will reutrn the address of first place where it will find the given value
    // and then erase function will delete the value
    s.erase(s.find(3));


    return 0;
}