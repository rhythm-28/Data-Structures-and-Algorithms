// Operator Overloading

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

void input(node* &head)
{
    int d;
    cin>>d;
    while(d!=-1)
    {
        insert_at_head(head,d);
        cin>>d;
    }
}

void operator>>(istream &cin,node* &head)
{
    input(head);
}


void operator<<(ostream &cout,node* head)
{
    print(head);
}

int main()
{
    int d;
    node* head=NULL;
    cin>>head;
    cout<<head;
    return 0;
}