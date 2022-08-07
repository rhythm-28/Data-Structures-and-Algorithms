// Delete a node from Binary search tree

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

node* search(node* root,int key)
{
    if(root==NULL)
    return NULL;

    if(key==root->data)
    return root;

    if(key<=root->data)
    return search(root->left,key);

    else
    return search(root->right,key);
}

node* delete_node(node* root,int key)
{
    if(root==NULL)
    return NULL;

    if(root->data==key)
    {
        // 0 children
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }
        
        // 1 children
        if(root->left!=NULL && root->right==NULL)
        {
            node* temp=root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL && root->right!=NULL)
        {
            node* temp=root->right;
            delete root;
            return temp;
        }

        // 2 children 
        else
        {
            node* replace=root->left;
            while(replace->right!=NULL)
            {
                replace=replace->right;
            }
            root->data=replace->data;
            root->left=delete_node(root->left,replace->data);
            return root;
        }
    }

    // not found and smaller than root, so look in left
    else if(key<root->data)
    {
        root->left=delete_node(root->left,key);
        return root;
    }

    // not found and greater than root,so look in right
    else
    {
        root->right=delete_node(root->right,key);
        return root;
    }
}

int main()
{
    node* root=create_tree();
    int key;
    cin>>key;
    cout<<endl;

    print(root);
    cout<<endl;

    root=delete_node(root,key);
    print(root);
    return 0;
}