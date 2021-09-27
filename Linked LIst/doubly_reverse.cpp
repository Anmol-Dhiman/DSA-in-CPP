#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
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
node *reverse(node *head)
{
    node *temp = head;
    node *p = NULL;
    while (temp != NULL)
    {
        temp->prev = temp->next;
        temp->next = p;
        p=temp;
        temp = temp->prev;
    }
    return p;
}

int main()
{
    node *a = new node;
    node *b = new node;
    node *c = new node;
    node *d = new node;
    node *e = new node;
    a->prev = NULL;
    a->data = 1;
    a->next = b;

    b->prev = a;
    b->data = 2;
    b->next = c;

    c->prev = b;
    c->data = 3;
    c->next = d;

    d->prev = c;
    d->data = 4;
    d->next = e;

    e->prev = d;
    e->data = 5;
    e->next = NULL;
    print(a);
    a = reverse(a);
    print(a);
    return 0;
}