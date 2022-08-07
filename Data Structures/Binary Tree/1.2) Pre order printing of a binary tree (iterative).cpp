// Pre order printing of a binary tree

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
    s.push(root);
    while (!s.empty())
    {
        node *cur = s.top();
        cout << cur->data << " ";
        s.pop();
        if (cur->right)
            s.push(cur->right);
        if (cur->left)
            s.push(cur->left);
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