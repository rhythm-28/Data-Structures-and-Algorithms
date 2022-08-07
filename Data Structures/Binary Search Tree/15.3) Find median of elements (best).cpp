// Find median of elements
// TC: O(N)
// SC: O(1)

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

int findSize(node *root)
{
    node *cur = root;
    int size = 0;
    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            size++;
            cur = cur->right;
        }
        else
        {
            node *prev = cur->left;
            while (prev->right != NULL)
            {
                if (prev->right == cur)
                    break;
                prev = prev->right;
            }
            if (prev->right == NULL)
            {
                prev->right = cur;
                cur = cur->left;
            }
            else
            {
                prev->right = NULL;
                size++;
                cur = cur->right;
            }
        }
    }
    return size;
}

int findSum(node *root, int n)
{
    node *cur = root;
    int count = 0, ans = 0, fMed = (n / 2), sMed = (n / 2) + 1;
    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            count++;
            if (count == sMed)
                ans += cur->data;
            else if (count == fMed && n % 2 == 0)
                ans += cur->data;

            cur = cur->right;
        }
        else
        {
            node *prev = cur->left;
            while (prev->right != NULL)
            {
                if (prev->right == cur)
                    break;
                prev = prev->right;
            }
            if (prev->right == NULL)
            {
                prev->right = cur;
                cur = cur->left;
            }
            else
            {
                prev->right = NULL;

                count++;
                if (count == sMed)
                    ans += cur->data;
                else if (count == fMed && n % 2 == 0)
                    ans += cur->data;

                cur = cur->right;
            }
        }
    }
    return ans;
}

float findMedian(node *root)
{
    int n = findSize(root);
    int sum = findSum(root, n);
    if (n % 2 == 0)
        return (float)sum / 2;
    else
        return (float)sum;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    node *root = create_tree();
    print(root);
    cout << endl;
    cout << findMedian(root);
    return 0;
}