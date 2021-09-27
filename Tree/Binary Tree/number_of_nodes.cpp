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
int number_of_nodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return number_of_nodes(root->left) + number_of_nodes(root->right) + 1;
}
int sumNodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return sumNodes(root->left) + sumNodes(root->right) + root->data;
}
int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}
int diameter(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max((height(root->left) + height(root->right) + 1), max(diameter(root->left), diameter(root->right)));
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
    cout << number_of_nodes(a) << endl;
    cout << sumNodes(a) << endl;
    cout << height(a) << endl;
    cout << diameter(a) << endl;
    return 0;
}