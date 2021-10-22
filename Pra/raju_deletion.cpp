#include <iostream>
using namespace std;
void print_arr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void deletion(int arr[], int index, int size)
{
    while (index + 1 != size)
    {
        arr[index] = arr[index + 1];
        index++;
    }
}
int main()
{
    int arr[6];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;

    print_arr(arr, 5);
    deletion(arr, 2, 5);
    print_arr(arr,4);
    return 0;
}