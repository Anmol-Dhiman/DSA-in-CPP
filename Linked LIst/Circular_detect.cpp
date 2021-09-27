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
    cout << endl;
}
bool circular(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        if (temp == head)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    node *a = new node;
    node *b = new node;
    node *c = new node;
    node *d = new node;
    node *e = new node;
    a->data = 1;
    a->next = b;

    b->data = 2;
    b->next = c;

    c->data = 3;
    c->next = d;

    d->data = 4;
    d->next = e;

    e->data = 5;
    e->next = a;

    // print(a);
    if (circular(a))
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }

    return 0;
}