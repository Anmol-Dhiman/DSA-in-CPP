#include <iostream>
using namespace std;

int occurance(int arr[], int n)
{
    int maxNum = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxNum)
        {
            maxNum = arr[i];
        }
    }
    int b[maxNum + 1];
    for (int i = 0; i < maxNum + 1; i++)
    {
        b[i] = -1;
    }
    int minOcuur = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (b[arr[i]] == -1)
        {
            b[arr[i]] = i;
        }
        else
        {
            if (b[arr[i]] < minOcuur)
            {
                minOcuur = b[arr[i]];
            }
        }
    }
    if (minOcuur == INT_MAX)
    {
        return 0;
    }
    return minOcuur;
}
int main()
{
    int n;
    cout << "enter the number of input:";
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << occurance(a, n);
    return 0;
}