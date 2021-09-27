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
int length(node *head)
{
    int count = 1;
    while (head->next != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
node *adding(node *first, node *second)
{
    first = reverse(first);
    node *temp = first;
    second = reverse(second);
    
    int count = 0;
    while (second != NULL)
    {
        if (first->data + second->data + count > 9)
        {
            first->data = first->data + second->data - 10 + count;
            count = 1;
        }
        else
        {
            first->data = first->data + second->data + count;
            count = 0;
        }
        second = second->next;
        first = first->next;
    }
    first->data += count;
    first = reverse(temp);
    return first;
}
node *add(node *head1, node *head2)
{
    int l1 = length(head1);
    int l2 = length(head2);
    node *temp;
    if (l1 > l2)
    {
        temp = adding(head1, head2);
    }
    else
    {
        temp = adding(head2, head1);
    }
    return temp;
}

int main()
{
    node *a = new node;
    node *b = new node;
    node *c = new node;
    node *d = new node;
    node *e = new node;
    a->data = 3;
    a->next = b;

    b->data = 4;
    b->next = c;

    c->data = 5;
    c->next = NULL;

    d->data = 4;
    d->next = e;

    e->data = 5;
    e->next = NULL;

    print(a);
    print(d);
    a = add(a, d);
    print(a);
    return 0;
}