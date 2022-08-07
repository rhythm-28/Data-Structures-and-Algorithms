// Print top view of a binary tree

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

void helper(node *root, map<int, pair<node *, int>> &m, int distance, int level)
{
    if (!root)
        return;

    auto it = m.find(distance);

    if (it == m.end())
        m[distance] = make_pair(root, level);
    else
    {
        if ((*it).second.second > level)
            m[distance] = make_pair(root, level);
    }

    helper(root->left, m, distance - 1, level + 1);
    helper(root->right, m, distance + 1, level + 1);
}

vector<int> topView(node *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    map<int, pair<node *, int>> m;
    helper(root, m, 0, 0);
    for (auto p : m)
        ans.push_back(p.second.first->data);
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    node *root = create_tree();
    print(root);
    cout << endl;
    vector<int> ans = topView(root);
    for (auto x : ans)
        cout << x << " ";
    return 0;
}