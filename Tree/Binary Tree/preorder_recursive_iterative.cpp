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
// the preorder recursive method -->
void preorder_recursive(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder_recursive(root->left);
    preorder_recursive(root->right);
}
// the preorder iterative method --->
void preorder_iterative(node *root)
{
    stack<node *> s;
    s.push(root);
    node *curr;
    // we will enter the value in stack in such a way that we get the left subtree first by stack.top() and then rightsubtree
    while (!s.empty())
    {
        // from s.top() we get the leftsubtree first
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        // enter the right tree then left tree as we are using stack 
        if (curr->right)
        {
            s.push(curr->right);
        }
        if (curr->left)
        {
            s.push(curr->left);
        }
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
    preorder_iterative(a);
    cout << endl;
    preorder_recursive(a);
    cout << endl;
    return 0;
}