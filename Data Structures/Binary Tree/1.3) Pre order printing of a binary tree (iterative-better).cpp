// Pre order printing of a binary tree
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
        while (cur != NULL)
        {
            cout << cur->data << " ";
            if (cur->right)
                s.push(cur->right);

            cur = cur->left;
        }

        if (!s.empty())
        {
            cur = s.top();
            s.pop();
        }
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