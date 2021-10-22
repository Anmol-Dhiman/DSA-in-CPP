#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int arr[4];
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << size;
    return 0;
}