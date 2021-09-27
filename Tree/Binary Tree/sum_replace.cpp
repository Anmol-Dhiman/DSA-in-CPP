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
int sum(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return sum(root->left) + sum(root->right) + root->data;
}
void change(node *root)
{
    static int temp = sum(root);
    if (root == NULL)
    {
        return;
    }
    change(root->left);
    root->data = temp;
    change(root->right);
}
void sum_change(node *root)
{
    if (root == NULL)
    {
        return;
    }
    sum_change(root->left);
    sum_change(root->right);
    if (root->left != NULL)
    {
        root->data += root->left->data;
    }
    if (root->right != NULL)
    {
        root->data += root->right->data;
    }
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}
bool balanced_height(node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (balanced_height(root->left) == false)
    {
        return false;
    }

    if (balanced_height(root->right) == false)
    {
        return false;
    }
    int l1 = height(root->left);
    int l2 = height(root->right);
    if (abs(l1 - l2) <= 1)
        return true;
    return false;
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
    // sum_change(a);
    // inorder(a);
    cout << height(a) << endl;
    cout << balanced_height(a) << endl;
    return 0;
}