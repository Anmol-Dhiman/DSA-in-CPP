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
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    node *lcaLeft = LCA(root->left, n1, n2);
    node *lcaRight = LCA(root->right, n1, n2);
    if (lcaLeft && lcaRight)
    {
        return root;
    }
    if (lcaLeft != NULL)
    {
        return lcaLeft;
    }
    return lcaRight;
}

int findDistance(node *root, int key, int distance)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == key)
    {
        return distance;
    }
    int l1 = findDistance(root->left, key, distance + 1);
    if (l1 != -1)
    {
        return l1;
    }
    return findDistance(root->right, key, distance + 1);
}
int distance(node *root, int n1, int n2)
{
    root = LCA(root, n1, n2);
    if (root == NULL)
    {
        return -1;
    }
    int l1 = findDistance(root, n1, 0);
    int l2 = findDistance(root, n2, 0);
    return l1 + l2;
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
    cout << distance(a, 4, 5) << endl;
    return 0;
}