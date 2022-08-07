// Print all the nodes at a distance of k from the given target node in a binary tree

#include<iostream>
#include<queue>
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

void print_k_level(node* root,int k)
{
    if(root==NULL)
    return;

    if(k==0)
    {
        cout<<root->data<<" ";
        return;
    }

    print_k_level(root->left,k-1);
    print_k_level(root->right,k-1);
}

int print(node* root,int target,int k)
{
    if(root==NULL)
    return -1;

    if(root->data==target)
    {
        print_k_level(root,k);
        return 0;
    }

    int dl=print(root->left,target,k);

    if(dl==-1)
    {
        // target node is present in right subtree
        int dr=print(root->right,target,k);

        if(dr+1==k)
        cout<<root->data<<" ";

        else
        print_k_level(root->left,k-dr-2);
        
        return dr+1;
    }

    else
    {
        // target node is present in left sub-tree

        if(dl+1==k)
        cout<<root->data<<" ";

        else
        print_k_level(root->right,k-dl-2);

        return dl+1;
    }
}

int main()
{
    node* root=create_tree();
    int k,target;
    cin>>target;
    cin>>k;
    print(root,target,k);
    return 0;
}