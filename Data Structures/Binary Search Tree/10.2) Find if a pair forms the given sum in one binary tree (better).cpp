// Find if a pair forms the given sum in one binary tree
// Time: O(N)
// Space: O(H)

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

class Iterator
{
public:
    stack<node *> a;
    int left = true;

    void pushNodes(node *root)
    {
        while (root != NULL)
        {
            a.push(root);
            if (left)
                root = root->left;
            else
                root = root->right;
        }
    }

    int nextElement()
    {
        node *top = a.top();
        a.pop();
        if (left)
            pushNodes(top->right);
        else
            pushNodes(top->left);
        return top->data;
    }
};

bool findTarget(node *root, int k)
{
    Iterator s;
    Iterator p;
    p.left = false;
    s.pushNodes(root);
    p.pushNodes(root);
    int x, y, sum;
    x = s.nextElement();
    y = p.nextElement();
    while (x != y)
    {
        sum = x + y;
        if (sum == k)
            return true;
        else if (sum < k)
            x = s.nextElement();
        else
            y = p.nextElement();
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
    if (findTarget(root,key))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}