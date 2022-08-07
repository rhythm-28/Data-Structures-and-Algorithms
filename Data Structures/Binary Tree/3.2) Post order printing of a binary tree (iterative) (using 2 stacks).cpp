// Post order printing of a binary tree

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
    stack<node *> s1;
    stack<node *> s2;
    s1.push(root);
    while (!s1.empty())
    {
        node *cur = s1.top();
        s1.pop();
        s2.push(cur);

        if (cur->left)
            s1.push(cur->left);
            
        if (cur->right)
            s1.push(cur->right);
    }
    while (!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
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