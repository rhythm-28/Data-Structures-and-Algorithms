// Diagonal traversal (recursive)
// TC: O(nlogn)
// SC: O(n)

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

void helper(node *root, int level, int distance, map<int, vector<int>> &m)
{
    if (!root)
        return;

    int x = level - distance;
    m[x].push_back(root->data);

    helper(root->left, level + 1, distance - 1, m);
    helper(root->right, level + 1, distance + 1, m);
}

vector<int> diagonal(node *root)
{
    map<int, vector<int>> m;
    helper(root, 0, 0, m);

    vector<int> v;
    for (auto x : m)
    {
        for (auto y : x.second)
            v.push_back(y);
    }
    return v;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    node *root = create_tree();
    print(root);
    cout << endl;
    vector<int> ans = diagonal(root);
    for (auto x : ans)
        cout << x << " ";
    return 0;
}