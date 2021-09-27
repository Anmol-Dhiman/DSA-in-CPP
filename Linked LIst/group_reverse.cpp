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
node *reverse(node *head, int k)
{
    node *p = NULL;
    node *r = head;
    node *q;
    int count = 0;
    while (r != NULL && count < k)
    {
        q = r->next;
        r->next = p;
        p = r;
        r = q;
        count++;
    }
    if (r != NULL)
    {
        head->next = reverse(r, k);
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
    node *f = new node;
    a->data = 1;
    a->next = b;

    b->data = 2;
    b->next = c;

    c->data = 3;
    c->next = d;

    d->data = 4;
    d->next = e;

    e->data = 5;
    e->next = f;
    
    f->data = 6;
    f->next = NULL;

    int k;

    print(a);
    cout << "Enter the value of K:";
    cin >> k;
    a = reverse(a, k);
    print(a);
    return 0;
}