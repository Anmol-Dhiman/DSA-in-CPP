#include <iostream>
using namespace std;
class A
{
   
    A &operator=(const A &t)
    {
        cout << "aur bhi ladlae kae haal h " << endl;
        return *this;
    }
};
int main()
{
    A t1, t2;

    t2 = t1;
    return 0;
}