// Find minimum time needed to burn a tree (iterative)
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
    queue<Node *> q;
    int time = 0, size;
    q.push(root);
    while (!q.empty())
    {
        size = q.size();
        while (size--)
        {
            Node *cur = q.front();
            q.pop();
            visited[cur] = 1;
            if (parent[cur] && !visited[parent[cur]])
                q.push(parent[cur]);
            if (cur->left && !visited[cur->left])
                q.push(cur->left);
            if (cur->right && !visited[cur->right])
                q.push(cur->right);
        }
        time++;
    }
    return time;
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