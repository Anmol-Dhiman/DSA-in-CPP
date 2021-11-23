#include <iostream>
#include <stack>
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
// postorder recursive method ---->
void postorder_recursive(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder_recursive(root->left);
    postorder_recursive(root->right);
    cout << root->data << " ";
}
// postorder iterative method --->
void postorder_iterative(node *root)
{
    stack<node *> s;
    node *cur;
    s.push(root);
    stack<int> out;
    while (!s.empty())
    {
        cur = s.top();
        s.pop();
        out.push(cur->data);
        if (cur->left)
        {
            s.push(cur->left);
        }
        if (cur->right)
        {
            s.push(cur->right);
        }
    }
    while (!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
    }
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
    postorder_iterative(a);
    cout << endl;
    postorder_recursive(a);
    cout << endl;
    return 0;
}