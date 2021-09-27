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

node *delet_at_begining(node *head)
{
    return (head = head->next);
}
node *delet_at_end(node *head)
{
    node *p = head;
    while (head->next->next != NULL)
    {
        head = head->next;
    }
    // here we have to free the dynamic memory;
    free(head->next);
   
    head->next = NULL;
    return p;
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
    e->next = NULL;

    print(a);
    a = delet_at_begining(a);
    print(a);

    a = delet_at_end(a);
    print(a);
    return 0;
}