#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    node *a = new node;
    node *b = new node;
    node *c = new node;
    a->data = 1;
    a->next = b;

    b->data = 1;
    b->next = c;

    c->data = 1;
    c->next = NULL;
    print(a);

    return 0;
}