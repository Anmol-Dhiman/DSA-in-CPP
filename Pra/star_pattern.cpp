#include <iostream>
using namespace std;
int main()
{
    int row;
    int column;
    cout << "enter the row and column respectively:";
    cin >> row;
    cin >> column;
    for (int i = 1; i <= row; i++)
    {
        if (i == 1 || i == row)
        {
            for (int j = 1; j <= column; j++)
            {
                cout << "* ";
            }
            cout << endl;
        }
        else
        {
            for (int j = 1; j <= column; j++)
            {
                if (j == 1 || j == column)
                {
                    cout << "* ";
                }
                else
                {
                    cout << "  ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}