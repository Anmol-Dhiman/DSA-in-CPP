#include <bits/stdc++.h>

#define ll long long int
#define qw priority_queue<int>
#define qwd priority_queue<int, vector<int>, greater<int>>
#define pp pair<int, int>
#define func                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define test  \
    int t;    \
    cin >> t; \
    while (t--)

using namespace std;

float ans_(float dep_rate, float cost, float value, float value_km, float distance)
{
    float ini_dip = (dep_rate * cost)/ 100;
    cost -= ini_dip;
    value = distance * value_km;
    float year = 0;
    while(value < cost)
    {
        value_km += value_km * 0.1;
        value = distance * value_km;
        cost -= ini_dip;
        year++;
    }
    return year - 1;
}

void solve()
{
    float cost, dep_rate, value_km, value, distance;
    cout << "Enter the initial cost of the car." << endl;
    cin >> cost;
    cout << "Enter the depriciation rate." << endl;
    cin >> dep_rate;
    cout << "Enter the value per kilometer." << endl;
    cin >> value_km;
    cout << "Enter the average distance drived." << endl;
    cin >> distance;
    value_km += value_km * 0.1;
    float ans = ans_(dep_rate, cost, value , value_km, distance);
    cout << ans << " Years" << endl;
}

int main()
{
    func
        test
    {
        solve();
    }
    return 0;
}