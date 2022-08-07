// Reverse a Linked List (recursion)
// O(n) Time
// O(1) Space 

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

void input(node* &head)
{
    int d;
    cin>>d;
    while(d!=-1)
    {
        insert_at_tail(head,d);
        cin>>d;
    }
}

void reverse(node* &head,node* &temp,node* &cur, node* &prev)
{
    if(temp==NULL)
    {
        head=cur;
        return;
    }

    cur=temp;
    temp=cur->next;
    cur->next=prev;
    prev=cur;
    reverse(head,temp,cur,prev);
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

int main()
{
    node* head=NULL;
    input(head);
    print(head);

    node* cur=head;
    node* temp=cur;
    node* prev=NULL;
    reverse(head,temp,cur,prev);

    print(head);
    return 0;
}