// For each element in given array find the highest smallest element on its right
// TC: O(N*LOG(N))
// SC: O(LOG(N))

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node *insert(node *root, int key)
{
    if (!root)
        return new node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
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

int findPredecessor(node *root, int key)
{
    int ans = -1;
    while (root != NULL)
    {
        if (key <= root->data)
            root = root->left;
        else
        {
            ans = root->data;
            root = root->right;
        }
    }
    return ans;
}

vector<int> solve(vector<int> &a, int n)
{
    node *root = NULL;
    for (int i = n - 1; i >= 0; i--)
    {
        root = insert(root, a[i]);
        a[i] = findPredecessor(root, a[i]);
    }
    return a;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, temp, i;
    vector<int> a;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }
    a = solve(a, n);
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}