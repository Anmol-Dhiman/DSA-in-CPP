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

// bool detect(node *head)
// {
//     node *p = head;

//     node *r = head;
//     do
//     {
//         r = r->next->next;
//         p = p->next;
//     } while (p != r && p != NULL);
//     if (p == NULL)
//     {
//         return false;
//     }
//     return true;
// }
bool detect2(node *head)
{
    node *fast = head;
    node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

void delete_cycle(node *head)
{

    node *fast = head;
    node *slow = head;
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
            slow->next = NULL;
            return;
        }
    }
    if (fast == NULL || fast->next == NULL)
    {
        return ;
    }
    fast = head;
    while (fast->next != slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
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
    e->next = NULL;

    // print(a);
    if (detect2(a))
    {
        cout << "ture" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    delete_cycle(a);
    print(a);

    return 0;
}