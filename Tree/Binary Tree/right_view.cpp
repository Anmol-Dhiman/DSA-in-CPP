#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
void rightView(node *root)
{
    queue<node *> q;
    q.push(root);
    node *temp;
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            temp = q.front();
            q.pop();
            if (i == n - 1)
            {
                cout << temp->data << " ";
            }
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}
void right(node *root)
{
    queue<node *> q;
    node *temp;
    q.push(root);
    q.push(NULL);
    int val;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp != NULL)
        {
            val = temp->data;
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
            cout << val << " ";
        }
    }
    cout << val << " ";
}
int main()
{
    /*
        1
      /  \
      2   3
     / \   \
    4   5   6 
   /
  7
     */
    node *a = new node(1);
    node *b = new node(2);
    node *c = new node(3);
    node *d = new node(4);
    node *e = new node(5);
    node *f = new node(6);
    node *g = new node(7);
    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->right = f;
    d->right = g;
    right(a);

    return 0;
}