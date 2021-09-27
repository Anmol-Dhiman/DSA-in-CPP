#include <iostream>
using namespace std;
class student
{
public:
    string name;
    int age;
    int gender;
    // default constructor
    student()
    {
        cout << "default constructor." << endl;
    }
    // parameterized construcotr
    student(string s, int a, int g)
    {
        name = s;
        age = a;
        gender = g;
    }

    // this is the distroucter and it will run after the complition of
    // the whole code to destory the variables that are built
    // and it will run auto maticaly
    ~student()
    {
        cout << "distrouctor" << endl;
    }
    bool operator==(student &a)
    {
        if (name == a.name && age == a.age && gender == a.gender)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    student a("anmol", 19, 1);
    student b("anmol", 19, 1);
    if (a == b)
    {
        cout << "same\n";
    }
    else
    {
        cout << "not same\n";
    }

    return 0;
}