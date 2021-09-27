#include <iostream>
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
node *insertBST(node *root, int val)
{
    if (root == NULL)
    {
        return new node(val);
    }
    if (val < root->data)
    {
        root->left = insertBST(root->left, val);
    }
    else
    {
        root->right = insertBST(root->right, val);
    }
    return root;
}
// this approach is wrong
bool checking(node *root)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    if (root->left->data < root->data && root->right->data > root->data)
    {
        return true;
    }

    if (checking(root->left) && checking(root->right))
    {
        return true;
    }
    return false;
}
int maximum(node *root, int key)
{
    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }

    if (root->data > key)
    {
        key = root->data;
    }
    int left, right;
    if (root->left != NULL)
    {
        left = maximum(root->left, key);
    }
    if (root->right != NULL)
    {
        right = maximum(root->right, key);
    }
    int temp = max(left, right);
    return max(temp, root->data);
}
// bool isBST(node *root, node *min, int max)
// {
// }
int main()
{
    /*
    Binary Search Tree
            5
          /  \ 
         1    7
          \    \ 
           3    9
          / \
         2   4
    */
    node *root = insertBST(NULL, 5);

    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);
    insertBST(root, 9);
    cout << maximum(root, INT_MIN);
    return 0;
}