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
void remove(node *head)
{
    node *temp;
  
    while (head->next != NULL)
    {

        if (head->next->data == head->data)
        {
            temp = head->next;
            head->next = head->next->next;
            free(temp);
        }
        else
        {
            head = head->next;
        }
    }
 
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

    c->data = 2;
    c->next = d;

    d->data = 4;
    d->next = e;

    e->data = 4;
    e->next = NULL;
    print(a);
    remove(a);
    print(a);
    return 0;
}