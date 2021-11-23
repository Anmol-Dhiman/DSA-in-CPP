#ifndef VERY_VERY_REAL_TREASURE_H
#define VERY_VERY_REAL_TREASURE_H
#include <bits/stdc++.h>
using namespace std;
class VeryVeryRealTreasure
{
private:
    int treasure[47] = {0xf, 0x5, 0x8, 0xe, 0x12, 0xa, 0x5d, 0x27, 0x1c, 0x59, 0x24, 0x36, 0x2f, 0x5d, 0x5f, 0x1d, 0x36, 0x5c, 0x7, 0x5d, 0x2, 0x2c, 0x5c, 0x36, 0x27, 0x5a, 0x3f, 0x5a, 0x1b, 0x36, 0x2a, 0x58, 0x59, 0x3e, 0x20, 0xa, 0x31, 0x5, 0x5e, 0x4, 0x3f, 0xa, 0x20, 0x14, 0x5e, 0x3e, 0x14};

public:
    bool unlock(string &password)
    {
        for (int i = 0; i < password.size(); i++)
        {
            if ((int)password[i] != treasure[i])
                return false;
        }
        return true;
    }
};

#endif