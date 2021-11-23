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
// height of a tree ---> the length from the root to the deepest leaf node
int height(node *root)
{
    // the base case 
    if (root == NULL)
    {
        return 0;
    }
    // we just find the height of left subtree and height of right subtree and find the maximum between them and add 1 to them for the root

    return max(height(root->left), height(root->right)) + 1;
}
//diameter of the tree ---> the nodes between two farthest leaf node
int diameter(node *root)
{
    // the base case
    if (root == NULL)
    {
        return 0;
    }
    // if the root node is included in the path of two farthest leaf nodes then the diameter will be the height of left subtree and the height of the right subtree +1 (for the root node)
    int left_height = height(root->left);
    int right_height = height(root->right);
    // if the root node does not include in the path then we will find the diametere in left and right subtrees and return the max of it
    int left_diameter = diameter(root->left);
    int right_diameter = diameter(root->right);
    return max(max(left_diameter, right_diameter), left_height + right_height + 1);
    
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
    inorder(a);
    mirror_image(a);
    cout << endl;
    inorder(a);
    cout << endl;
    cout << height(a) << endl;

    cout << diameter(a);
    return 0;
}