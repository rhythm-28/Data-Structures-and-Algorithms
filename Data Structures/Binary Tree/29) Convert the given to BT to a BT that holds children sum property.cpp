// Convert the given to BT to a BT that holds children sum property
// allowed to increase node's value
// not allowed to decrease node's value
// TC: O(N)
// SC: O(H)

#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define pii pair<lli, lli>

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *create_tree()
{
    int d;
    cin >> d;
    if (d == -1)
        return NULL;
    node *root = new node(d);
    root->left = create_tree();
    root->right = create_tree();
    return root;
}

void print(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    node *a;
    while (!q.empty())
    {
        a = q.front();

        if (a == NULL)
        {
            cout << endl;
            q.pop();

            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            // pop
            q.pop();

            // print
            cout << a->data << " ";

            // push children
            if (a->left != NULL)
                q.push(a->left);

            if (a->right != NULL)
                q.push(a->right);
        }
    }
}

void convert(node *root)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        return;

    int childSum = 0;
    if (root->left)
        childSum += root->left->data;
    if (root->right)
        childSum += root->right->data;

    if (root->data > childSum)
    {
        if(root->left)
        root->left->data = root->data;
        if(root->right)
        root->right->data = root->data;
    }
    convert(root->left);
    convert(root->right);
    int left = 0, right = 0;
    if (root->left)
        left = root->left->data;
    if (root->right)
        right = root->right->data;
    root->data = left + right;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    node *root = create_tree();
    print(root);
    cout << endl;
    convert(root);
    print(root);
    return 0;
}