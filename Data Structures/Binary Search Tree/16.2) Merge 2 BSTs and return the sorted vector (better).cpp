// Merge 2 BSTs and return the sorted vector
// TC: O(M+N)
// SC: O(H1+H2)

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

void pushLeft(node *root, stack<node *> &a)
{
    while (root != NULL)
    {
        a.push(root);
        root = root->left;
    }
}

vector<int> merge(node *root1, node *root2)
{
    vector<int> a;
    stack<node *> s1, s2;
    node *x;
    node *y;
    pushLeft(root1, s1);
    pushLeft(root2, s2);

    while (!s1.empty() && !s2.empty())
    {
        x = s1.top();
        y = s2.top();
        if (x->data < y->data)
        {
            a.push_back(x->data);
            s1.pop();
            pushLeft(x->right, s1);
        }
        else
        {
            a.push_back(y->data);
            s2.pop();
            pushLeft(y->right, s2);
        }
    }
    while (!s1.empty())
    {
        x = s1.top();
        a.push_back(x->data);
        s1.pop();
        pushLeft(x->right, s1);
    }
    while (!s2.empty())
    {
        y = s2.top();
        a.push_back(y->data);
        s2.pop();
        pushLeft(y->right, s2);
    }
    return a;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    node *root1 = create_tree();
    print(root1);
    cout << endl;
    node *root2 = create_tree();
    print(root2);
    cout << endl;
    vector<int> a = merge(root1, root2);
    for (auto x : a)
        cout << x << " ";
    return 0;
}