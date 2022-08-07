// Find floor and ceil of given node

#include <iostream>
#include <queue>
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

void findFloorCeil(node *root, node *&floor, node *&ceil, int key)
{
    // for ceil
    node *ans = NULL;
    node *temp = root;
    while (root != NULL)
    {
        if (root->data == key)
        {
            ans = root;
            break;
        }
        if (root->data > key)
        {
            ans = root;
            root = root->left;
        }
        else
            root = root->right;
    }
    ceil = ans;

    // for floor
    ans = NULL;
    root = temp;
    while (root != NULL)
    {
        if (root->data == key)
        {
            ans = root;
            break;
        }
        if (root->data < key)
        {
            ans = root;
            root = root->right;
        }
        else
            root = root->left;
    }
    floor = ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    node *root = create_tree();
    int key;
    cin >> key;
    print(root);
    cout << endl;
    node *floor = NULL;
    node *ceil = NULL;
    findFloorCeil(root, floor, ceil, key);
    if (floor != NULL)
        cout << floor->data;
    else
        cout << -1;
    cout << " ";
    if (ceil != NULL)
        cout << ceil->data;
    else
        cout << -1;
    return 0;
}