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
node *append(node *head, int k)
{
    int num = 1;
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
        num++;
    }
    temp->next = head;
    int num2 = num - k - 1;
    node *temp2 = head;
    while (num2)
    {
        temp2 = temp2->next;
        num2--;
    }
    temp = temp2->next;
    temp2->next = NULL;
    return temp;
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
    a = append(a, 2);
    print(a);
    return 0;
}