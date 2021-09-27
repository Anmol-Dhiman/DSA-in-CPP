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
int sumAt(node *root, int level)
{
    if (root == NULL)
    {
        return -1;
    }

    int sum = 0;
    int count = 0;
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    node *temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp != NULL)
        {
            if (count == level)
            {
                sum += temp->data;
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
        else if (!q.empty())
        {
            q.push(NULL);
            count++;
        }
    }
    return sum;
}
int main()
{
    /*
        1
      /  \
      2   3
     / \   \
    4   5   6 
     */
    node *a = new node(1);
    node *b = new node(2);
    node *c = new node(3);
    node *d = new node(4);
    node *e = new node(5);
    node *f = new node(6);
    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->right = f;
    cout << sumAt(a, 2) << endl;
    return 0;
}