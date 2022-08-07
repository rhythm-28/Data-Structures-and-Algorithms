// Taking input in a linked list (if no of elements is known)

#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node(int d)
    {
        data=d;
        next=NULL;
    }
};

void insert_at_head(node* &head, int d)
{
    if(head==NULL)
    head = new node(d);
    else
    {
        node* n= new node(d);
        (*n).next=head;
        head=n;
    }
}

void print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

void input(node* &head,int n)
{
    int d;
    for(int i=0;i<n;i++)
    {
        cin>>d;
        insert_at_head(head,d);
    }
}

int main()
{
    int n,d;
    node* head=NULL;
    cin>>n;
    input(head,n);
    print(head);
    return 0;
}