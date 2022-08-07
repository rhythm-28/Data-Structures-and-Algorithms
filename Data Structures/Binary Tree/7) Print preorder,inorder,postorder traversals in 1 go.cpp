// Print preorder,inorder,postorder traversals in 1 go
// TC: O(N)
// SC: O(H)

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

#define pni pair<node *, int>
void allInOne(node *root)
{
    vector<int> pre, in, post;
    stack<pni> s;
    s.push({root, 1});
    while (!s.empty())
    {
        pni top = s.top();
        node *cur = top.first;
        int state = top.second;
        if (state == 1)
        {
            pre.push_back(cur->data);
            s.top().second++;
            if (cur->left)
                s.push({cur->left, 1});
        }
        else if (state == 2)
        {
            in.push_back(cur->data);
            s.top().second++;
            if (cur->right)
                s.push({cur->right, 1});
        }
        else
        {
            post.push_back(cur->data);
            s.pop();
        }
    }
    cout << "Preorder-> ";
    for (auto x : pre)
        cout << x << " ";
    cout << endl;
    cout << "Inorder-> ";
    for (auto x : in)
        cout << x << " ";
    cout << endl;
    cout << "Postorder-> ";
    for (auto x : post)
        cout << x << " ";
    cout << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    node *root = create_tree();
    print(root);
    cout << endl;
    allInOne(root);
    return 0;
}