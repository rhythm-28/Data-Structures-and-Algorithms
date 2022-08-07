// Post order printing of a binary tree using 1 stack

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
    stack<node *> s;
    node *cur = root, *lastPopped;
    while (cur != NULL || !s.empty())
    {
        while (cur != NULL)
        {
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top()->right;
        if (cur == NULL)
        {
            lastPopped = s.top();
            s.pop();
            ans.push_back(lastPopped->data);
            while (!s.empty() && s.top()->right == lastPopped)
            {
                lastPopped = s.top();
                s.pop();
                ans.push_back(lastPopped->data);
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