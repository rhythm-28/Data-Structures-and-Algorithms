// Vertical order print of binary tree

#include<iostream>
#include<queue>
#include<map>
#include<vector>
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

void vertical_print(node* root,map<int,vector<int>> &m,int d)
{
    if(root!=NULL)
    {
        m[d].push_back(root->data);
        vertical_print(root->left,m,d-1);
        vertical_print(root->right,m,d+1);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    node* root=create_tree();

    map<int,vector<int>> m;
    vertical_print(root,m,0);
    
    for(auto p:m)
    {
        for(int i: p.second)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}