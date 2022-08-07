// Find minimum time needed to burn a tree (recursive)
// TC: O(N)
// SC: O(N)

#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define pii pair<lli, lli>

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node *create_tree()
{
    int d;
    cin >> d;
    if (d == -1)
        return NULL;
    Node *root = new Node(d);
    root->left = create_tree();
    root->right = create_tree();
    return root;
}

void print(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    Node *a;
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

void findParents(Node *root, Node *par, map<Node *, Node *> &parent)
{
    if (!root)
        return;
    parent[root] = par;
    findParents(root->left, root, parent);
    findParents(root->right, root, parent);
}

int findTime(Node *root, map<Node *, Node *> &parent, map<Node *, bool> &visited)
{
    if (!root)
        return 0;
    if (visited[root] == 1)
        return 0;
    visited[root] = 1;
    int x = findTime(parent[root], parent, visited);
    int y = findTime(root->left, parent, visited);
    int z = findTime(root->right, parent, visited);
    return 1 + max(x, max(y, z));
}

void search(Node *root, int target, Node *&ans)
{
    if (!root)
        return;
    if (root->data == target)
    {
        ans = root;
        return;
    }
    search(root->left, target, ans);
    search(root->right, target, ans);
}

int minTime(Node *root, int target)
{
    Node *ans = NULL;
    search(root, target, ans);
    map<Node *, Node *> parent;
    findParents(root, NULL, parent);
    map<Node *, bool> visited;
    for (auto x : parent)
        visited[x.first] = false;
    return findTime(ans, parent, visited) - 1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Node *root = create_tree();
    print(root);
    cout << endl;
    int target;
    cin >> target;
    cout << minTime(root, target);
    return 0;
}