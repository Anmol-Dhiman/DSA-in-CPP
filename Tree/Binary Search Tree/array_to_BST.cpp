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
        left == NULL;
        right == NULL;
    }
};
node *builtBST(int arr[], int start, int end)
{
    // find the mid of the array and make the node
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    node *root = new node(arr[mid]);
    root->left = builtBST(arr, start, mid - 1);
    root->right = builtBST(arr, mid + 1, end);
    return root;
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
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    node *root = builtBST(arr, 0, 4);
    inorder(root);
    return 0;
}