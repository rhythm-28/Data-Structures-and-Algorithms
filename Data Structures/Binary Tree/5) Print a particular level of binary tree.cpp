// Print a particular level of binary tree

#include<iostream>
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

void print(node* root,int k)
{
    if(root==NULL)
    return;

    if(k==1)
    {
        cout<<root->data;
        return;
    }

    print(root->left,k-1);
    print(root->right,k-1);
}

int main()
{
    node* root=create_tree();
    int k;
    cin>>k;
    print(root,k);
    return 0;
}