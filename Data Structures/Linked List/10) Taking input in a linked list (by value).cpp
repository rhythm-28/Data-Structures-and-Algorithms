// Taking input in a linked list (by value)

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

void print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

node* input()
{
    int d;
    node* head=NULL;
    cin>>d;
    while(d!=-1)
    {
        insert_at_tail(head,d);
        cin>>d;
    }
    return head;
}

int main()
{
    int d;
    node* head=input();
    print(head);
    return 0;
}