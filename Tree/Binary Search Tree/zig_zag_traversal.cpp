#include <iostream>
#include <stack>
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
void zigzagTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    // two stacks are used firstly we inset the elements in currentLevl and then we remove it one by one and their left and right nodes in the
    // nextLevl stack we store it from left to right if leftToright is true and store right to left if leftToright is false.
    
    stack<node *> currentLevl;
    stack<node *> nextLevl;
    currentLevl.push(root);
    node *temp;
    bool leftToright = true;
    while (!currentLevl.empty())
    {
        temp = currentLevl.top();
        currentLevl.pop();
        if (temp)
        {
            cout << temp->data << " ";
            if (leftToright)
            {

                if (temp->left)
                {
                    nextLevl.push(temp->left);
                }
                if (temp->right)
                {
                    nextLevl.push(temp->right);
                }
            }
            else
            {
                if (temp->right)
                {
                    nextLevl.push(temp->right);
                }
                if (temp->left)
                {
                    nextLevl.push(temp->left);
                }
            }
        }
        if (currentLevl.empty())
        {
            leftToright = false;
            swap(nextLevl, currentLevl);
        }
    }
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
    zigzagTraversal(root);
    return 0;
}