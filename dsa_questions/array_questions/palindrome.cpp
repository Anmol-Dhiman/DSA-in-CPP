#include <iostream>
using namespace std;
int main()
{
    char arr[100];
    cout << "enter the name: ";
    cin >> arr;
    int count = 0;
    while (arr[count] != '\0')
    {
        count++;
    }
    int i = 0;
    int j = count - 1;
    while (i != j)
    {
        if (arr[i] == arr[j])
        {
            i++;
            j--;
        }
        else
        {
            cout << "this word is not palindrome" << endl;
            return 0;
        }
    }
    cout << "this word is palindrome" << endl;
    return 0;
}