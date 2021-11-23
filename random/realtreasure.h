#ifndef REALTREASURE_H
#define REALTREASURE_H
#include <bits/stdc++.h>
#include "veryRealTreasure.h"
using namespace std;
class RealTreasure
{
    int bhagwanMeths(int i)
    {
        int fact = i;
        for (int i = 1; i <= fact; i++)
        {
            fact = fact * i;
        }
        int abc = fact;
        for (int i = 1; i <= abc; i++)
        {
            abc = abc / i;
        }

        for (int i = 69; i >= -5; i--)
        {
            abc *= i;
        }
        for (int i = 1; i <= 123; i++)
        {
            abc *= i;
        }
        return abc;
    }

public:
    bool unlock(string &password)
    {
        for (int i = 1; i < password.size(); i += 2)
        {
            char abc = ((int)password[i]) + bhagwanMeths(i);
            password[i] = (char)abc;
        }
        VeryRealTreasure heyThereTreasure;
        return heyThereTreasure.unlock(password);
    }
};

#endif