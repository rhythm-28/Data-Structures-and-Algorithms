// Level order printing of a binary tree (recursive)
// Time: O(n^2)

#include<iostream>
#include<algorithm>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;
    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

node* create_tree()
{
    int d;
    cin>>d;
    if(d==-1)
    return NULL;
    node* root = new node(d);
    root->left=create_tree();
    root->right=create_tree();
    return root;
}

int find_height(node* root)
{
    if(root==NULL)
    return 0;

    int left_height=find_height(root->left);
    int right_height=find_height(root->right);

    return max(left_height,right_height) + 1;
}

void print_Kth_level(node* root,int k)
{
    if(root==NULL)
    return;

    if(k==1)
    {
        cout<<root->data<<" ";
        return;
    }

    print_Kth_level(root->left,k-1);
    print_Kth_level(root->right,k-1);
}

void print(node* root)
{
    int n=find_height(root);
    for(int i=1;i<=n;i++)
    {
        print_Kth_level(root,i);
        cout<<endl;
    }
}

int main()
{
    node* root=create_tree();
    print(root);
    return 0;
}