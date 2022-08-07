// Post order printing of a binary tree

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

void print(node* root)
{
    if(root==NULL)
    return;
    print(root->left);
    print(root->right);
    cout<<root->data<<" ";
}

int main()
{
    node* root=create_tree();
    print(root);
    return 0;
}