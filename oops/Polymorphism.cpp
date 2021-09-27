#include <iostream>
using namespace std;
// this is function overloading.
class A
{
public:
    void fun()
    {
        cout << "i am in the class A\n";
    }
    void fun(int x)
    {
        cout << "i am in the class A and my value is " << x << endl;
    }
    void fun(string a)
    {
        cout << "i am in the class A and my name is " << a << endl;
    }
};
int main()
{
    A temp;
    temp.fun();
    temp.fun(3);
    temp.fun("anmol");
    return 0;
}