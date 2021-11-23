#include <iostream>
#include <bits/stdc++.h>
#include "realtreasure.h"
#include "veryRealTreasure.h"
#include "veryVeryRealTreasure.h"
using namespace std;

class Treasure
{
public:
    bool unlock(string &password)
    {
        password = "flag{" + password;
        password += "}";
       
        if (password.size() != 47)
            return false;
        int i = 0;
        for (i = 0; i < 5; i++)
        {
            password[i] = password[i];
        }
        for (; i < 10; i += 3)
        {
            password[i] = char(((int)password[i] + 69 % 26));
        }
        for (i = 45; i >= 33; i--)
        {
            password[i] = char(((int)password[i] + 420 % 26));
        }
        RealTreasure bigTreasure;
        return bigTreasure.unlock(password);
    }
};

int main()
{
    Treasure smallTreasure;
    string key = "lgRN0_4t54E_33_1S_hi_yS";
    cout << "Enter the key to unlock the treasure " << endl;

    if (smallTreasure.unlock(key))
        cout << "Congratulation You've reached the treasure" << endl;
    else
    {
        cout << "Sorry! You don't have what it takes :(" << endl;
    }

    return 0;
}