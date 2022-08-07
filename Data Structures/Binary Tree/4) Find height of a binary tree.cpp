// Find height of a binary tree

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

int main()
{
    node* root=create_tree();
    cout<<"height is "<<find_height(root);
    return 0;
}