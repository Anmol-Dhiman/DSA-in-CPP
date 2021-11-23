#ifndef VERY_REAL_TREASURE_H
#define VERY_REAL_TREASURE_H
#include <bits/stdc++.h>
#include "veryVeryRealTreasure.h"
using namespace std;
class VeryRealTreasure
{
public:
    bool unlock(string &password)
    {
        for (int i = 0; i < password.size(); i++)
        {
            password[i] = password[i] ^ 0x69;
        }
        VeryVeryRealTreasure someTreasure;
        return someTreasure.unlock(password);
    }
};

#endif