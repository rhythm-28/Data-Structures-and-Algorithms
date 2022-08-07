// Find if a pair forms the given sum in one binary tree
// Time: O(N)
// Space: O(N)

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

void helper(node *root, vector<int> &a)
{
    if (!root)
        return;
    helper(root->left, a);
    a.push_back(root->data);
    helper(root->right, a);
}

bool findTarget(node *root, int k)
{
    if (!root)
        return false;
    vector<int> a;
    helper(root, a);
    int i = 0, n = a.size(), j = n - 1;
    while (i < j)
    {
        if (a[i] + a[j] == k)
            return true;
        else if (a[i] + a[j] < k)
            i++;
        else
            j--;
    }
    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    node *root = create_tree();
    print(root);
    int key;
    cin >> key;
    cout << endl;
    if (findTarget(root, key))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}