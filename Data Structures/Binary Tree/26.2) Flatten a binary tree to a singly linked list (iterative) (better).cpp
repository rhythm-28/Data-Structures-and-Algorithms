// Flatten a binary tree to a singly linked list (better)
// TC: O(n)
// SC: O(1)

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

void flatten(node *root)
{
    node *cur = root;
    node *prev;
    while (cur != NULL)
    {
        if (cur->left != NULL)
        {
            prev = cur->left;
            while (prev->right != NULL)
            {
                prev = prev->right;
            }
            prev->right = cur->right;
            cur->right = cur->left;
            cur->left = NULL;
        }
        cur = cur->right;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    node *root = create_tree();
    flatten(root);
    print(root);
    return 0;
}