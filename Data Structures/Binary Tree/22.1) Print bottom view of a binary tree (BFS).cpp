// Print bottom view of a binary tree

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

vector<int> bottomView(node *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    queue<pair<node *, int>> q;
    map<int, int> m;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<node *, int> p = q.front();
        q.pop();
        node *cur = p.first;
        int distance = p.second;
        m[distance] = cur->data;
        if (cur->left)
            q.push(make_pair(cur->left, distance - 1));
        if (cur->right)
            q.push(make_pair(cur->right, distance + 1));
    }

    for (auto p : m)
        ans.push_back(p.second);

    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    node *root = create_tree();
    print(root);
    cout << endl;
    vector<int> ans = bottomView(root);
    for (auto x : ans)
        cout << x << " ";
    return 0;
}