// Search for an element in a binary search tree
// TC: O(H)
// SC: O(1)

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

node *search(node *root, int key)
{
    while (root != NULL && root->data != key)
    {
        if (key <= root->data)
            root = root->left;
        else
            root = root->right;
    }

    if (!root)
        return NULL;

    else
        return root;
}

int main()
{
    node *root = create_tree();
    int key;
    cin >> key;
    ;
    node *a = search(root, key);
    if (a == NULL)
        cout << "not found";
    else
        cout << "key found:" << a->data;
    return 0;
}