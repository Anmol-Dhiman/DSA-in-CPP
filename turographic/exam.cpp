#include <iostream>
using namespace std;
class Question
{
public:
    string question = "";
    string option1 = "";
    string option2 = "";
    string option3 = "";
    string option4 = "";

    void setQuestion(string q)
    {
        question += q;
    }
    void setOption(string a, string b, string c, string d)
    {
        option1 = a;
        option2 = b;
        option3 = c;
        option4 = d;
    }
};

int main()
{

    return 0;
}