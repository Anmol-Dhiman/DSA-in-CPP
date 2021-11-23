#include <iostream>
using namespace std;
class temp
{
    int a = 1;
};
class temp2 : public temp
{
public:
    int b = 1;
    void print()
    {

        cout << b << endl;
        cout << super.a << endl;
    }
};
int main()
{
    temp2 a;

    return 0;
}