// when a class is derived from the other class is called inheritence
// we need to mention the access modifers before declearing any variable or making any function
#include <iostream>
using namespace std;
class A
{
public:
    void temp1()
    {
        cout << "i am in the class A\n";
    }
};
class B : public A
{
public:
    void temp2()
    {
        cout << "I am in the class B\n";
    }
};

int main()
{
    B val;
    val.temp1();
    val.temp2();
    return 0;
}