// Serialize and deserialize
// (My approach: using preorder)
// TC: O(N)

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

void helper(node *root, string &s)
{
    if (!root)
    {
        s += "# ";
        return;
    }
    s += to_string(root->data);
    s += ' ';
    helper(root->left, s);
    helper(root->right, s);
}

// Encodes a tree to a single string.
string serialize(node *root)
{
    string s;
    helper(root, s);
    return s;
}

node *create(string s, int &i, int n)
{
    if (s[i] == '#')
    {
        i += 2;
        return NULL;
    }
    string temp;
    while (s[i] != ' ')
    {
        temp.push_back(s[i]);
        i++;
    }
    int x = stoi(temp);
    node *root = new node(x);
    i++;
    root->left = create(s, i, n);
    root->right = create(s, i, n);
    return root;
}

// Decodes your encoded data to tree.
node *deserialize(string s)
{
    int n = s.length(), i = 0;
    return create(s, i, n);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    node *root = create_tree();
    print(root);
    cout << endl;
    string s = serialize(root);
    node* root2 = deserialize(s);
    print(root2);
    return 0;
}