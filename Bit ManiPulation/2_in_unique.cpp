#include <iostream>
using namespace std;
int getbit(int a, int index)
{
    return ((a & (1 << index)) != 0);
}
void unique(int a[], int n)
{
    int xor_sum = 0;
    for (int i = 0; i < n; i++)
    {
        xor_sum = xor_sum ^ a[i];
    }
    int setbit = 0;
    int pos = -1;
    int temp_xor = xor_sum;
    while (setbit != 1)
    {
        setbit = xor_sum & 1;
        pos++;
        xor_sum >> 1;
    }
    int new_xor = 0;
    for (int i = 0; i < n; i++)
    {
        if (getbit(a[i], pos))
        {
            new_xor = new_xor ^ a[i];
        }
    }
    cout << new_xor << endl;
    cout << (temp_xor ^ new_xor) << endl;
}

int main()
{
    int n;
    cout << "enter the number of input";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cout << "enter the number: ";
        cin >> a[i];
    }
    unique(a, n);
    return 0;
}