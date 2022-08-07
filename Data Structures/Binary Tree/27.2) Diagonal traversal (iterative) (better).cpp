// Diagonal traversal (iterative)
// TC: O(n)
// SC: O(n)

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

vector<int> diagonal(node *root)
{
    vector<vector<int>> ans;

    // stores no of components of current diagonal
    int noOfComponents;

    // stores elements of current diagonal
    vector<int> temp;

    // stores head of component of current diagonal
    node *head;

    // to store head of components of next diagonal
    queue<node *> q;

    q.push(root);

    while (!q.empty())
    {
        noOfComponents = q.size();
        while (noOfComponents--)
        {
            // head of current diagonal
            head = q.front();
            q.pop();

            // loop until component finishes
            while (head != NULL)
            {
                // element of current diagonal
                temp.push_back(head->data);

                // pushing head of next component
                if (head->left)
                    q.push(head->left);

                // moving on to next element of current diagonal
                head = head->right;
            }
        }
        ans.push_back(temp);
        temp.clear();
    }

    vector<int> result;
    for (auto x : ans)
    {
        for (auto y : x)
            result.push_back(y);
    }
    return result;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    node *root = create_tree();
    print(root);
    cout << endl;
    vector<int> ans = diagonal(root);
    for (auto x : ans)
        cout << x << " ";
    return 0;
}