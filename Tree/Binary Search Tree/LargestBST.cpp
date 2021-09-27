#include <iostream>
#include <climits>
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
struct info
{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};
info largestBST(node *root)
{
    if (root == NULL)
    {
        return {0, INT_MIN, INT_MAX, 0, true};
    }
    if (root->left == NULL && root->right == NULL)
    {
        return {1, root->data, root->data, 1, true};
    }
    info leftSub = largestBST(root->left);
    info rightSub = largestBST(root->right);
    info current;
    current.size = 1 + leftSub.size + rightSub.size;
    if (leftSub.isBST && rightSub.isBST && leftSub.max < root->data && rightSub.min > root->data)
    {
        current.isBST = true;
        current.min = min(leftSub.min, min(rightSub.min, root->data));
        current.min = max(leftSub.min, max(rightSub.min, root->data));
        current.ans = current.size;
        return current;
    }
    current.ans = max(leftSub.ans, rightSub.ans);
    current.isBST = false;
    return current;
}
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
    info temp = largestBST(root);
    cout << temp.isBST2 << " ";
    return 0;
}