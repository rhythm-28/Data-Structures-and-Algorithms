// Find max width of binary tree
// TC: O(N)
// SC: O(H)

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

#define ll long long int
int maxWidth(node *root)
{
    queue<pair<node *, ll>> q;
    q.push({root, 0});
    q.push({NULL, -1});
    vector<ll> temp;
    ll ans = -1;
    while (!q.empty())
    {
        pair<node *, int> p = q.front();
        node *cur = p.first;
        ll i = p.second;
        q.pop();
        if (cur == NULL)
        {
            ans = max(ans, temp[temp.size() - 1] - temp[0] + 1);
            temp.clear();
            if (q.empty())
                break;
            else
                q.push({NULL, -1});
        }
        else
        {
            temp.push_back(i);
            if (cur->left)
                q.push({cur->left, (2 * i) + 1});
            if (cur->right)
                q.push({cur->right, (2 * i) + 2});
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
    cout << maxWidth(root);
    return 0;
}