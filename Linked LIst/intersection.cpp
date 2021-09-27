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
int length(node *head)
{
    int count = 0;
    while (head->next != NULL)
    {
        head = head->next;
        count++;
    }
    return count;
}
int intersection(node *head1, node *head2)
{
    int l1 = length(head1);
    int l2 = length(head2);
    int temp;
    node *num1 = head1;
    node *num2 = head2;
    if (l1 > l2)
    {
        temp = l1 - l2;
        while (temp)
        {
            num1 = num1->next;
            temp--;
        }
    }
    else
    {
        temp = l2 - l1;
        while (temp)
        {
            num2 = num2->next;
            temp--;
        }
    }
    while (num1->next != NULL && num2->next != NULL)
    {
        num1 = num1->next;
        num2 = num2->next;
        if (num1 == num2)
        {
            return num1->data;
        }
    }
    return -1;
}
int main()
{
    node *a = new node;
    node *b = new node;
    node *c = new node;
    node *d = new node;
    node *e = new node;
    node *f = new node;
    node *g = new node;
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

    f->data = 6;
    f->next = g;

    g->data = 7;
    g->next = d;

    print(a);
    print(f);
    cout << intersection(a, f) << endl;
    return 0;
}