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
node *insert_at_begining(node *head, int val)
{
    
    node *temp = new node;
    temp->data = val;
    temp->next = head;
    return temp;
}
node *insert_at_end(node *head, int val)
{
    node *p = head;

    while (head->next != NULL)
    {
        head = head->next;
    }
    node *temp = new node;
    temp->data = val;
    head->next = temp;
    temp->next = NULL;
    return p;
}

node *insert_at_index(node *head, int val, int index)
{
    node *p = head;
    node *temp = new node;
    temp->data = val;
    int n = 0;
    while (n != index - 1)
    {
        head = head->next;
        n++;
    }
    temp->next = head->next;
    head->next = temp;
    return p;
}

node *insert_by_value(node *head, int val, int check)
{
    node *p = head;
    node *temp = new node;
    temp->data = val;
    while (head->next->data != check && head->next != NULL)
    {
        head = head->next;
    }
    if (head->next->data == check)
    {
        temp->next = head->next;
        head->next = temp;
    }

    return p;
}

int main()
{
    node *a = new node;
    node *b = new node;
    node *c = new node;
    a->data = 1;
    a->next = b;

    b->data = 2;
    b->next = c;

    c->data = 3;
    c->next = NULL;

    print(a);
    a = insert_at_begining(a, 4);
    print(a);

    a = insert_at_end(a, 5);
    print(a);

    a = insert_at_index(a, 6, 2);
    print(a);

    a = insert_by_value(a, 7, 6);
    print(a);
    return 0;
}