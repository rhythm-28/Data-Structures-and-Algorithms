// Find no of nodes in given complete binary tree
// TC: O((logn)^2)
// SC: O(logn)

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

int leftHeight(node *cur)
{
    int count = 0;
    while (cur != NULL)
    {
        count++;
        cur = cur->left;
    }
    return count;
}

int rightHeight(node *cur)
{
    int count = 0;
    while (cur != NULL)
    {
        count++;
        cur = cur->right;
    }
    return count;
}

int countNodes(node *root)
{
    if (!root)
        return 0;
    int lh = leftHeight(root);
    int rh = rightHeight(root);

    if (lh == rh)
        return pow(2, lh) - 1;
    else
        return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    node *root = create_tree();
    print(root);
    cout << endl;
    cout << countNodes(root);
    return 0;
}