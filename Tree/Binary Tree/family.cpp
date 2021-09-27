#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    string data;

    node *right;
    node *left;

    node(string x)
    {
        data = x;
        right = NULL;
        left = NULL;
    }
};
void traversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    node *temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp != NULL)
        {
            cout << temp->data << endl;
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}
int main()
{
    node *a = new node("Prem Singh");
    node *b = new node("Rammehar");
    node *c = new node("Anmol");
    node *d = new node("Rambir");
    a->right = b;
    a->left = d;
    b->right = c;
    traversal(a);
    return 0;
}