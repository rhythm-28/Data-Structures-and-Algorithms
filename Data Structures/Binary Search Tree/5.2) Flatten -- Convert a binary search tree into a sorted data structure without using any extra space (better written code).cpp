// Flatten -- Convert a binary search tree into a sorted data structure without using any extra space

// We did this by converting binary search tree into linked list (by changing connection of nodes)

// Better written code

#include <iostream>
#include <queue>
#include <utility>
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

#define pnn pair<node *, node *>
pnn flatten(node *root)
{
    if (!root)
        return {NULL, NULL};

    if (!root->left && !root->right)
        return {root, root};

    pnn left = flatten(root->left);
    pnn right = flatten(root->right);

    node *b = left.second;
    node *a = root;
    node *c = right.first;

    if (b != NULL)
        b->left = a;

    a->left = c;

    node *head = left.first;
    node *tail = right.second;

    if (!head)
        head = root;

    if (!tail)
        tail = root;

    return {head, tail};
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    node *root = create_tree();
    cout << endl;
    print(root);
    cout << endl;
    node *head = flatten(root).first;
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->left;
    }
    return 0;
}