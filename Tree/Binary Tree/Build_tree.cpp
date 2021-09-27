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
int search(int inorder[], int current, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == current)
        {
            return i;
        }
    }
    return -1;
}
node *buildtree(int preorder[], int inorder[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    static int index = 0;
    int current = preorder[index];
    index++;
    int position = search(inorder, current, start, end);
    node *root = new node(current);
    if (start == end)
    {
        return root;
    }

    root->left = buildtree(preorder, inorder, start, position - 1);
    root->right = buildtree(preorder, inorder, position + 1, end);
    return root;
}
node *builtTree_post_in(int postorder[], int inorder[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    static int index = end;
    int current = postorder[index];
    index--;
    int position = search(inorder, current, start, end);
    node *root = new node(current);
    if (start == end)
    {
        return root;
    }

    root->right = builtTree_post_in(postorder, inorder, position + 1, end);
    root->left = builtTree_post_in(postorder, inorder, start, position - 1);
    return root;
}
void inorder_travel(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder_travel(root->left);
    cout << root->data << " ";
    inorder_travel(root->right);
}
int main()
{
    // 4 2 5 1 3 6
    // 1 2 4 5 3 6
    int postorder[] = {4, 5, 2, 6, 3, 1};
    int inorder[] = {4, 2, 5, 1, 3, 6};
    node *root = builtTree_post_in(postorder, inorder, 0, 5);
    inorder_travel(root);
    return 0;
}