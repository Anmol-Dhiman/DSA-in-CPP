#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left, *right;
    node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

node *construct(int preorder[], int *preorderInx, int key, int min, int max, int n)
{
    if (*preorderInx >= n)
    {
        return NULL;
    }
    node *root = NULL;
    if (key > min && key < max)
    {
        root = new node(key);

        *preorderInx += 1;
        if (*preorderInx < n)
        {
            root->left = construct(preorder, preorderInx, preorder[*preorderInx], min, key, n);
        }
        if (*preorderInx < n)
        {
            root->right = construct(preorder, preorderInx, preorder[*preorderInx], key, max, n);
        }
    }
    return root;
}
void preorder_print(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder_print(root->left);
    preorder_print(root->right);
}
int main()
{

    int preorder[] = {10, 2, 1, 13, 11};
    int preorderInx = 0;
    node *root = construct(preorder, &preorderInx, 10, INT_MIN, INT_MAX, 5);
    preorder_print(root);

    return 0;
}