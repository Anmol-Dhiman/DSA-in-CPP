#include <iostream>
using namespace std;
int main()
{
    int i = 1;
    int j = 2;
    cout << (i & (1 << j));
    return 0;
}