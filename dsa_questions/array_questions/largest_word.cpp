// to be asked
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter the number of alphabets: ";
    cin >> n;
    cin.ignore();

    char a[n + 1];
    cout << "enter the string: ";
    cin.getline(a, n);
    cin.ignore();
    int max_length = INT_MIN;
    int front = 0;
    int end = 0;
    while (1)
    {
        while (a[end] != ' ' && a[end] != '\0')
        {
            end++;
        }
        max_length = max(max_length, end - front);
        while (a[end] == ' ')
        {
            end++;
        }
        front = end;
    }
    cout << "the maximum lenth is " << max_length << endl;
    cout << front << end;
    return 0;
}