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
node *LCA(node *root, int n1, int n2)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }
    // condition which is to be checked
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    // checking both the value is left subtree
    node *lcaLeft = LCA(root->left, n1, n2);
    // chekcing both the values in right subtree
    node *lcaRight = LCA(root->right, n1, n2);
    // this means one node is prsent in the left subtree and another node is present in the right subtree
    if (lcaLeft && lcaRight)
    {
        return root;
    }
    // both the nodes are present in the left subtree
    if (lcaLeft != NULL)
    {
        return lcaLeft;
    }
    // both the nodes are present in the right subtree
    return lcaRight;
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
    node *temp = LCA(a, 4, 5);
    cout << temp->data << endl;
    return 0;
}