#include <iostream>
using namespace std;

void towerofHanoi(int n, char src, char helper, char dst)
{
    if (n == 0)
    {
        return;
    }
    towerofHanoi(n - 1, src, dst, helper);
    cout << "Moving from " << src << " to " << dst << endl;
    towerofHanoi(n - 1, helper, src, dst);
}
int main()
{
    int n;
    cout << "enter the number of disk: ";
    cin >> n;
    towerofHanoi(n, 'A', 'B', 'C');
    return 0;
}