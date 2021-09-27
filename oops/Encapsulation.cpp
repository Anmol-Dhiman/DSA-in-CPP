// hiding sensitive data from the user
// use of the access modifier is lies into the encapsulation

#include <iostream>
using namespace std;
class temp
{
public:
    void FunA()
    {
        cout << "I am in the public\n";
    }

private:
    void FunB()
    {
        cout << "I am in the private\n";
    }
    // protected can be used in the other class but not in the main function
    
protected:
    void FunC()
    {
        cout << "I am in the protected\n";
    }
};
int main()
{
    temp A;
    A.FunA();
    // we can not access these two funcitons as
    // these are from private and protected access modifires.
    // A.FunB();
    // A.FunC();
    return 0;
}