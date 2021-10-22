#include <iostream>
using namespace std;
class stack
{
public:
    class node
    {
    public:
        int size;
        int first;
        int last;
        int *arr;
    };
    node *temp = new node;
    stack(int n)
    {
        temp->size = n;
        temp->first = -1;
        temp->last = n;
        temp->arr = new int[n];
    }
    void push1(int x)
    {
        temp->arr[++temp->first] = x;
    }
    void push2(int x)
    {
        temp->arr[--temp->last] = x;
    }
    int pop1()
    {
        return temp->arr[temp->first--];
    }
    int pop2()
    {
        return temp->arr[temp->last++];
    }
};

int main()
{
    int n;
    cout << "Enter the number of inputs: ";
    cin >> n;
    stack *temp = new stack(n);
    temp->push1(1);
    temp->push1(2);
    temp->push1(3);
    temp->push2(4);
    temp->push2(5);
    cout << temp->pop1() << endl;
    cout << temp->pop1() << endl;
    cout << temp->pop2() << endl;
}