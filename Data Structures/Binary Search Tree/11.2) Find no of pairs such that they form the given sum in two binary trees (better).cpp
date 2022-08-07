// Find no of pairs such that they form the given sum in two binary trees
// elements in each pair must be from different trees
// Time: O(n+m)
// n = no of nodes in tree1 
// m = no of nodes in tree2

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

    bool hasNext()
    {
        if (a.empty())
            return false;
        else
            return true;
    }

    int nextElement()
    {
        if (!hasNext())
            return -1;
        node *top = a.top();
        a.pop();
        if (left)
            pushNodes(top->right);
        else
            pushNodes(top->left);
        return top->data;
    }
};

int countPairs(node *root1, node *root2, int k)
{
    Iterator s;
    Iterator p;
    p.left = false;
    s.pushNodes(root1);
    p.pushNodes(root2);
    int x, y;
    x = s.nextElement();
    y = p.nextElement();
    int count = 0;
    while (x != -1 && y != -1)
    {
        if ((x + y) == k)
        {
            count++;
            x = s.nextElement();
            y = p.nextElement();
        }
        else if ((x + y) < k)
            x = s.nextElement();
        else
            y = p.nextElement();
    }
    return count;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    node *root1 = create_tree();
    print(root1);
    node *root2 = create_tree();
    print(root2);
    int key;
    cin >> key;
    cout << endl;
    cout << countPairs(root1, root2, key);
    return 0;
}