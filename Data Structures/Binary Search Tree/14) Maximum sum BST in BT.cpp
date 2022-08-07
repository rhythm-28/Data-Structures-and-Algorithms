// Maximum sum BST in BT
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

vector<int> isBST(node *root, int &ans)
{
    if (!root)
        return {0, INT_MAX, INT_MIN};

    vector<int> left = isBST(root->left, ans);
    vector<int> right = isBST(root->right, ans);

    if (left[0] != INT_MIN && right[0] != INT_MIN)
    {
        if (left[2] < root->data && root->data < right[1])
        {
            int sum = left[0] + right[0] + root->data;
            ans = max(ans, sum);

            int low = left[1];
            int high = right[2];

            if (!root->left)
                low = root->data;
            if (!root->right)
                high = root->data;

            return {sum, low, high};
        }
    }
    return {INT_MIN, -1, -1};
}

int maxSumBST(node *root)
{
    int ans = 0;
    isBST(root, ans);
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    node *root = create_tree();
    print(root);
    cout << endl;
    cout << maxSumBST(root);
    return 0;
}