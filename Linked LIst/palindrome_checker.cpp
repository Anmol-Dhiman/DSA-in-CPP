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
node *reverse(node *head)
{
    node *current = head;
    node *prev = NULL, *next = NULL;

    while (current != NULL)
    {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
bool checker(node *head)
{
    node *temp = reverse(head);
    while (temp->next != NULL)
    {
        if (temp->data != head->data)
        {
            return false;
        }
        temp = temp->next;
        head = head->next;
    }
    return true;
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

    c->data = 1;
    c->next = NULL;

    // d->data = 4;
    // d->next = e;

    // e->data = 5;
    // e->next = NULL;

    print(a);
    cout << checker(a) << endl;
    return 0;
}