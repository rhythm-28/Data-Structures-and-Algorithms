// To find Lowest common ancestor of two given nodes

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

node* LCA(node* root,int a,int b)
{
    // if target nodes not found
    if(root==NULL)
    return NULL;

    // if any of target nodes are found
    if(root->data==a || root->data==b)
    return root;

    node* left=LCA(root->left,a,b);
    node* right=LCA(root->right,a,b);

    // if LCA is found
    if(left!=NULL && right!=NULL)
    return root;

    // if LCA is found and we are moving up to return address of LCA to main 
    // or if LCA is not found but we have found one of the target nodes, and we are moving up to return that address to find LCA 

    if(left==NULL)
    return right;

    else
    return left;
}

int main()
{
    node* root=create_tree();
    int a,b;
    cout<<"enter a & b"<<endl;
    cin>>a>>b;
    cout<<endl;
    print(root);
    cout<<endl;
    cout<<"LCA="<<LCA(root,a,b)->data;
    return 0;
}