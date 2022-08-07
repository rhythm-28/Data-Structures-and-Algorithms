// Build a binary search tree

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

node* insert_in_bst(node* root,int d)
{
    if(root==NULL)
    return new node(d);
    
    if(d<=root->data)
    root->left=insert_in_bst(root->left,d);

    else
    root->right=insert_in_bst(root->right,d);

    return root;
}

node* create_tree()
{
    int d;
    cin>>d;

    node* root=NULL;
    while(d!=-1)
    {
        root=insert_in_bst(root,d);
        cin>>d;
    }
    return root;
}

void print(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    node* a;
    while(!q.empty())
    {   
        a=q.front();
        
        if(a==NULL)
        {
            cout<<endl;
            q.pop();

            if(!q.empty())
            q.push(NULL);
        }
        else
        {
            // pop 
            q.pop();

            // print
            cout<<a->data<<" "; 

            // push children
            if(a->left!=NULL)
            q.push(a->left);

            if(a->right!=NULL)
            q.push(a->right);
        }
    }
}

int main()
{
    node* root=create_tree();
    print(root);
    return 0;
}