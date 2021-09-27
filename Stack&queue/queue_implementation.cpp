#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};
class queue
{
    node *front;
    node *back;

public:
    queue()
    {
        front = NULL;
        back = NULL;
    }
    void enqueue(int x)
    {
        node *n = new node(x);
        if (front == NULL && back == NULL)
        {
            front = n;
            back = n;
        }
        else
        {
            back->next = n;
            back = n;
        }
    }
    void dequeue()
    {
        if (front == NULL)
        {
            cout << "queue underflow\n";
        }
        else
        {
            node *temp = front;
            front = front->next;
            delete temp;
        }
    }
    int peek()
    {
        if (front == NULL)
        {
            cout << "queue is empty\n";
            return -1;
        }
        return front->data;
    }
    bool isEmpty()
    {
        if (front == NULL && back == NULL)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    cout<<q1.peek();
    return 0;
}