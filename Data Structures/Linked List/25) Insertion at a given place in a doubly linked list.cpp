// Insertion at a given place in a doubly linked list

#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node* prev;
    node(int d)
    {
        data=d;
        next=NULL;
        prev=NULL;
    }
};

void insert_at_tail(node* &head, int d)
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
    node* n=new node(d);
    tail->next=n;
    n->prev=tail;
}

void insert_at_place(node* &head, int d, int p)
{
    int jump=0;
    node* a=head;
    while(jump<p-1)
    {
        a=a->next;
        jump++;
    }
    node* b=a->next;
    
    node* n=new node(d);
    a->next=n;
    b->prev=n;
    n->prev=a;
    n->next=b;
}

void print(node* head)
{   
    while(head!=NULL)
    {
        cout<<head->data;
        head=head->next;
    }
    cout<<endl;
}

int main()
{
    node* head=NULL;
    insert_at_tail(head,5);
    insert_at_tail(head,3);
    insert_at_tail(head,2);
    insert_at_tail(head,1);
    insert_at_tail(head,9);
    
    print(head);

    insert_at_place(head,6,2);
    print(head);

    return 0;
}