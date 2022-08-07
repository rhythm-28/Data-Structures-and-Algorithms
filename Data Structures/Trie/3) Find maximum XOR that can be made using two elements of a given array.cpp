// Find maximum XOR that can be made using two elements of a given array

#include<iostream>
#include<math.h>
using namespace std;

class node
{
    public:
    node* left;
    node*right;
    node()
    {
        left=NULL;
        right=NULL;
    }
};  

class Trie
{
    public:
    node* root;

    Trie()
    {
        root=new node();
    }

    void insert(int n)
    {
        node* temp=root;
        int i;
        for(i=31;i>=0;i--)
        {
            int bit=(n>>i)&1;

            if(bit==0)
            {
                // 0 is absent
                // so create and go there
                if(temp->left==NULL)
                temp->left=new node();

                // 0 is present, so go there
                temp=temp->left;
            }
            else
            {
                // 1 is absent
                // so create and go there
                if(temp->right==NULL)
                temp->right=new node();

                // 1 is present, so go there
                temp=temp->right;
            }
        }
    }
    int helper(int value)
    {
        node* temp=root;
        int sum=0;
        for(int i=31;i>=0;i--)
        {
            int bit=(value>>i)&1;

            if(bit==0)
            {
                // look for 1
                if(temp->right!=NULL)
                {
                    // i.e. 1 exists
                    temp=temp->right;
                    sum+=(pow(2,i));
                }
                
                // i.e. 1 does not exist
                // so, choosing 0
                else
                temp=temp->left;
            }

            else
            {
                // look for 0
                if(temp->left!=NULL)
                {
                    // i.e. 0 exists
                    temp=temp->left;
                    sum+=(pow(2,i));
                }    

                // choosing 1 as 0 does not exist here
                else
                temp=temp->right;
            } 
        }
        return sum;
    }

    int max_XOR(int a[],int n)
    {
        int max=0,cur;
        for(int i=0;i<n;i++)
        {
            insert(a[i]);
            cur=helper(a[i]);

            if(cur>max)
            max=cur;
        }
        return max;
    }
};

int main()
{
    int n,a[100];
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];

    Trie t;
    cout<<t.max_XOR(a,n);
    
    return 0;
}