// here we will se two function one which convert the tree into its mirror image and the other will generate then tree as the mirror image
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
// this is the function which converts the tree into its mirror image
void mirror_image(node *root)
{
    if (root == NULL)
    {
        return;
    }
    // we will first change the left subtree and then the right subtree
    mirror_image(root->left);
    mirror_image(root->right);
    // this is the logic
    swap(root->left, root->right);
}


// here is the code which generates the new tree
// we need the root address of the new tree so we use the mirror pointer
void mirro_tree(node *root, node **mirror)
{
    if (root == NULL)
    {
        mirror = NULL;
        return;
    }
    // new node has been built and the data is set 
    *mirror = new node(root->data);
    // now we give the left value of vase tree into the right side of the new tree
    mirro_tree(root->left, &((*mirror)->right));
    // and here we give the right value of the base tree into the left side of the new tree
    mirro_tree(root->right, &((*mirror)->left));
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
    // before any change
    inorder(a);
    cout << endl;

    // new tree bulit
    node *mirror = NULL;
    mirro_tree(a, &mirror);
    inorder(mirror);
    cout << endl;

    // the base tree has been changed
    mirror_image(a);
    inorder(a);
    cout << endl;
    return 0;
}