#include <bits/stdc++.h>
using namespace std;
long long evalutae(string &str, int val)
{
    long long ans = (str[0] -'0')* pow(val, str[3] -'0');
    int i = 4;
    while (i != str.length())
    {
        if (str[i] == '+')
        {
            ans += str[i + 1] * pow(val, str[i + 4] -'0');
            i += 5;
        }
        else
        {
            ans -= (str[i + 1] -'0') * pow(val, str[i + 4] -'0');
            i += 5;
        }
    }
    return ans;
}
int main()
{

    string str = "2x^3 + 1x^1 + 3x^2";
    int val = 2;
    evalutae(str, 2);
    return 0;
}