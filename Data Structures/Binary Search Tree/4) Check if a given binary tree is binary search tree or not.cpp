// Check if a given binary tree is binary search tree or not

#include<iostream>
#include<queue>
#include<climits>
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

bool check(node* root,int min_limit,int max_limit)
{
    if(root==NULL)
    return true;
    
    if(min_limit <= root->data && root->data < max_limit)
    {
        if(check(root->left,min_limit,root->data) && check(root->right,root->data,max_limit))
        return true;
    }
    return false;
}

int main()
{
    node* root=create_tree();
    cout<<endl;
    print(root);
    cout<<endl;
    bool ans=check(root,INT_MIN,INT_MAX);
    if(ans)
    cout<<"yes";
    else
    cout<<"no";
    return 0;
}