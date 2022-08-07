// To check if a binary tree is height balanced or not

#include<iostream>
#include<queue>
#include<utility>
#include<algorithm>
#include<cstdlib>
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

pair<int,bool> balanced(node* root)
{
    pair<int,bool> p;

    if(root==NULL)
    {
        p.first=0;
        p.second=true;
        return p;
    }

    pair<int,bool> l=balanced(root->left);
    pair<int,bool> r=balanced(root->right);
    p.first=max(l.first,r.first)+1;

    if(abs(l.first-r.first)<=1 && l.second==true && r.second==true)
    p.second=true;
    
    else
    p.second=false;

    return p;
}

int main()
{
    node* root=create_tree();
    print(root);
    if(balanced(root).second==true)
    cout<<"balanced";
    else
    cout<<"not balanced";
    return 0;
}