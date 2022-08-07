// Find median of elements
// TC: O(N)
// SC: O(H)

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

void inorder(node *root, int &count, int n, int &ans)
{
    if (!root)
        return;

    inorder(root->left, count, n, ans);
    count++;
    if (count == (n / 2) + 1)
        ans += root->data;
    if (count == (n / 2) && n % 2 == 0)
        ans += root->data;
    inorder(root->right, count, n, ans);
}

int size(node *root)
{
    if (!root)
        return 0;

    int left = size(root->left);
    int right = size(root->right);
    return left + right + 1;
}

float findMedian(node *root)
{
    int n = size(root), count = 0, ans = 0;
    inorder(root, count, n, ans);

    if (n % 2 == 0)
        return (float)ans / 2;
    else
        return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    node *root = create_tree();
    print(root);
    cout << endl;
    cout << findMedian(root);
    return 0;
}