// Print right view of a binary tree

#include<iostream>
#include<queue>
#include<utility>
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

int max_level=0;
void print_right(node* root,int level)
{
    if(root==NULL)
    return;

    if(level>max_level)
    {
        cout<<root->data;
        max_level=level;
    }

    // recursive call for right
    print_right(root->right,level+1);

    // recursive call for right
    print_right(root->left,level+1);
}

int main()
{
    node* root=create_tree();
    cout<<endl;
    print(root);
    cout<<endl;
    print_right(root,1);
    return 0;
}