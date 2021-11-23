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
int counting_number_of_node(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return counting_number_of_node(root->left) + counting_number_of_node(root->right) + 1;
}
int sum_of_all_nodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return sum_of_all_nodes(root->left) + sum_of_all_nodes(root->right) + root->data;
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
    cout << counting_number_of_node(a) << endl;
    cout << sum_of_all_nodes(a);
    return 0;
}