#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    long long data;
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
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
int add(node *head)
{
    int l = length(head) - 1;

    long long sum = 0;
    while (head != NULL)
    {
        sum += (head->data * pow(10, l));
        l--;
        head = head->next;
    }
    return sum + 1;
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

node *add1(node *head)
{
    node *temp = reverse(head);
    node *temp2 = temp;
    while (temp != NULL)
    {
        if (temp->data == 9 && temp->next != NULL)
        {
            temp->data = 0;
            temp = temp->next;
        }
        else
        {
            temp->data++;
            break;
        }
    }
    return head = reverse(temp2);
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
    cout << add(a) << endl;

    return 0;
}