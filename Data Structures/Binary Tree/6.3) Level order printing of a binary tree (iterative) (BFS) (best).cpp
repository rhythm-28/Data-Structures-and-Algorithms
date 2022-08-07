// Level order printing of a binary tree (iterative) (better)
// Breadth First Search (BFS)
// Time: O(n)
// Space: O(n)
// where n=no of nodes

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

vector<vector<int>> levelOrder(node *root)
{
    vector<vector<int>> a;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp;
        while (size--)
        {
            node *cur = q.front();
            q.pop();
            temp.push_back(cur->data);
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
        a.push_back(temp);
    }
    return a;
}

int main()
{
     freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    node *root = create_tree();
    vector<vector<int>> a = levelOrder(root);
    for (auto x : a)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}