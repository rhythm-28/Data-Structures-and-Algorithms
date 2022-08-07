// Pre order printing of a binary tree
// using Morris-traversal
// TC: O(n)
// SC: O(1)

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
    vector<int> ans;
    node *cur = root;
    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            ans.push_back(cur->data);
            cur = cur->right;
        }
        else
        {
            node *rightMost = cur->left;
            while (rightMost->right != NULL)
            {
                if (rightMost->right == cur)
                    break;
                else
                    rightMost = rightMost->right;
            }
            if (rightMost->right != cur)
            {
                rightMost->right = cur;
                ans.push_back(cur->data);
                cur = cur->left;
            }
            else
            {
                rightMost->right = NULL;
                cur = cur->right;
            }
        }
    }
    for (auto x : ans)
        cout << x << " ";
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    node *root = create_tree();
    print(root);
    return 0;
}