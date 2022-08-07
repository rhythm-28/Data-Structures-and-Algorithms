// Create the binary search tree using its given pre-order printing
// TC: O(n^2)
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

node *create_tree(vector<int> &a, int low, int high)
{
    if (low > high)
        return NULL;

    node *root = new node(a[low]);
    int i;
    for (i = low + 1; i <= high; i++)
    {
        if (a[i] > a[low])
            break;
    }
    root->left = create_tree(a, low + 1, i - 1);
    root->right = create_tree(a, i, high);
    return root;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, i, temp;
    vector<int> a;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }
    node *root = create_tree(a, 0, n - 1);
    print(root);
    return 0;
}