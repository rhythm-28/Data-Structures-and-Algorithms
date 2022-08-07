// Convert a BST into Balanced BST
// without creating new nodes

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

node *insert_in_bst(node *root, int d)
{
    if (root == NULL)
        return new node(d);

    if (d <= root->data)
        root->left = insert_in_bst(root->left, d);

    else
        root->right = insert_in_bst(root->right, d);

    return root;
}

node *create_tree()
{
    int d;
    cin >> d;

    node *root = NULL;
    while (d != -1)
    {
        root = insert_in_bst(root, d);
        cin >> d;
    }
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

void find(node *root, vector<node *> &a)
{
    if (!root)
        return;
    find(root->left, a);
    a.push_back(root);
    find(root->right, a);
}

node *create(vector<node *> &a, int l, int h)
{
    if (l > h)
        return NULL;

    int mid = l + ((h - l) / 2);
    node *root = a[mid];

    root->left = create(a, l, mid - 1);
    root->right = create(a, mid + 1, h);

    return root;
}

node *balanceBST(node *root)
{
    vector<node *> a;
    find(root, a);
    return create(a, 0, a.size() - 1);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    node *root = create_tree();
    print(root);
    cout << endl;
    root = balanceBST(root);
    print(root);
    return 0;
}