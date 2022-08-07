// Build a height balanced binary tree

#include<iostream>
#include<queue>
#include<utility>
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

node* create_tree(int a[],int s,int e)
{
    if(s>e)
    return NULL;
    
    int mid=(s+e)/2;
    node* root=new node(a[mid]);
    root->left=create_tree(a,s,mid-1);
    root->right=create_tree(a,mid+1,e);

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
    int a[100],n,i;
    cin>>n; 
    for(i=0;i<n;i++)
    cin>>a[i];
    node* root=create_tree(a,0,n-1);
    print(root);
    return 0;
}