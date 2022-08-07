// Print maximum path sum from any node to any node

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

pii maxPathSum(node *root)
{
    if (!root)
        return make_pair(INT_MIN, INT_MIN);

    if (!root->left && !root->right)
        return make_pair(root->data, root->data);

    pii left = maxPathSum(root->left);
    pii right = maxPathSum(root->right);

    // for branch sum
    lli b1 = root->data;
    lli b2 = root->data + left.first;
    lli b3 = root->data + right.first;
    lli branchSum = max(max(b1, b2), b3);

    // for path sum
    lli p1 = root->data;
    lli p2 = root->data + left.first;
    lli p3 = root->data + right.first;
    lli p4 = root->data + left.first + right.first;
    lli p5 = left.second;
    lli p6 = right.second;
    lli pathSum = max(max(max(max(max(p1, p2), p3), p4), p5), p6);

    return make_pair(branchSum, pathSum);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    node *root = create_tree();
    print(root);
    cout << endl;
    cout << maxPathSum(root).second;
    return 0;
}