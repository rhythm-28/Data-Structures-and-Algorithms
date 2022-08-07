// In order printing of a binary tree
// TC: O(n)
// SC: O(logn)

#include <bits/stdc++.h>
using namespace std;

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
    if (root == NULL)
        return;

    stack<node *> s;
    node *cur = root;

    while (cur != NULL || !s.empty())
    {
        // left subtree
        while (cur != NULL)
        {
            s.push(cur);
            cur = cur->left;
        }

        // root node
        node *popped = s.top();
        s.pop();
        cout << popped->data << " ";

        // right subtree
        cur = popped->right;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    node *root = create_tree();
    print(root);
    return 0;
}