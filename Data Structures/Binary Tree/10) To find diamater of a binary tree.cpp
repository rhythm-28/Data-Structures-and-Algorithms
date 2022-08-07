// To find diamater of a binary tree
// O(n^2)

#include<iostream>
#include<queue>
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

int find_height(node* root)
{
    if(root==NULL)
    return 0;

    int left_height=find_height(root->left);
    int right_height=find_height(root->right);

    return max(left_height,right_height) + 1;
}

int diameter(node* root)
{
    if(root==NULL)
    return 0;

    int left=find_height(root->left);
    int right=find_height(root->right);

    int a=left+right;
    int b=diameter(root->left);
    int c=diameter(root->right);

    return max(max(a,b),c);
}

int main()
{
    node* root=create_tree();
    print(root);
    cout<<diameter(root);
    return 0;
}