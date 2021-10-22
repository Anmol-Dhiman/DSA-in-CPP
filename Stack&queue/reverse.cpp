#include <iostream>
using namespace std;
class stack
{
public:
    class node
    {
    public:
        int size;
        int top;
        char *arr;
    };
    node *temp = new node;
    stack(int n)
    {
        temp->size = n;
        temp->top = -1;
        temp->arr = new char[n];
    }
    void push(char a)
    {
        temp->arr[++temp->top] = a;
    }
    char pop()
    {
        return temp->arr[temp->top--];
    }
};

int main()
{
    string S = "GeeksforGeeks";
    // stack *temp = new stack(S.length());
    // string s = "";
    // for (int i = 0; i < S.length(); i++)
    // {
    //     temp->push(S[i]);
    // }
    // for (int i = 0; i < S.length(); i++)
    // {
    //     s=s + temp->pop();
    // }
    // cout << s;
    char s[S.length()];
    int index = 0;
    for (int i = S.length() - 1; i >= 0; i--)
    {
        s[index] = S[i];
        index++;
    }
    for (int i = 0; i < S.length(); i++)
    {
        cout << s[i];
    }
    return 0;
}