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

void insert(int arr[], int index, int value, int size)
{
    while (size != index)
    {
        arr[size] = arr[size - 1];
        size--;
    }
    arr[size] = value;
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
    insert(arr, 2, 6, 5);
    print_arr(arr, 6);
    return 0;
}