// Boundary Traversal of binary tree

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

void leftBoundary(node *root, vector<node *> &left)
{
    left.push_back(root);
    node *parent = NULL;
    node *cur = root->left;
    while (cur != NULL)
    {
        while (cur != NULL)
        {
            left.push_back(cur);
            parent = cur;
            cur = cur->left;
        }
        if (parent != NULL)
            cur = parent->right;
    }
}

void leafNodes(node *root, vector<node *> &leaf)
{
    if (!root)
        return;

    if (!root->left && !root->right)
    {
        leaf.push_back(root);
        return;
    }
    leafNodes(root->left, leaf);
    leafNodes(root->right, leaf);
}

void rightBoundary(node *root, vector<node *> &right)
{
    node *parent = NULL;
    node *cur = root->right;
    while (cur != NULL)
    {
        while (cur != NULL)
        {
            right.push_back(cur);
            parent = cur;
            cur = cur->right;
        }
        if (parent != NULL)
            cur = parent->left;
    }
}

vector<int> boundary(node *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    // find left boundary
    vector<node *> left;
    leftBoundary(root, left);

    // find leaf nodes
    vector<node *> bottom;
    leafNodes(root, bottom);

    // find right boundary
    vector<node *> right;
    rightBoundary(root, right);

    // filling answer vector
    map<node *, bool> m;
    for (auto x : left)
    {
        ans.push_back(x->data);
        m[x] = true;
    }
    for (auto x : bottom)
    {
        auto it = m.find(x);
        if (it == m.end())
        {
            ans.push_back(x->data);
            m[x] = true;
        }
    }
    reverse(right.begin(), right.end());
    for (auto x : right)
    {
        auto it = m.find(x);
        if (it == m.end())
        {
            ans.push_back(x->data);
            m[x] = true;
        }
    }
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    node *root = create_tree();
    print(root);
    cout << endl;
    vector<int> ans = boundary(root);
    for (auto x : ans)
        cout << x << " ";
    return 0;
}