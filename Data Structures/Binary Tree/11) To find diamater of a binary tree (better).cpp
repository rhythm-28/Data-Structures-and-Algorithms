// To find diamater of a binary tree
// O(n)

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

pair<int,int> diameter(node* root)
{
    pair<int,int> p,pl,pr;
    // first=>height
    // second=> diameter
    if(root==NULL)
    {
        p.first=0;
        p.second=0;
        return p;
    }

    pl=diameter(root->left);
    pr=diameter(root->right);

    // calculate height
    p.first=max(pl.first,pr.first)+1;

    // calculate diameter
    p.second=max(pl.first+pr.first,max(pl.second,pr.second));

    return p;
}

int main()
{
    node* root=create_tree();
    print(root);
    cout<<diameter(root).second;
    return 0;
}