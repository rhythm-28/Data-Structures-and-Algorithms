// Convert binary tree to doubly linked list in-place

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

// not required to be made
void printList(node *root)
{
    node *prev = NULL;
    while (root!=NULL)
    {
        cout << root->data << " ";
        prev = root;
        root = root->right;
    }
    cout << endl;
    while (prev!=NULL)
    {
        cout << prev->data << " ";
        prev = prev->left;
    }
    cout << endl;
}

pair<node *, node *> helper(node *root)
{
    if (!root)
        return {NULL, NULL};

    if (!root->left && !root->right)
        return make_pair(root, root);

    pair<node *, node *> left = helper(root->left);
    pair<node *, node *> right = helper(root->right);

    node *b = left.second;
    node *a = root;
    node *c = right.first;

    if (b != NULL)
        b->right = a;

    a->left = b;
    a->right = c;

    if (c != NULL)
        c->left = a;

    node *x = root;
    node *y = root;

    if (left.first != NULL)
        x = left.first;

    if (right.second != NULL)
        y = right.second;

    return make_pair(x, y);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    node *root = create_tree();
    print(root);
    cout << endl;
    root = helper(root).first;
    printList(root);
    return 0;
}