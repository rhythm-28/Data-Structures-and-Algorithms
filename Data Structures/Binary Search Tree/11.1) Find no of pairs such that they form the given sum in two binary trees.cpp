// Find no of pairs such that they form the given sum in two binary trees
// elements in each pair must be from different trees
// Time: O(n*height(m))
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

bool search(node *root, int key)
{
    if (!root)
        return false;

    if (root->data == key)
        return true;

    if (key < root->data)
        return search(root->left, key);

    else
        return search(root->right, key);
}

void traverse(node *root1, node *root2, int x, int &count)
{
    if (!root1)
        return;

    if (search(root2, x - root1->data))
        count++;

    traverse(root1->left, root2, x, count);
    traverse(root1->right, root2, x, count);
}

int countPairs(node *root1, node *root2, int x)
{
    int count = 0;
    traverse(root1, root2, x, count);
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