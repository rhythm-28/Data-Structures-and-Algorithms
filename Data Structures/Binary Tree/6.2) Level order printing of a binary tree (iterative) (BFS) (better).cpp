// Level order printing of a binary tree (iterative) (better)
// Breadth First Search (BFS)
// Time: O(n)
// Space: O(n)
// where n=no of nodes

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

int main()
{
    node* root=create_tree();
    print(root);
    return 0;
}