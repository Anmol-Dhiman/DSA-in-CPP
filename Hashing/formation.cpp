#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main()
{
    // map<key data type,value data type> variable name
    map<int, int> temp;
    int arr[5];
    cout << "temp" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the value: ";
        cin >> arr[i];
    }
    for (int i = 0; i < 5; i++)
    {
        //    the value in Hash table starts form 0
        temp[arr[i]]++;
    }
    // this is used to traverse the map or hash table
    map<int, int>::iterator it;
    for (it = temp.begin(); it != temp.end(); it++)
    {
        cout << "The frequency is : "<<it->second << endl;
    }
    return 0;
}
