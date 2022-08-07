// Print right view of a binary tree
// iterative approach
// TC: O(n)

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

void bfs(node *root, vector<int> &ans)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    int lastElement = root->data;
    while (!q.empty())
    {
        node *top = q.front();
        q.pop();
        if (top == NULL)
        {
            ans.push_back(lastElement);
            if (q.empty())
                break;
            else
                q.push(NULL);
        }
        else
        {
            lastElement = top->data;
            if (top->left)
                q.push(top->left);
            if (top->right)
                q.push(top->right);
        }
    }
}

vector<int> rightSideView(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    bfs(root, ans);
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    node *root = create_tree();
    print(root);
    cout << endl;
    vector<int> ans = rightSideView(root);
    for (auto x : ans)
        cout << x << " ";
    return 0;
}