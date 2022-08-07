// Create the binary tree using its given pre-order printing and in-order printing
// TC : O(nlogn)
// SC: O(n)

#include<bits/stdc++.h>
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

int i = 0;

node *create_tree(int a[], int b[], int s, int e,map<int,int> &m)
{
    // base case
    if (s > e)
        return NULL;

    // create a node to store the element of the pre-order array
    node *root = new node(a[i]);

    // search for that element in in-order array
    int j = m[a[i]];

    // move to the next element in pre-order array
    i++;

    // recursive call for the left part
    root->left = create_tree(a, b, s, j - 1,m);

    // recursive call for the right part
    root->right = create_tree(a, b, j + 1, e,m);

    // return address of current node
    return root;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a[1000], b[1000], n, i;
    cin >> n;
    // pre-order printing
    for (i = 0; i < n; i++)
        cin >> a[i];

    // in-order printing
    for (i = 0; i < n; i++)
        cin >> b[i];
    map<int, int> m;
    for (int i = 0; i < n; i++)
        m[b[i]] = i;
    node *root = create_tree(a, b, 0, n - 1,m);
    print(root);
    return 0;
}