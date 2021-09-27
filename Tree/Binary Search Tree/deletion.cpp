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
node *inordersucc(node *root)
{
    while (root && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
node *deleteion(node *root, int key)
{
    node *temp;
    if (root->data > key)
    {
        root->left = deleteion(root->left, key);
    }
    else if (root->data < key)
    {
        root->right = deleteion(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }
        // here we are replacing the node with the inorder predecessor

        temp = inordersucc(root->left);
        root->data = temp->data;
        root->left = deleteion(root->left, temp->data);
        // here we are replacing the node with the inorder successor
        // temp = inordersucc(root->right);
        // root->data = temp->data;
        // root->right = deleteion(root->right, temp->data);
    }
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
    node *root = insertBST(NULL, 5);

    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);
    insertBST(root, 9);
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
    inorder(root);
    cout << endl;
    root = deleteion(root, 3);
    inorder(root);

    return 0;
}