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
int solve(node *root)
{
    if (root == NULL)
        return 0;
    int a = solve(root->left);
    int b = solve(root->right);
    int x = root->data;
    root->data = a + b;
    return a + b + x;
}
void chainging_tree(node *root)
{
    solve(root);
}
void inorder_recursive(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder_recursive(root->left);
    cout << root->data << " ";
    inorder_recursive(root->right);
}
int main()
{
    /*
        1f
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
    inorder_recursive(a);
    cout << endl;
    chainging_tree(a);
    inorder_recursive(a);

    return 0;
}