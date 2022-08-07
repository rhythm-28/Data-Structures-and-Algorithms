// Add k nodes from end to front of linked list
// if(k>n) => append (k-n) nodes from end to front of linked list

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

void insert_at_tail(node* &head,int d)
{
    if(head==NULL)
    {
        head=new node(d);
        return;
    }
    node* tail=head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    tail->next=new node(d);
}

void input(node* &head, int n)
{
    int d,i;
    for(i=0;i<n;i++)
    {
        cin>>d;
        insert_at_tail(head,d);
    }
}

node* k_node(node* head,int k)
{
    node* fast=head;
    node* slow=head;
    while(k--)
    {
        fast=fast->next;
    }
    while(fast!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }
    return slow;
}

void print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

void k_append(node* &head,int k)
{
    node* tail=head;
    while(tail->next!=NULL)
    {
        tail=tail->next;
    }
    node* n=k_node(head,k+1);
    node* temp=n->next;
    n->next=NULL;
    tail->next=head;
    head=temp;
}

int main()
{
    node* head=NULL;
    int n;
    cin>>n;
    input(head,n);
    int k;
    cin>>k;

    if(n>k)
    k_append(head,k);

    else if(n<k)
    k_append(head,k-n);

    print(head);

    return 0;
}