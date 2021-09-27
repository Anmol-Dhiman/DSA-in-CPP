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

node *first_node(node *head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            break;
        }
        if (slow->next == head)
        {
            return head;
        }
    }
    if (fast == NULL || fast->next == NULL)
    {
        return NULL;
    }
    fast = head;
    while (fast->next != slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow->next;
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
    e->next = a;
    node *val = first_node(a);
    if (val == NULL)
    {
        cout << "there is not any loop\n";
    }
    else
    {
        cout << "loop starts at " << val->data << endl;
    }

    return 0;
}